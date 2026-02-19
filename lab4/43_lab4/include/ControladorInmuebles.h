#ifndef CONTROLADORINMUEBLES_H
#define CONTROLADORINMUEBLES_H

#include <map>
#include <set>
#include "Inmueble.h"
#include "DTPublicacion.h"
#include "DTInmueble.h"
#include "DTInmuebleListado.h"
#include "DTInmuebleAdministrado.h"
#include "TipoInmueble.h"
#include "TipoTecho.h" 
#include "Casa.h"
#include "Apartamento.h"
#include "IControladorInmuebles.h"
#include <list>

class ControladorInmuebles : public IControladorInmuebles {
private:
    std::map<int, Inmueble*> inmuebles;
    int codigoActual = 0;
    int codigoActualPublicacion = 0;

public:
    ControladorInmuebles();
    virtual ~ControladorInmuebles();
    static ControladorInmuebles* instance;
    static ControladorInmuebles* getInstance();

    void altaCasa(const std::string& direccion, int numeroPuerta, int superficie, int anio, bool esPH, TipoTecho techo) override;
    void altaApartamento(const std::string& direccion, int numeroPuerta, int superficie, int ambientes, int banios, bool ascensor, float gastosComunes) override;
    void eliminarInmueble(int codigo) override;
    void setCodigoActualPublicacion(int nuevoCodigo) override;
    bool altaPublicacion(const std::string& nicknameInmobiliaria, int codigoInmueble, TipoPublicacion tipoPublicacion, const std::string& texto, float precio);
    std::set<DTPublicacion*> listarPublicacion(TipoPublicacion tipo, float min, float max, tipoInmueble::TipoInmueble tipoInm) override;
    DTInmueble* detalleInmueblePublicacion(int codigo) override;
    DTInmueble* detalleInmueble(int codigo) override;
    std::list<DTInmuebleListado*> listarInmuebles() override;
    Inmueble* obtenerInmueble(int codigo) override;
    int getCodigoActual() const  { return codigoActual; }
    int getCodigoActualPublicacion() const  { return codigoActualPublicacion; }
};


#endif