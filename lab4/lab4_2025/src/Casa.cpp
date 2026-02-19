#include "../include/Casa.h"
#include "../include/DTCasa.h"

Casa::Casa(const std::string& direccion, int numeroPuerta, int superficie, int anio, bool esPH, TipoTecho techo)
    : Inmueble(0, direccion, numeroPuerta, superficie, anio), esPH(esPH), techo(techo) {
}

 Casa::~Casa(){
 }

DTCasa Casa::getDTCasa(){
    DTInmueble dtinm = this->getDTInmueble();
    return DTCasa(dtinm.getCodigo(), dtinm.getDireccion(), dtinm.getNumeroPuerta(),dtinm.getSuperficie(),dtinm.getAnioConstruccion(),this->esPH,this->techo);

}


