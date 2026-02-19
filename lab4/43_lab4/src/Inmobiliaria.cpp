#include "../include/Inmobiliaria.h"
#include "../include/AdministraPropiedad.h"
#include "../include/Propietario.h"
#include "../include/DTUsuario.h"
#include "../include/DTInmuebleAdministrado.h"
#include "../include/DTInmuebleListado.h"
#include "../include/DTFecha.h"
#include "../include/Publicacion.h"
#include "../include/Factory.h"
#include "../include/ISuscrito.h"
#include "../include/DTNotificacion.h"
#include "../include/TipoPublicacion.h"
#include "../include/TipoInmueble.h"
#include "../include/Apartamento.h"
#include "../include/Casa.h"
#include <algorithm>
#include <iostream>

Inmobiliaria::Inmobiliaria(std::string nickname, std::string contrasena, std::string nombre,
                           std::string email, std::string direccion, std::string url, std::string telefono)
    : Usuario(nickname, contrasena, nombre, email),
      direccion(direccion), url(url), telefono(telefono) {}

Inmobiliaria::~Inmobiliaria() {
    for (auto* ap : AdministracionesPropiedad)
        delete ap;
    AdministracionesPropiedad.clear();
    propietariosRepresentados.clear();
    suscriptores.clear();
}

std::string Inmobiliaria::getDireccion() { return direccion; }
std::string Inmobiliaria::getUrl() { return url; }
std::string Inmobiliaria::getTelefono() { return telefono; }

void Inmobiliaria::setDireccion(std::string& dir) { direccion = dir; }
void Inmobiliaria::setUrl(std::string& u) { url = u; }
void Inmobiliaria::setTelefono(std::string& tel) { telefono = tel; }

DTUsuario* Inmobiliaria::getDT() const {
    return new DTUsuario(getNickname(), getNombre());
}

void Inmobiliaria::altaAdminitracionPropiedad(Inmueble* inmueble, DTFecha* fecha) {
    auto* ap = new AdministraPropiedad(fecha->copiar());
    AdministracionesPropiedad.push_back(ap);
    inmueblesAdministrados.insert(inmueble);
    inmueble->asociarAdministracionPropiedad(ap);
    ap->setInmobiliaria(this);
    ap->setInmueble(inmueble);
}

std::list<DTInmuebleAdministrado*> Inmobiliaria::listarInmuebles() {
    std::list<DTInmuebleAdministrado*> resultado;
    for (auto* ap : AdministracionesPropiedad) {
        if (ap->getInmueble() != nullptr) {
            DTInmuebleAdministrado* dtInmueble = ap->getDTInmuebleAdmin();
            resultado.push_back(dtInmueble);
        } else {
            std::cout << "No hay inmueble asociado a esta administracion." << std::endl;
        }
    }
    return resultado;
}

std::set<DTInmuebleListado*> Inmobiliaria::getInmueblesNoAdminPropietario() {
    std::set<DTInmuebleListado*> resultado;
    for (auto* p : propietariosRepresentados) {
        std::set<DTInmuebleListado*> lista = p->getInmueblesNoAdmin(this);
        while (!lista.empty()) {
            DTInmuebleListado* dtInmueble = *lista.begin();
            lista.erase(lista.begin());
            resultado.insert(dtInmueble);
        }
    }
    return resultado;
}

bool Inmobiliaria::yaExiste(int codigoInmueble, TipoPublicacion tipo, const std::string& texto, float precio) {
    for (auto* ap : AdministracionesPropiedad) {
        Inmueble* in = ap->getInmueble();
        if (in != nullptr && in->getCodigo() == codigoInmueble) {
            if (ap->yaExiste(tipo, texto, precio))
                return false; 
        }
        bool creada = ap->crearPubli(tipo, texto, precio); 
        if (creada) {   
            TipoInmueble tipoInm;
            if (dynamic_cast<Casa*>(in)) {
                tipoInm = TipoInmueble::Casa;
            } else if (dynamic_cast<Apartamento*>(in)) {
                tipoInm = TipoInmueble::Apartamento;
            }
            DTNotificacion* notificacion = new DTNotificacion(getNickname(), codigoInmueble, texto, tipoInm, tipo);
            notificarSuscriptores(notificacion);
            return true; 
        }
    }
    return false; 
}

void Inmobiliaria::agregarPublicacion() {
}

void Inmobiliaria::agregarPropietario(Propietario* propietario) {
    if (propietariosRepresentados.find(propietario) != propietariosRepresentados.end()) {
        std::cout << "El propietario ya está representado por esta inmobiliaria." << std::endl;
        return;
    }else{
        propietariosRepresentados.insert(propietario);
    }
}

void Inmobiliaria::agregarSuscriptor(ISuscrito* observer) {
    suscriptores.insert(observer);
}

void Inmobiliaria::eliminarSuscriptor(ISuscrito* observer) {
    suscriptores.erase(observer);
}

bool Inmobiliaria::esSuscriptor(const std::string& nicknameCliente) const {
    for (auto* obs : suscriptores) {
        if (obs->getNickname() == nicknameCliente)
            return true;
    }
    return false;
}

void Inmobiliaria::notificarSuscriptores(DTNotificacion* notificacion) {
    for (auto* s : suscriptores) {
        DTNotificacion* copiaNotificacion = new DTNotificacion(*notificacion); 
        s->notificar(copiaNotificacion);
    }
    delete notificacion;  
}