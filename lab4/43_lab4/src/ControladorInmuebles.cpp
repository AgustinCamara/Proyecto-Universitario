#include "../include/ControladorInmuebles.h"
#include "../include/Casa.h"
#include "../include/ControladorUsuarios.h"
#include "../include/Apartamento.h"
#include "../include/TipoTecho.h"
#include "../include/Publicacion.h"
#include "../include/AdministraPropiedad.h"
#include "../include/Factory.h"
#include <stdexcept>
#include <algorithm>
#include <iostream>

ControladorInmuebles* ControladorInmuebles::instance = nullptr;

ControladorInmuebles::ControladorInmuebles() {
    codigoActual = 1;
}

ControladorInmuebles* ControladorInmuebles::getInstance() {
    if (instance == NULL)
        instance = new ControladorInmuebles();
    return instance;
}

ControladorInmuebles::~ControladorInmuebles() {
    for (auto& par : inmuebles)
        delete par.second;
    inmuebles.clear();
}

void ControladorInmuebles::altaCasa(const std::string& direccion, int numeroPuerta, int superficie, int anio, bool esPH, TipoTecho techo) {
    Casa* nuevaCasa = new Casa(esPH, techo);
    nuevaCasa->setCodigo(codigoActual);
    nuevaCasa->setDireccion(direccion);
    nuevaCasa->setNumeroPuerta(numeroPuerta);
    nuevaCasa->setSuperficie(superficie);
    nuevaCasa->setAnoConstruccion(anio);

    inmuebles[codigoActual] = nuevaCasa;

    Propietario* propietario = Factory::getInstance()->getControladorUsuarios()->getPropietarioRecordado();
    if (propietario) {
        propietario->agregarInmueble(nuevaCasa);
        nuevaCasa->setPropietario(propietario);
    }

    codigoActual++;
}

void ControladorInmuebles::altaApartamento(const std::string& direccion, int numeroPuerta, int superficie, int anio, int piso, bool tieneAscensor, float gastosComunes) {
    Apartamento* nuevoApartamento = new Apartamento(piso, tieneAscensor, gastosComunes);
    nuevoApartamento->setCodigo(codigoActual);
    nuevoApartamento->setDireccion(direccion);
    nuevoApartamento->setNumeroPuerta(numeroPuerta);
    nuevoApartamento->setSuperficie(superficie);
    nuevoApartamento->setAnoConstruccion(anio);

    inmuebles[codigoActual] = nuevoApartamento;

    Propietario* propietario = Factory::getInstance()->getControladorUsuarios()->getPropietarioRecordado();
    if (propietario) {
        propietario->agregarInmueble(nuevoApartamento);
        nuevoApartamento->setPropietario(propietario);
    }

    codigoActual++;
}
void ControladorInmuebles::eliminarInmueble(int codigo) {
    auto it = inmuebles.find(codigo);
    if (it != inmuebles.end()) {
        delete it->second;
        inmuebles.erase(it);
    }
}

void ControladorInmuebles::setCodigoActualPublicacion(int nuevoCodigo) {
    codigoActualPublicacion = nuevoCodigo;
}

bool ControladorInmuebles::altaPublicacion(const std::string& nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, const std::string& texto, float precio) {
Usuario* u = ControladorUsuarios::getInstance()->getUsuario(nicknameInmobiliaria);
Inmobiliaria* inmobiliaria = dynamic_cast<Inmobiliaria*>(u);
    if (!inmobiliaria) return false; // no existe la inmobiliaria
    return inmobiliaria->yaExiste(codigoInmueble, tipoPublicacion, texto, precio);
}


std::set<DTPublicacion*> ControladorInmuebles::listarPublicacion(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmueble tipoInmueble) {
    std::vector<DTPublicacion*> temp;

    for (auto& par : inmuebles) {
        Inmueble* inmueble = par.second;

        if ((tipoInmueble == TipoInmueble::Todos) ||
            (tipoInmueble == TipoInmueble::Casa && dynamic_cast<Casa*>(inmueble)) ||
            (tipoInmueble == TipoInmueble::Apartamento && dynamic_cast<Apartamento*>(inmueble))) {

            std::list<AdministraPropiedad*> administraciones = inmueble->getAdministraciones();
            for (AdministraPropiedad* ap : administraciones) {
                Publicacion* pubActiva = ap->obtenerActiva(tipoPublicacion);
                if (pubActiva && pubActiva->getPrecio() >= precioMinimo && pubActiva->getPrecio() <= precioMaximo) {
                    temp.push_back(pubActiva->getData());
                }
            }
        }
    }

    std::sort(temp.begin(), temp.end(), [](DTPublicacion* a, DTPublicacion* b) {
        return a->getCodigo() < b->getCodigo();
    });

    std::set<DTPublicacion*> resultado(temp.begin(), temp.end());
    return resultado;
}
DTInmueble* ControladorInmuebles::detalleInmueblePublicacion(int codigoPublicacion) {
    Inmueble* res = nullptr;  
    for (auto& par : inmuebles) {
        Inmueble* inmueble = par.second;
        std::list<AdministraPropiedad*> administraciones = inmueble->getAdministraciones();
        for (AdministraPropiedad* ap : administraciones) {
            const std::map<int, Publicacion*>& pubs = ap->getPublicaciones();
            auto pubIt = pubs.find(codigoPublicacion);
            if (pubIt != pubs.end()) {
                res = inmueble;
                break;  
            }
        }
        if (res != nullptr)
            break;  
    }

    if (!res)
        throw std::runtime_error("No se encontró la publicación solicitada.");

    return res->getDTInmueble();
}



DTInmueble* ControladorInmuebles::detalleInmueble(int codigoInmueble) {
    if (inmuebles.count(codigoInmueble))
        return inmuebles[codigoInmueble]->getDTInmueble();
    throw std::runtime_error("Código de inmueble inválido.");
}

std::list<DTInmuebleListado*> ControladorInmuebles::listarInmuebles() {
    std::list<DTInmuebleListado*> resultado;
    for (auto& par : inmuebles) {
        Inmueble* inmueble = par.second;
        resultado.push_back(inmueble->getDTInmuebleListado());
    }
    return resultado;
}

Inmueble* ControladorInmuebles::obtenerInmueble(int codigo) {
    return inmuebles.count(codigo) ? inmuebles[codigo] : NULL;
}


 
