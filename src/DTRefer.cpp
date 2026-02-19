#include "../include/DTRefer.h"

DTRefer::DTRefer(const std::string& d, const std::string& t, const std::string& f, const std::vector<std::string>& a)
    : DOI(d), titulo(t), fecha(f), autores(a) {}

std::string DTRefer::getDOI() const { 
    return DOI; 
}

std::string DTRefer::getTitulo() const { 
    return titulo; 
}

std::string DTRefer::getFecha() const { 
    return fecha;
}

std::vector<std::string> DTRefer::getAutores() const { return autores; }

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream& os, const DTRefer& dt) {  
    os << dt.DOI << " -> " << dt.titulo << " (" << dt.fecha << ") / ";
    for (size_t i = 0; i < dt.autores.size(); i++) {
        os << dt.autores[i];
        if (i != dt.autores.size() - 1) os << ", ";
    }
    return os;
}
