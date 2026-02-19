#ifndef CASA_H
#define CASA_H

#include "Inmueble.h"
#include "TipoTecho.h"

class Casa : public Inmueble {
private:
    bool esPH;
    TipoTecho techo;
public:
    Casa(bool esPH, TipoTecho techo);
    virtual ~Casa();
    virtual DTInmueble* getDTInmueble() override;
    bool getEsPH() const;
    TipoTecho getTecho() const;
};

#endif
