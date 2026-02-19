#ifndef DTINMUEBLEADMINISTRADO_H
#define DTINMUEBLEADMINISTRADO_H
#include "DTFecha.h"
#include <string>

class DTInmuebleAdministrado {
    private:
        int codigo;
        std::string direccion;
        DTFecha* fechaComienzo;

    public:
        DTInmuebleAdministrado(int codigo, std::string direccion, DTFecha* fechaComienzo);
        int getCodigo() const;
        std::string getDireccion() const;
        DTFecha* getFechaComienzo() const;
        void setFechaComienzo(DTFecha* fecha) { fechaComienzo = fecha; }
        ~DTInmuebleAdministrado();
};

#endif