#include <algorithm>
#include "Investigador.h"
#include "Publicacion.h"
#include "DTFecha.h"

Investigador::Investigador(std::string oc, std::string nom, std::string inst) : ORCID(oc), nombre(nom), institucion(inst) {}

void Investigador::agregarPublicacion(Publicacion* pub) {
    if (pub && std::find(publicaciones.begin(), publicaciones.end(), pub) == publicaciones.end()) {
        publicaciones.push_back(pub); 
        pub->agregarAutor(this);
    }
}

std::vector<std::string> Investigador::listarPublicaciones(DTFecha desde, const std::string& palabra) const {
    std::vector<std::string> resultados;
    for (std::vector<Publicacion*>::const_iterator it = publicaciones.begin(); it != publicaciones.end(); ++it) {
        if ((*it)->getFecha() > desde && (*it)-> contienePalabra(palabra)) {
            resultados.push_back((*it)->getDOI());
        }
    }
    return resultados;
}

std::string Investigador::toString() const {
    return ORCID + "->" + nombre + "/" + institucion;
}

std::string Investigador::getORCID() const {
    return ORCID;
}

void Investigador::removerPublicacion(Publicacion* pub) {
    publicaciones.erase(std::remove(publicaciones.begin(), publicaciones.end(), pub), publicaciones.end()); 
}
