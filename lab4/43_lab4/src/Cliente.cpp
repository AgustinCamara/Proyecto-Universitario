#include "../include/Cliente.h"


Cliente::Cliente(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string apellido, std::string documento)
    : Usuario(nickname, contrasena, nombre, email), apellido(apellido), documento(documento) {
}

Cliente::~Cliente(){}

void Cliente::notificar(DTNotificacion* notificacion) {
    notificaciones.insert(notificacion);
}

std::set<DTNotificacion*> Cliente::getNotificaciones() const {
    return notificaciones;
}

void Cliente::limpiarNotificaciones() {
    notificaciones.clear();  
}

std::string Cliente::getNickname() const {
    return Usuario::getNickname();
}
DTUsuario* Cliente::getDT() const {
    return new DTUsuario(getNickname(), getNombre());
}

