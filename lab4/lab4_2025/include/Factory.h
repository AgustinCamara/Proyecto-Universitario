#ifndef FACTORY_H
#define FACTORY_H

#include "IControladorFechaActual.h"
#include "IControladorInmuebles.h"
#include "IControladorUsuarios.h"



class Factory {
    private:
        static Factory* instance;
        Factory();

    public:
        static Factory* getInstance();
        IControladorFechaActual* getControladorFechaActual();
        IControladorUsuarios* getControladorUsuarios();
        IControladorInmuebles* getControladorInmuebles();
        ~Factory();
};

#endif