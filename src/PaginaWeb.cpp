#include "../include/PaginaWeb.h"
#include "../include/Investigador.h"

PaginaWeb::PaginaWeb(std::string doi, std::string tit, DTFecha f, std::string u, std::string cont)
: Publicacion(doi, tit, f), url(u), contenido(cont) {}

DTRefer PaginaWeb::getDT() const {
    std::vector<std::string> listaAutores;
    for (size_t i = 0; i < autores.size(); ++i) {
        listaAutores.push_back(autores[i]->toString());
    }
    return DTRefer(DOI, titulo, fecha.toString(), listaAutores);
}

bool PaginaWeb::contienePalabra(const std::string& palabra) const {
    return contenido.find(palabra) != std::string::npos;
}
