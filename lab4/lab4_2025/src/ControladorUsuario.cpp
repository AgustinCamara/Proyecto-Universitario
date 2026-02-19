#include "../include/ControladorUsuario.h"
#include "../include/Inmueble.h"
#include "../include/Casa.h"
#include "../include/Apartamento.h"
#include "../include/DTNotificacion.h"
#include "../include/ISuscrito.h"
#include "../include/Cliente.h"
#include "../include/Propietario.h"
#include "../include/Inmobiliaria.h"
#include "../include/DTUsuario.h"
#include <iostream>

ControladorUsuario* ControladorUsuario::instancia = NULL;

ControladorUsuario* ControladorUsuario::getInstancia() {
    if (instancia == NULL) {
        instancia = new ControladorUsuario();
    }
    return instancia;
}

bool ControladorUsuario::altaCliente(const std::string& nickname, const std::string& contrasena, const std::string& nombre, const std::string& email, const std::string& apellido, const std::string& documento) {
    if (usuarios.find(nickname) != usuarios.end()) {
        return false;
    }
    Cliente* c = new Cliente(nickname, contrasena, nombre, email, apellido, documento);
    usuarios[nickname] = c;
    clientes[nickname] = c;
    return true;
}

bool ControladorUsuario::altaPropietario(const std::string& nickname, const std::string& contrasena, const std::string& nombre, const std::string& email, const std::string& cuentaBancaria, const std::string& telefono) {
    if (usuarios.find(nickname) != usuarios.end()) {
        return false;
    }
    Propietario* p = new Propietario(nickname, contrasena, nombre, email, cuentaBancaria, telefono);
    usuarios[nickname] = p;
    propietarios[nickname] = p;
    return true;
}

bool ControladorUsuario::altaInmobiliaria(const std::string& nickname, const std::string& contrasena, const std::string& nombre, const std::string& email, const std::string& direccion, const std::string& url, const std::string& telefono) {
    if (usuarios.find(nickname) != usuarios.end()) {
        return false;
    }
    Inmobiliaria* i = new Inmobiliaria(nickname, contrasena, nombre, email, direccion, url, telefono);
    usuarios[nickname] = i;
    inmobiliarias[nickname] = i;
    return true;
}


std::set<DTUsuario> ControladorUsuario::listarPropietarios() {
    std::set<DTUsuario> propietariosSet;
    std::map<std::string, Propietario*>::const_iterator it;
    for (it = propietarios.begin(); it != propietarios.end(); ++it) {
        const Propietario* propietario = it->second;
        propietariosSet.insert(DTUsuario(propietario->getNickname(), propietario->getNombre()));
    }
    return propietariosSet;
}

std::set<DTUsuario> ControladorUsuario::listarInmobiliarias() {
    std::set<DTUsuario> res;
    std::map<std::string, Inmobiliaria*>::const_iterator it;
    for (it = inmobiliarias.begin(); it != inmobiliarias.end(); ++it) {
        Inmobiliaria* inmo = it->second;
        res.insert(DTUsuario(inmo->getNickname(), inmo->getNombre()));
    }
    return res;
}

void ControladorUsuario::suscribirseAInmobiliaria(const std::string& nicknameUsuario, const std::string& nicknameInmobiliaria) {
    std::map<std::string, Usuario*>::iterator itUsuario = usuarios.find(nicknameUsuario);
    std::map<std::string, Inmobiliaria*>::iterator itInmo = inmobiliarias.find(nicknameInmobiliaria);

    if (itUsuario != usuarios.end() && itInmo != inmobiliarias.end()) {
        ISuscrito* suscriptor = dynamic_cast<ISuscrito*>(itUsuario->second);
        if (suscriptor != NULL && !itInmo->second->esSuscriptor(suscriptor)) {
            itInmo->second->agregarSuscriptor(suscriptor);
            std::cout << "Suscripción realizada correctamente.\n";
        } else {
            std::cout << "Ya estás suscripto o el usuario no es válido.\n";
        }
    } else {
        std::cout << "Usuario o inmobiliaria inexistente.\n";
    }
}

void ControladorUsuario::eliminarSuscripcion(const std::string& nicknameUsuario, const std::string& nicknameInmobiliaria) {
    std::map<std::string, Usuario*>::iterator itUsuario = usuarios.find(nicknameUsuario);
    std::map<std::string, Inmobiliaria*>::iterator itInmo = inmobiliarias.find(nicknameInmobiliaria);

    if (itUsuario != usuarios.end() && itInmo != inmobiliarias.end()) {
        ISuscrito* suscriptor = dynamic_cast<ISuscrito*>(itUsuario->second);
        if (suscriptor != NULL && itInmo->second->esSuscriptor(suscriptor)) {
            itInmo->second->eliminarSuscriptor(suscriptor);
            std::cout << "Suscripción eliminada correctamente.\n";
        } else {
            std::cout << "No estás suscripto o el usuario no es válido.\n";
        }
    } else {
        std::cout << "Usuario o inmobiliaria inexistente.\n";
    }
}

void ControladorUsuario::mostrarNotificaciones(const std::string& nicknameUsuario) {
    if (clientes.count(nicknameUsuario)) {
        clientes[nicknameUsuario]->verNotificaciones();
    } else if (propietarios.count(nicknameUsuario)) {
        propietarios[nicknameUsuario]->verNotificaciones();
    } else {
        std::cout << "El usuario no tiene notificaciones.\n";
    }
}

std::set<std::string> ControladorUsuario::listarInmobiliariasNoSuscripto(const std::string& nicknameUsuario) {
    std::set<std::string> resultado;
    Usuario* usuario = usuarios[nicknameUsuario];
    ISuscrito* suscriptor = dynamic_cast<ISuscrito*>(usuario);

    if (suscriptor == NULL)
        return resultado;

    std::map<std::string, Inmobiliaria*>::iterator it;
    for (it = inmobiliarias.begin(); it != inmobiliarias.end(); ++it) {
        if (!it->second->esSuscriptor(suscriptor)) {
            resultado.insert(it->first);
        }
    }
    return resultado;
}
