#include "../include/Publicacion.h"
#include <sstream>

Publicacion::Publicacion(int codigo, DTFecha* fecha, TipoPublicacion tipo, const std::string& texto, float precio, bool activa)
    : codigo(codigo), fecha(fecha), tipo(tipo), texto(texto), precio(precio), activa(activa) {}

Publicacion::~Publicacion() {
    delete fecha;
}

int Publicacion::getCodigo() {
    return codigo;
}

DTFecha* Publicacion::getFecha() {
    return fecha;
}

TipoPublicacion Publicacion::getTipo() {
    return tipo;
}

std::string Publicacion::getTexto() {
    return texto;
}

float Publicacion::getPrecio() {
    return precio;
}

bool Publicacion::esActiva() {
    return activa;
}

void Publicacion::setCodigo(int codigo) {
    this->codigo = codigo;
}

void Publicacion::setFecha(DTFecha* fecha) {
    this->fecha = fecha;
}

void Publicacion::setTipo(TipoPublicacion tipo) {
    this->tipo = tipo;
}

void Publicacion::setTexto(const std::string& texto) {
    this->texto = texto;
}

void Publicacion::setPrecio(float precio) {
    this->precio = precio;
}

void Publicacion::setActiva(bool activa) {
    this->activa = activa;
}

void Publicacion::desactivarPublicacion() {
    activa = false;
}

void Publicacion::activarPublicacion() {
    activa = true;
}

DTPublicacion* Publicacion::getData() {
    std::ostringstream oss;
    oss << precio;
    return new DTPublicacion(codigo, fecha, texto, oss.str(), inmobiliaria);
}

void Publicacion::setInmobiliaria(const std::string& inmobiliaria) {
    this->inmobiliaria = inmobiliaria;
}