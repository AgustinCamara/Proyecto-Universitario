#ifndef ARTICULOREVISTA_H
#define ARTICULOREVISTA_H
#include "Publicacion.h"
#include "DTFecha.h"

class ArticuloRevista : public Publicacion {
    private:
        std::string revista;
        std::string extracto;
    public:
        ArticuloRevista(std::string doi, std::string tit, DTFecha f, std::string rev, std::string ext);
        DTRefer getDT() const; 
        bool contienePalabra(const std::string& palabra) const;
};

#endif
