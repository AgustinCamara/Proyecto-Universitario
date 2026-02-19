#ifndef PUBLICACION_H
#define PUBLICACION_H
#include "DTRefer.h"  
#include "DTFecha.h"  
#include <vector>      
#include <string>     
#include <algorithm>  

class Investigador; 

class Publicacion { 
    protected:
        std::string DOI; 
        std::string titulo; 
        DTFecha fecha; 
        std::vector<Investigador*> autores;
    public:
        Publicacion(const std::string& doi, const std::string& tit, const DTFecha& f);
        virtual ~Publicacion() {}
        virtual DTRefer getDT() const = 0;
        virtual bool contienePalabra(const std::string& palabra) const = 0;
        void agregarAutor(Investigador* autor);
        DTFecha getFecha() const;
        std::string getDOI() const;
};

#endif
