#include "../include/AdministraPropiedad.h"
#include "../include/Publicacion.h"
#include "../include/Inmueble.h"
#include "../include/Inmobiliaria.h"
#include "../include/TipoPublicacion.h"
#include "../include/DTFecha.h"
#include "../include/DTPublicacion.h"
#include "../include/Factory.h"
#include <sstream>

AdministraPropiedad::AdministraPropiedad(DTFecha* fecha)
    : fecha(fecha), inmueble(nullptr), inmobiliaria(nullptr),
      activaVenta(nullptr), activaAlquiler(nullptr) {}

AdministraPropiedad::~AdministraPropiedad() {
    delete fecha;
    for (auto& par : publicaciones)
        delete par.second;
    publicaciones.clear();
    activaVenta = NULL;
    activaAlquiler = NULL;
}

DTFecha* AdministraPropiedad::getFecha() {
    return fecha;
}

void AdministraPropiedad::setFecha(DTFecha* nuevaFecha) {
    if (fecha != nullptr)
        delete fecha;
    fecha = nuevaFecha;
}

const std::map<int, Publicacion*>& AdministraPropiedad::getPublicaciones() {
    return publicaciones;
}

Publicacion* AdministraPropiedad::obtenerActiva(TipoPublicacion tipo) {
    return (tipo == Venta) ? activaVenta : activaAlquiler;
}

bool AdministraPropiedad::yaExiste(TipoPublicacion tipo, const std::string& texto, float precio) {
    for (const auto& par : publicaciones) {
        Publicacion* p = par.second;
        if (p->getTipo() == tipo &&
            p->getTexto() == texto &&
            p->getPrecio() == precio) {
            return true;
        }
    }
    return false;
}

DTPublicacion AdministraPropiedad::getDatos() {
    if (!publicaciones.empty()) {
        return publicaciones.begin()->second->getData();
    }
    return DTPublicacion(0, fecha, "sin datos", "0", "inmobiliaria");
}

void AdministraPropiedad::buscar() { //hacer
}

Publicacion AdministraPropiedad::crearPubli(TipoPublicacion tipo, const std::string& texto, float precio) {
    DTFecha* fechaActual = Factory::getInstance()->getControladorFechaActual()->getFechaActual();

    static int ultimoCodigoTemp = 10000;
    int nuevoCodigo = ++ultimoCodigoTemp;

    return Publicacion(nuevoCodigo, fechaActual, tipo, texto, precio, true);
}


Inmueble* AdministraPropiedad::getInmueble() {
    return inmueble;
}

Inmobiliaria* AdministraPropiedad::inmobiliariaAsociada() {
    return inmobiliaria;
}
