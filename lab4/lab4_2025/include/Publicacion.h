#ifndef PUBLICACION_H
#define PUBLICACION_H

#include "DTFecha.h"
#include "TipoPublicacion.h"
#include "DTPublicacion.h"
#include <string>

class Publicacion {
private:
    int codigo;
    DTFecha* fecha;
    TipoPublicacion tipo;
    std::string texto;
    float precio;
    bool activa;

public:
    Publicacion(int codigo, DTFecha* fecha, TipoPublicacion tipo, const std::string& texto, float precio, bool activa);
    ~Publicacion();

    int getCodigo();
    DTFecha* getFecha();
    TipoPublicacion getTipo();
    std::string getTexto();
    float getPrecio();
    bool esActiva();

    void setCodigo(int codigo);
    void setFecha(DTFecha* fecha);
    void setTipo(TipoPublicacion tipo);
    void setTexto(const std::string& texto);
    void setPrecio(float precio);
    void setActiva(bool activa);

    void desactivarPublicacion();
    void activarPublicacion();
    DTPublicacion getData();
};

#endif
