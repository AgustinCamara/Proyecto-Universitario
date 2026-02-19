#ifndef APARTAMENTO_H
#define APARTAMENTO_H

#include "Inmueble.h"

class Apartamento : public Inmueble {
private:
    int piso;
    bool tieneAscensor;
    float gastosComunes;

public:
    Apartamento(int piso, bool tieneAscensor, float gastosComunes);
    virtual ~Apartamento();

    virtual DTInmueble* getDTInmueble() override;

    int getPiso() const;
    bool getTieneAscensor() const;
    float getGastosComunes() const;
};

#endif
