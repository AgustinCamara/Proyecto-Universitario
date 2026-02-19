#include "Casa.h"
#include "DTCasa.h"
#include "Casa.h"

Casa::Casa(bool esPH, TipoTecho techo)
    : Inmueble(0, "", 0, 0, 0), esPH(esPH), techo(techo) {
}

Casa::~Casa() {
}

DTInmueble* Casa::getDTInmueble() {
    return new DTCasa(getCodigo(), getDireccion(), getNumeroPuerta(),
                      getSuperficie(), getAnoConstruccion(), esPH, techo);
}
