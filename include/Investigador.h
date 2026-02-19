#ifndef INVESTIGADOR_H
#define INVESTIGADOR_H
#include "DTFecha.h" 
#include <string>
#include <vector>

class Publicacion; 

class Investigador {
    private:
        std::string ORCID; 
        std::string nombre;
        std::string institucion;
        std::vector<Publicacion*> publicaciones;
    public:
        void removerPublicacion(Publicacion* pub); 
        Investigador(std::string oc, std::string nom, std::string inst);
        void agregarPublicacion(Publicacion* pub);
        std::vector<std::string> listarPublicaciones(DTFecha desde, const std::string& palabra) const;
        std::string toString() const;
        std::string getORCID() const;
};

#endif
