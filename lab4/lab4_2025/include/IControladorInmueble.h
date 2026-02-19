#ifndef ICONTROLADORINMUEBLE_H
#define ICONTROLADORINMUEBLE_H

#include <set>
#include <string>
#include "DTPublicacion.h"
#include "DTInmueble.h"
#include "TipoInmueble.h"
#include "TipoPublicacion.h"

class IControladorInmueble {
public:
virtual ~IControladorInmueble() {}
    virtual std::set<DTPublicacion> listarPublicacion(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmueble tipoInmueble) = 0;
    virtual void eliminarInmueble(int codigoInmueble) = 0;
    virtual bool altaPublicacion(const std::string& nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, const std::string& texto, float precio) = 0;
    virtual bool altaCasa(const std::string& nicknamePropietario, const std::string& direccion, int numeroPuerta, int superficie, int anioConstruccion, bool esPH, TipoTecho techo) = 0;
    virtual bool altaApartamento(const std::string& nicknamePropietario, const std::string& direccion, int numeroPuerta, int superficie, int anioConstruccion, int piso, bool tieneAscensor, float gastosComunes) = 0;
    virtual DTInmueble detalleInmueblePublicacion(int codigoPublicacion) = 0;
    virtual DTInmueble detalleInmueble(int codigoInmueble) = 0;
};

#endif
