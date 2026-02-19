#include "../include/ControladorUsuarios.h"
#include "../include/Cliente.h"
#include "../include/Propietario.h"
#include "../include/Inmobiliaria.h"
#include "../include/DTInmuebleListado.h"
#include "../include/ControladorFechaActual.h"
#include "../include/ControladorInmuebles.h"
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>

ControladorUsuarios* ControladorUsuarios::instance = NULL;

ControladorUsuarios::ControladorUsuarios() {}

ControladorUsuarios* ControladorUsuarios::getInstance() {
    if (instance == NULL)
        instance = new ControladorUsuarios();
    return instance;
}

bool ControladorUsuarios::altaCliente(const std::string& nickname, const std::string& contrasena, const std::string& nombre, const std::string& email, const std::string& apellido, const std::string& documento) {
    if (usuarios.count(nickname)) return false;
    Cliente* nuevoCliente = new Cliente(nickname, contrasena, nombre, email, apellido, documento);
    usuarios[nickname] = nuevoCliente;
    return true;
}

bool ControladorUsuarios::altaPropietario(const std::string& nickname, const std::string& contrasena, const std::string& nombre, const std::string& email, const std::string& cuentaBancaria, const std::string& telefono) {
    if (usuarios.count(nickname)) return false;
    Propietario* nuevoPropietario = new Propietario(nickname, contrasena, nombre, email, cuentaBancaria, telefono);
    usuarios[nickname] = nuevoPropietario;
    propietarioRecordado = nuevoPropietario;
    return true;
}

bool ControladorUsuarios::altaInmobiliaria(const std::string& nickname, const std::string& contrasena, const std::string& nombre, const std::string& email, const std::string& direccion, const std::string& url, const std::string& telefono) {
    if (usuarios.count(nickname)) return false;
    Inmobiliaria* nuevaInmobiliaria = new Inmobiliaria(nickname, contrasena, nombre, email, direccion, url, telefono);
    usuarios[nickname] = nuevaInmobiliaria;
    inmobiliariaRecordada = nuevaInmobiliaria;
    return true;
}

std::set<DTUsuario*> ControladorUsuarios::listarInmobiliarias() {
    std::set<DTUsuario*> resultado;
    for (auto& par : usuarios) {
        Usuario* usuario = par.second;
        Inmobiliaria* inm = dynamic_cast<Inmobiliaria*>(usuario);
        if (inm)
            resultado.insert(inm->getDT());
    }
    return resultado;
}

std::list<DTInmuebleAdministrado*> ControladorUsuarios::listarInmueblesAdministrados(const std::string& nicknameInmobiliaria) {
    Inmobiliaria* inm = dynamic_cast<Inmobiliaria*>(usuarios[nicknameInmobiliaria]);
    return inm ? inm->listarInmuebles() : std::list<DTInmuebleAdministrado*>();
}

std::set<DTUsuario*> ControladorUsuarios::listarPropietarios() {
    std::set<DTUsuario*> resultado;
    for (auto& par : usuarios) {
        Usuario* usuario = par.second;
        Propietario* prop = dynamic_cast<Propietario*>(usuario);
        if (prop)
            resultado.insert(prop->getDT());
    }
    return resultado;
}

void ControladorUsuarios::representarPropietario(const std::string& nicknamePropietario) {
    Propietario* propietario = dynamic_cast<Propietario*>(usuarios[nicknamePropietario]);
    if (inmobiliariaRecordada && propietario) {
        inmobiliariaRecordada->agregarPropietario(propietario);
    }
}

Propietario* ControladorUsuarios::getPropietarioRecordado() {
    return propietarioRecordado;
}

Inmobiliaria* ControladorUsuarios::getInmobiliariaRecordada() {
    return inmobiliariaRecordada;
}

void ControladorUsuarios::finalizarAltaUsuario() {
    inmobiliariaRecordada = NULL;
    propietarioRecordado = NULL;
}

ControladorUsuarios::~ControladorUsuarios() {
    for (auto& par : usuarios) {
        delete par.second; 
    }
    usuarios.clear();
}

Usuario* ControladorUsuarios::getUsuario(const std::string& nickname) {
    if (usuarios.count(nickname)) {
        return usuarios[nickname];
    }
    return NULL;
}


std::set<DTInmuebleListado*> ControladorUsuarios::listarInmueblesNoAdministradosInmobiliaria(const std::string& nicknameInmobiliaria) {
    Inmobiliaria* ci = dynamic_cast<Inmobiliaria*>(usuarios[nicknameInmobiliaria]);
    return ci ? ci->getInmueblesNoAdminPropietario() : std::set<DTInmuebleListado*>();
}

