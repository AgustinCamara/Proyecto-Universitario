#ifndef PAGINAWEB_H
#define PAGINAWEB_H
#include "Publicacion.h"

class PaginaWeb : public Publicacion {
    private:
        std::string url; 
        std:: string contenido;
    public:
        PaginaWeb(std::string doi, std::string tit, DTFecha f, std::string u, std::string cont);
        DTRefer getDT() const; 
        bool contienePalabra(const std::string& palabra) const;
};

#endif
