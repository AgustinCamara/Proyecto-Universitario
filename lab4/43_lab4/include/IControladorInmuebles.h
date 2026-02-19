#ifndef ICONTROLADORINMUEBLES_H
#define ICONTROLADORINMUEBLES_H
#include <set>
#include "../include/DTPublicacion.h"
#include "../include/TipoPublicacion.h"
#include "../include/TipoInmueble.h"
#include "../include/TipoTecho.h"
#include <vector>
#include "DTInmuebleListado.h"
#include "../include/DTInmueble.h"
#include "../include/Inmueble.h" 
#include <list>

using tipoInmueble::TipoInmueble;


class IControladorInmuebles{
 public: 
    virtual void eliminarInmueble(int codigoInmueble)=0;
    virtual std::set<DTPublicacion*> listarPublicacion(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmueble tipoInmueble)=0;
    virtual DTInmueble* detalleInmueblePublicacion(int codigoPublicacion)=0;
    virtual void altaCasa(const std::string& direccion, int numeroPuerta, int superficie, int anoConstruccion, bool esPH, TipoTecho techo)=0;   
    virtual void altaApartamento(const std::string& direccion, int numeroPuerta, int superficie, int anoConstruccion, int piso, bool tieneAscensor, float gastosComunes)=0;
    virtual bool altaPublicacion(const std::string& nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, const std::string& texto, float precio) = 0;
    virtual DTInmueble* detalleInmueble(int codigoInmueble)=0;   
    virtual std::list<DTInmuebleListado*> listarInmuebles()=0;
    
    virtual void setCodigoActualPublicacion(int nuevoCodigo) = 0;

    virtual Inmueble* obtenerInmueble(int codigoInmueble)=0;
    virtual int getCodigoActual() const = 0;
    virtual int getCodigoActualPublicacion() const = 0;
};

#endif