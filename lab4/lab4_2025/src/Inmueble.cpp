#include "../include/Inmueble.h"
#include "../include/AdministraPropiedad.h"
#include "../include/Propietario.h"
#include "../include/DTInmueble.h"
#include "../include/DTInmuebleAdministrado.h"
#include "../include/DTInmuebleListado.h"
#include "../include/DTPublicacion.h"

Inmueble::Inmueble(int codigo, const std::string& direccion, int numeroPuerta, int superficie, int anoConstruccion)
    : codigo(codigo), direccion(direccion), numeroPuerta(numeroPuerta), superficie(superficie), anoConstruccion(anoConstruccion), fechaComienzo(nullptr), propietario(nullptr) {}

Inmueble::~Inmueble() {
    administraciones.clear(); // no se borran los objetos AdministraPropiedad, solo referencias
    delete fechaComienzo;
}

// Getters básicos
int Inmueble::getCodigo() const {
    return this->codigo;
}

std::string Inmueble::getDireccion() const {
    return this->direccion;
}

int Inmueble::getNumeroPuerta() const {
    return this->numeroPuerta;
}

int Inmueble::getSuperficie() const {
    return this->superficie;
}

int Inmueble::getAnoConstruccion() const {
    return this->anoConstruccion;
}

// Setters
void Inmueble::setCodigo(int codigo) {
    this->codigo = codigo;
}

void Inmueble::setDireccion(const std::string& direccion) {
    this->direccion = direccion;
}

void Inmueble::setNumeroPuerta(int numeroPuerta) {
    this->numeroPuerta = numeroPuerta;
}

void Inmueble::setSuperficie(int superficie) {
    this->superficie = superficie;
}

void Inmueble::setAnoConstruccion(int anoConstruccion) {
    this->anoConstruccion = anoConstruccion;
}

std::vector<AdministraPropiedad*> Inmueble::getAdministraciones() {
    return administraciones;
}

bool Inmueble::esInmueble(Inmobiliaria* inmobiliaria) {
    for (AdministraPropiedad* admin : administraciones) {
        if (admin->inmobiliariaAsociada() == inmobiliaria)
            return true;
    }
    return false;
}

void Inmueble::asociarAdministracionPropiedad(AdministraPropiedad* ap) {
    this->administraciones.push_back(ap);
}

DTInmuebleAdministrado Inmueble::getDTInmuebleAdministrado() {
    return DTInmuebleAdministrado(this->codigo, this->direccion, this->fechaComienzo);
}

DTInmuebleListado Inmueble::getDTInmuebleListado() {
    return DTInmuebleListado(this->codigo, this->direccion, this->propietario ? this->propietario->getNickname() : "Desconocido");
}

DTInmueble Inmueble::getDTInmueble() {
    return DTInmueble(this->codigo, this->direccion, this->numeroPuerta, this->superficie, this->anoConstruccion);
}
