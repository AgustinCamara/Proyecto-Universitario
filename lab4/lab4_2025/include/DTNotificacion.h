#ifndef DTNOTIFICACION_H
#define DTNOTIFICACION_H
#include <string>
#include "TipoPublicacion.h"
#include "TipoInmueble.h"

using namespace tipoInmueble;

class DTNotificacion {
private:
	std::string nickname;
	int codigo;
	std::string texto;
	TipoInmueble tipoInmueble;
	TipoPublicacion tipoPublicacion;
public:
	DTNotificacion(std::string nickname, int codigo, std::string texto, TipoInmueble tipoInmueble, TipoPublicacion tipoPublicacion);
	std::string getMensaje() const;
	std::string getNickname() const;
	bool operator<(const DTNotificacion& other) const;
};
#endif