#include "../include/DTFecha.h"
#include <sstream>

DTFecha::DTFecha(int d, int m, int a): dia(d), mes(m), anio(a) {}

int DTFecha::getDia() const{
    return dia;
}

int DTFecha::getMes() const{
    return mes;
}

int DTFecha::getAnio() const{
    return anio;
}

bool DTFecha::operator>(const DTFecha& otra) const{
    return anio > otra.anio || (anio == otra.anio && mes > otra.mes) || (anio == otra.anio && mes == otra.mes && dia > otra.dia);
}

std::string DTFecha::toString() const{
    std::stringstream ss;
    ss << dia << "/" << mes << "/" << anio;
    return ss.str();
}
