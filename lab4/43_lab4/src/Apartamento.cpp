#include "Apartamento.h"
#include "DTApartamento.h"
#include "Apartamento.h"

Apartamento::Apartamento(int piso, bool tieneAscensor, float gastosComunes)
    : Inmueble(0, "", 0, 0, 0), piso(piso), tieneAscensor(tieneAscensor), gastosComunes(gastosComunes) {
}

Apartamento::~Apartamento() {
}

DTInmueble* Apartamento::getDTInmueble() {
    return new DTApartamento(getCodigo(), getDireccion(), getNumeroPuerta(),
                             getSuperficie(), getAnoConstruccion(),
                             piso, tieneAscensor, gastosComunes);
}
