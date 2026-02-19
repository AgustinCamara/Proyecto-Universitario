#include "../include/Publicacion.h"

Publicacion::Publicacion(const std::string& doi, const std::string& tit, const DTFecha& f) : DOI(doi), titulo(tit), fecha(f) {}

void Publicacion::agregarAutor(Investigador* autor) {
    autores.push_back(autor); 
}

DTFecha Publicacion::getFecha() const {
    return fecha;
}

std::string Publicacion::getDOI() const {
    return DOI;
}
