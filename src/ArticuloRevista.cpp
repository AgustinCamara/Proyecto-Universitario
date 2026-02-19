#include "../include/ArticuloRevista.h"
#include "../include/Investigador.h"

ArticuloRevista::ArticuloRevista(std::string doi, std::string tit, DTFecha f, std::string rev, std::string ext)
    : Publicacion(doi, tit, f), revista(rev), extracto(ext) {}

DTRefer ArticuloRevista::getDT() const {
    std::vector<std::string> listaAutores;
    for (size_t i = 0; i < autores.size(); ++i) {
        listaAutores.push_back(autores[i]->toString());
    }
    return DTRefer(DOI, titulo, fecha.toString(), listaAutores);
}

bool ArticuloRevista::contienePalabra(const std::string& palabra) const {
    return extracto.find(palabra) != std::string::npos;
}
