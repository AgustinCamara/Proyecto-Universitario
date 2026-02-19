#include "../include/ControladorInmuebles.h"
#include "../include/Casa.h"
#include "ControladorUsuarios.h"
#include "../include/Apartamento.h"
#include "../include/TipoTecho.h"
#include "../include/Publicacion.h"
#include "../include/AdministraPropiedad.h"
#include <stdexcept>

ControladorInmuebles* ControladorInmuebles::instance = nullptr;

ControladorInmuebles::ControladorInmuebles() {}

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
    Casa* nuevaCasa = new Casa(direccion, numeroPuerta, superficie, anio, esPH, techo);
    inmuebles[nuevaCasa->getCodigo()] = nuevaCasa;
}

void ControladorInmuebles::altaApartamento(const std::string& direccion, int numeroPuerta, int superficie, int ambientes, int banios, bool ascensor, float gastosComunes) {
    Apartamento* nuevoApartamento = new Apartamento(direccion, numeroPuerta, superficie, ambientes, banios, ascensor, gastosComunes);
    inmuebles[nuevoApartamento->getCodigo()] = nuevoApartamento;
}

void ControladorInmuebles::eliminarInmueble(int codigo) {
    auto it = inmuebles.find(codigo);
    if (it != inmuebles.end()) {
        delete it->second;
        inmuebles.erase(it);
    }
}

bool ControladorInmuebles::altaPublicacion(const std::string& nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, const std::string& texto, float precio) {
Usuario* u = ControladorUsuarios::getInstance()->getUsuario(nicknameInmobiliaria);
Inmobiliaria* inmobiliaria = dynamic_cast<Inmobiliaria*>(u);
    if (!inmobiliaria) return false;

    return inmobiliaria->yaExiste(codigoInmueble, tipoPublicacion, texto, precio);
}


std::set<DTPublicacion> ControladorInmuebles::listarPublicacion(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmueble tipoInmueble) {
    std::set<DTPublicacion> resultado;
    for (auto& par : inmuebles) {
        Inmueble* inmueble = par.second;
        if ((tipoInmueble == TipoInmueble::Casa && dynamic_cast<Casa*>(inmueble)) ||
            (tipoInmueble == TipoInmueble::Apartamento && dynamic_cast<Apartamento*>(inmueble))) {
            
            std::vector<AdministraPropiedad*> administraciones = inmueble->getAdministraciones();
            for (AdministraPropiedad* ap : administraciones) {
                Publicacion* pubActiva = ap->obtenerActiva(tipoPublicacion);
               if (pubActiva && pubActiva->getPrecio() >= precioMinimo && pubActiva->getPrecio() <= precioMaximo) {
    resultado.insert(pubActiva->getData());
}

            }
        }
    }
    return resultado;
}

DTInmueble ControladorInmuebles::detalleInmueblePublicacion(int codigoPublicacion) {
    for (auto& par : inmuebles) {
        Inmueble* inmueble = par.second;
        std::vector<AdministraPropiedad*> administraciones = inmueble->getAdministraciones();
        for (AdministraPropiedad* ap : administraciones) {
            const std::map<int, Publicacion*>& pubs = ap->getPublicaciones();
            if (pubs.find(codigoPublicacion) != pubs.end()) {
                return inmueble->getDTInmueble();
            }
        }
    }
    throw std::runtime_error("No se encontró la publicación solicitada.");
}

DTInmueble ControladorInmuebles::detalleInmueble(int codigoInmueble) {
    if (inmuebles.count(codigoInmueble))
        return inmuebles[codigoInmueble]->getDTInmueble();
    throw std::runtime_error("Código de inmueble inválido.");
}

std::vector<DTInmuebleListado> ControladorInmuebles::listarInmuebles() {
    std::vector<DTInmuebleListado> resultado;
    for (auto& par : inmuebles) {
        Inmueble* inmueble = par.second;
        resultado.push_back(inmueble->getDTInmuebleListado());
    }
    return resultado;
}

Inmueble* ControladorInmuebles::obtenerInmueble(int codigo) {
    return inmuebles.count(codigo) ? inmuebles[codigo] : NULL;
}
 