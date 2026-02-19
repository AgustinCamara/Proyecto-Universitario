#ifndef APARTAMENTO_H
#define APARTAMENTO_H
#include "Inmueble.h"
#include "DTApartamento.h"


class Apartamento : public Inmueble {
    private:
        int piso;
        bool tieneAscensor;
        float gastosComunes;

    public:
    Apartamento(const std::string& direccion, int numeroPuerta, int superficie, int anioConstruccion, int piso, bool tieneAscensor, float gastosComunes);

        ~Apartamento();
        DTApartamento getDTApartamento();
};

#endif