#include "Agenda.h"
#include <iostream>

// Constructor
Agenda::Agenda(DTFecha* fecha, std::string& formaContacto) {}

// destructor
Agenda::~Agenda() {
    delete fecha;
}

// getters 
DTFecha* Agenda::getFecha() {
    return fecha;
}
std::string Agenda::getFormaContacto() {
    return formaContacto;
}

// setters
void Agenda::setFecha(DTFecha* fecha) {
    this->fecha = fecha;
}
void Agenda::setFormaContacto(std::string& formaContacto) {
    this->formaContacto = formaContacto;
}
