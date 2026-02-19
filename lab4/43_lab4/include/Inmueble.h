#ifndef INMUEBLE_H
#define INMUEBLE_H

#include "DTPublicacion.h"
#include "DTFecha.h"
#include "DTInmueble.h"
#include "DTInmuebleListado.h"
#include "DTInmuebleAdministrado.h"
#include "TipoInmueble.h"
#include <string>
#include <vector>
#include <list>

class AdministraPropiedad;
class Inmobiliaria;
class Propietario;

class Inmueble {
private:
    int codigo;
    std::string direccion;
    int numeroPuerta;
    int superficie;
    int anoConstruccion;
    DTFecha* fechaComienzo;
    std::list<AdministraPropiedad*> administraciones;
    Propietario* propietario;

public:
    Inmueble(int codigo, const std::string& direccion, int numeroPuerta, int superficie, int anoConstruccion);
    virtual ~Inmueble();

    int getCodigo() const;
    std::string getDireccion() const;
    int getNumeroPuerta() const;
    int getSuperficie() const;
    int getAnoConstruccion() const;
    void setPropietario(Propietario*);
    void setCodigo(int codigo);
    void setDireccion(const std::string& direccion);
    void setNumeroPuerta(int numeroPuerta);
    void setSuperficie(int superficie);
    void setAnoConstruccion(int anoConstruccion);
    std::list<AdministraPropiedad*> getAdministraciones();
    virtual DTInmueble* getDTInmueble() = 0;
    DTInmuebleListado* getDTInmuebleListado();
    DTInmuebleAdministrado* getDTInmuebleAdministrado();
    bool esInmueble(Inmobiliaria*);
    void asociarAdministracionPropiedad(AdministraPropiedad* ap);
};

#endif
