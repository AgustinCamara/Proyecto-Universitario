#ifndef CONTROLADORINMUEBLE_H
#define CONTROLADORINMUEBLE_H

#include <set>
#include <string>
#include "IControladorInmueble.h"
#include "DTPublicacion.h"
#include "DTInmueble.h"
#include "TipoInmueble.h"
#include "TipoPublicacion.h"

class ControladorInmueble : public IControladorInmueble {
private:
    static ControladorInmueble* instancia;
    ControladorInmueble(); 

public:
    static ControladorInmueble* getInstancia();
    ~ControladorInmueble();
    std::set<DTPublicacion> listarPublicacion(TipoPublicacion tipoPublicacion, float precioMinimo, float precioMaximo, TipoInmueble tipoInmueble);
    void eliminarInmueble(int codigoInmueble);
    bool altaCasa(const std::string& nicknamePropietario, const std::string& direccion,
                  int numeroPuerta, int superficie, int anioConstruccion, bool esPH, TipoTecho techo);
    bool altaApartamento(const std::string& nicknamePropietario, const std::string& direccion,
                         int numeroPuerta, int superficie, int anioConstruccion,
                         int piso, bool tieneAscensor, float gastosComunes);
    bool altaPublicacion(const std::string& nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, const std::string& texto, float precio);
    DTInmueble detalleInmueblePublicacion(int codigoPublicacion);
    DTInmueble detalleInmueble(int codigoInmueble);
};

#endif
