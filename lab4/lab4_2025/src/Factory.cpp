#include "../include/Factory.h"
#include "../include/ControladorFechaActual.h"
#include <cstddef>
#include "../include/ControladorInmuebles.h"
#include "../include/ControladorUsuarios.h"

Factory* Factory::instance = NULL;

Factory::Factory() {

}

Factory* Factory::getInstance() {
    if (instance == NULL) {
        instance = new Factory();
    }
    return instance;
}

IControladorFechaActual* Factory::getControladorFechaActual(){
    return ControladorFechaActual::getInstance();
}

IControladorUsuarios* Factory::getControladorUsuarios() {
    return ControladorUsuarios::getInstance();
}

IControladorInmuebles* Factory::getControladorInmuebles() {
    return ControladorInmuebles::getInstance();
}


Factory::~Factory() {
}
