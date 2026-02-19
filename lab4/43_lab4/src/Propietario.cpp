#include "../include/Propietario.h"
#include "../include/Inmobiliaria.h"
#include "../include/Inmueble.h"
#include "../include/Usuario.h"
#include <iostream>

Propietario::Propietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono)
    : Usuario(nickname, contrasena, nombre, email), cuentaBancaria(cuentaBancaria), telefono(telefono){
    }

void Propietario::agregarInmueble(Inmueble* inmueble) {
    inmuebles.push_back(inmueble);
}

void Propietario::eliminarInmueble(Inmueble* inmueble) {
    for (auto it = inmuebles.begin(); it != inmuebles.end(); ++it) {
        if (*it == inmueble) {
            inmuebles.erase(it);
            break;
        }
    }
}

Propietario::~Propietario(){
}

DTUsuario* Propietario::getDT() const {
    return new DTUsuario(getNickname(), getNombre());
}

std::set<DTInmuebleListado*> Propietario::getInmueblesNoAdmin(Inmobiliaria* inmobiliaria) {
    std::set<DTInmuebleListado*> resultado;
    for (Inmueble* i : inmuebles) {
        if (!i->esInmueble(inmobiliaria)) {
            int codigo = i->getCodigo();
            std::string direccion = i->getDireccion();
            std::string nick = Usuario::getNickname();
            DTInmuebleListado* dti = new DTInmuebleListado(codigo, direccion, nick);
            resultado.insert(dti);
            
        }
    }

    return resultado;
}

void Propietario::notificar(DTNotificacion* notificacion) {
    notificaciones.insert(notificacion);
}

std::set<DTNotificacion*> Propietario::getNotificaciones() const {
    return notificaciones;
}

std::string Propietario::getNickname() const {
    return Usuario::getNickname();
}
void Propietario::limpiarNotificaciones() {
    for (auto* it : notificaciones) {
        delete it; 
    }
    notificaciones.clear();
}
