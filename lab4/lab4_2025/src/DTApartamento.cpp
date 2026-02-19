#include "../include/DTApartamento.h"

DTApartamento::DTApartamento(int codigo, std::string direccion, int numeroPuerta, int superficie, int anioConstruccion, int piso, bool tieneAscensor, float gastosComunes)
    : DTInmueble(codigo, direccion, numeroPuerta, superficie, anioConstruccion) {
    this->piso = piso;
    this->tieneAscensor = tieneAscensor;
    this->gastosComunes = gastosComunes;
}

int DTApartamento::getPiso() const {
    return piso;
}

bool DTApartamento::getTieneAscensor() const {
    return tieneAscensor;
}

float DTApartamento::getGastosComunes() const {
    return gastosComunes;
}

DTApartamento::~DTApartamento(){

}