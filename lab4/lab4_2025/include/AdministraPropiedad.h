#ifndef ADMINISTRAPROPIEDAD_H
#define ADMINISTRAPROPIEDAD_H

#include "DTFecha.h"
#include "DTPublicacion.h"
#include "Publicacion.h"
#include "TipoPublicacion.h"
#include <map>
#include <vector>
#include <string>

class Inmueble;
class Inmobiliaria;

class AdministraPropiedad {
private:
    DTFecha* fecha;
    std::map<int, Publicacion*> publicaciones;
    Inmueble* inmueble;
    Inmobiliaria* inmobiliaria;
    Publicacion* activaVenta;
    Publicacion* activaAlquiler;

public:
    AdministraPropiedad(DTFecha* fecha);
    ~AdministraPropiedad();

    DTFecha* getFecha();
    void setFecha(DTFecha* fecha);
    const std::map<int, Publicacion*>& getPublicaciones();
    Publicacion* obtenerActiva(TipoPublicacion tipo);
    bool yaExiste(TipoPublicacion tipoPublicacion, const std::string& texto, float precio);

    DTPublicacion getDatos();
    void buscar();
Publicacion crearPubli(TipoPublicacion tipo, const std::string& texto, float precio);

    Inmueble* getInmueble();
    Inmobiliaria* inmobiliariaAsociada();
};

#endif
