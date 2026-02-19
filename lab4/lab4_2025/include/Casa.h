#ifndef CASA_H
#define CASA_H
#include "Inmueble.h"
#include "TipoTecho.h"
#include "DTCasa.h"


class Casa : public Inmueble {
    private:
        bool esPH;
        TipoTecho techo;

    public:
Casa(const std::string& direccion, int numeroPuerta, int superficie, int anio, bool esPH, TipoTecho techo);
        ~Casa();
        DTCasa getDTCasa();
};

#endif