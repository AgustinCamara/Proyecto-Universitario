#include "../include/AdministraPropiedad.h"
#include "../include/Publicacion.h"
#include "../include/Inmueble.h"
#include "../include/Inmobiliaria.h"
#include "../include/TipoPublicacion.h"
#include "../include/DTFecha.h"
#include "../include/DTPublicacion.h"
#include "../include/Factory.h"
#include "../include/DTInmuebleAdministrado.h"
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
    if (tipo == Venta)
        return activaVenta;
    else if (tipo == Alquiler)
        return activaAlquiler;
    else
        return nullptr;
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

DTPublicacion* AdministraPropiedad::getDatos() {
    if (!publicaciones.empty()) {
        return publicaciones.begin()->second->getData();
    }
    return new DTPublicacion(0, fecha, "sin datos", "0", "inmobiliaria");
}

bool AdministraPropiedad::crearPubli(TipoPublicacion tipo, const std::string& texto, float precio) {
    DTFecha* fechaActual = Factory::getInstance()->getControladorFechaActual()->getFechaActual();
    int ultimoCodigo = Factory::getInstance()->getControladorInmuebles()->getCodigoActualPublicacion();
    ultimoCodigo++;
    publicaciones[ultimoCodigo] = new Publicacion(ultimoCodigo, fechaActual, tipo, texto, precio, true);
    publicaciones[ultimoCodigo]->setInmobiliaria(inmobiliaria->getNickname());
    Factory::getInstance()->getControladorInmuebles()->setCodigoActualPublicacion(ultimoCodigo);
    for (auto& par : publicaciones) {
        Publicacion* pu = par.second;
        if (pu->getTipo() == tipo && pu->esActiva() == true) {
            if (pu->getFecha() < fecha) {
                pu->desactivarPublicacion();
            } else {
                publicaciones.find(ultimoCodigo)->second->desactivarPublicacion();
            }
        }
    }
    if (tipo == Venta) {
        activaVenta = publicaciones[ultimoCodigo];
    } else if (tipo == Alquiler) {
        activaAlquiler = publicaciones[ultimoCodigo];
    }
    
    return true; 

}

DTInmuebleAdministrado* AdministraPropiedad::getDTInmuebleAdmin() {
    return new DTInmuebleAdministrado(inmueble->getCodigo(), inmueble->getDireccion(), fecha->copiar());
}

Inmueble* AdministraPropiedad::getInmueble() {
    return inmueble;
}

Inmobiliaria* AdministraPropiedad::getInmobiliaria() const {
    return inmobiliaria;
}