void ControladorUsuarios::altaAdministraPropiedad(std::string nicknameInmobiliaria, int codigoInmueble) {
    Inmobiliaria* ci = dynamic_cast<Inmobiliaria*>(usuarios[nicknameInmobiliaria]);
    Inmueble* cin = ControladorInmuebles::getInstance()->obtenerInmueble(codigoInmueble);
    DTFecha* fechaActual = ControladorFechaActual::getInstance()->getFechaActual();
    if (ci && cin && fechaActual) {
        ci->altaAdminitracionPropiedad(cin, fechaActual);
    }
    delete fechaActual; 
}

std::set<DTUsuario*> ControladorUsuarios::listarInmobiliariasNoSuscripto(const std::string& nicknameCliente) {
    std::set<DTUsuario*> resultado;

    if (Cliente* cliente = dynamic_cast<Cliente*>(usuarios[nicknameCliente])){
        for (auto& par : usuarios) {
            Inmobiliaria* inm = dynamic_cast<Inmobiliaria*>(par.second);
            if (inm && !inm->esSuscriptor(cliente->getNickname())) {
                resultado.insert(inm->getDT());
            }
        }
    } else if (Propietario* propietario = dynamic_cast<Propietario*>(usuarios[nicknameCliente])) {
        for (auto& par : usuarios) {
            Inmobiliaria* inm = dynamic_cast<Inmobiliaria*>(par.second);
            if (inm && !inm->esSuscriptor(propietario->getNickname())) {
                resultado.insert(inm->getDT());
            }
        }   
    } 
    return resultado;
}
bool ControladorUsuarios::suscribirAInmobiliaria(const std::string& nicknameCliente, const std::string& nicknameInmobiliaria) {
    Inmobiliaria* inmobiliaria = dynamic_cast<Inmobiliaria*>(usuarios[nicknameInmobiliaria]);
    Usuario* usuario = usuarios[nicknameCliente];

    if (inmobiliaria && usuario) {
        Cliente* cliente = dynamic_cast<Cliente*>(usuario);
        Propietario* propietario = dynamic_cast<Propietario*>(usuario);

        if (cliente) {
            inmobiliaria->agregarSuscriptor(cliente);
            return true;
        } else if (propietario) {
            inmobiliaria->agregarSuscriptor(propietario);
            return true;
        }
    }

    return false;
}


void ControladorUsuarios::finalizarSuscripcion() {
    nicknameUsuarioRecordado = "";
}

std::set<DTNotificacion*> ControladorUsuarios::listarNotificaciones(std::string nicknameCliente) {
    if (Cliente* cliente = dynamic_cast<Cliente*>(usuarios[nicknameCliente])){
        return cliente->getNotificaciones();
    }else if (Propietario* propietario = dynamic_cast<Propietario*>(usuarios[nicknameCliente])) {
        return propietario->getNotificaciones();
    }
    nicknameUsuarioRecordado = nicknameCliente;
    return std::set<DTNotificacion*>();
}
void ControladorUsuarios::eliminarNotificaciones(std::string nicknameUsuario) {
    Usuario* usuario = usuarios[nicknameUsuario];

    if (Cliente* cliente = dynamic_cast<Cliente*>(usuario)) {
        cliente->limpiarNotificaciones();
    }
    else if (Propietario* propietario = dynamic_cast<Propietario*>(usuario)) {
        propietario->limpiarNotificaciones();
    }
}



void ControladorUsuarios::finalizarConsulta() {
    nicknameUsuarioRecordado = "";
}

std::set<DTUsuario*> ControladorUsuarios::listarInmobiliariasSuscripto(const std::string& nicknameCliente) {
    Cliente* cliente = dynamic_cast<Cliente*>(usuarios[nicknameCliente]);
    std::set<DTUsuario*> resultado;
    if (cliente) {
        for (auto& par : usuarios) {
            Inmobiliaria* inm = dynamic_cast<Inmobiliaria*>(par.second);
            if (inm && inm->esSuscriptor(cliente->getNickname())) {
                resultado.insert(inm->getDT());
            }
        }
    }
    nicknameUsuarioRecordado = nicknameCliente; 
    return resultado;
}


bool ControladorUsuarios::desuscribirDeInmobiliaria(const std::string& nicknameCliente, const std::string& nicknameInmobiliaria) {
    Inmobiliaria* inmobiliaria = dynamic_cast<Inmobiliaria*>(usuarios[nicknameInmobiliaria]);
    Cliente* cliente = dynamic_cast<Cliente*>(usuarios[nicknameCliente]);
    if (inmobiliaria && cliente) {
        inmobiliaria->eliminarSuscriptor(cliente);
        return true;
    }
    return false;
}

