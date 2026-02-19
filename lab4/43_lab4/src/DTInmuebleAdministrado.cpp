#include "../include/DTInmuebleAdministrado.h"

DTInmuebleAdministrado::DTInmuebleAdministrado(int codigo, std::string direccion, DTFecha* fechaComienzo) {
    this->codigo = codigo;
    this->direccion = direccion;
    this->fechaComienzo = fechaComienzo;
}

int DTInmuebleAdministrado::getCodigo() const {
    return codigo;
}

std::string DTInmuebleAdministrado::getDireccion() const {
    return direccion;
}

DTFecha* DTInmuebleAdministrado::getFechaComienzo() const {
    return fechaComienzo->copiar();
}

DTInmuebleAdministrado::~DTInmuebleAdministrado(){
    delete fechaComienzo;
}
