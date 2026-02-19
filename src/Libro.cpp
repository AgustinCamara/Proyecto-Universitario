#include "../include/Libro.h"
#include "../include/Investigador.h"

Libro::Libro(std::string doi, std::string tit, DTFecha f, std::string edit, const std::set<std::string>& palD)
    : Publicacion(doi, tit, f), palabrasDestacadas(palD) {}

DTRefer Libro::getDT() const {
    std::vector<std::string> listaAutores;
    for (size_t i = 0; i < autores.size(); ++i) {
        listaAutores.push_back(autores[i]->toString());
    }
    return DTRefer(DOI, titulo, fecha.toString(), listaAutores);
}

bool Libro::contienePalabra(const std::string& palabra) const {
    return palabrasDestacadas.find(palabra) != palabrasDestacadas.end();
}
