#include "../include/Apartamento.h"
#include "../include/DTApartamento.h"

Apartamento::Apartamento(const std::string& direccion, int numeroPuerta, int superficie, int anioConstruccion, int piso, bool tieneAscensor, float gastosComunes)
    : Inmueble(0, direccion, numeroPuerta, superficie, anioConstruccion), piso(piso), tieneAscensor(tieneAscensor), gastosComunes(gastosComunes) {
}


Apartamento::~Apartamento(){
}

DTApartamento Apartamento::getDTApartamento(){
    DTInmueble dtinm = this->getDTInmueble();
    return DTApartamento(dtinm.getCodigo(), dtinm.getDireccion(), dtinm.getNumeroPuerta(),dtinm.getSuperficie(),dtinm.getAnioConstruccion(),this->piso, this->tieneAscensor, this->gastosComunes);

}