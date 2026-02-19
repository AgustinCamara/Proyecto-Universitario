#include "../include/DTNotificacion.h"

DTNotificacion::DTNotificacion(std::string nickname, int codigo, std::string texto, TipoInmueble tipoInmueble, TipoPublicacion tipoPublicacion)
	: nickname(nickname), codigo(codigo), texto(texto), tipoInmueble(tipoInmueble), tipoPublicacion(tipoPublicacion) {}

std::string DTNotificacion::getMensaje() const {
	return texto;
}

std::string DTNotificacion::getNickname() const {
	return nickname;
}

bool DTNotificacion::operator<(const DTNotificacion& other) const {
        return texto < other.getMensaje(); 
    }