#ifndef LIBRO_H
#define LIBRO_H
#include "Publicacion.h"
#include <vector>
#include <set>

class Libro : public Publicacion {
    private:
        std::string editorial; 
        std::set<std::string> palabrasDestacadas;
    public:
        Libro(std::string doi, std::string tit, DTFecha f, std::string ed, const std::set<std::string>& palD);
        DTRefer getDT() const;
        bool contienePalabra(const std::string& palabra) const; 
};

#endif
