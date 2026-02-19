#ifndef DTFECHA_H
#define DTFECHA_H
#include <string>

class DTFecha {
    private:
        int dia, mes, anio;
    public:
        DTFecha(int d, int m, int a);
        bool operator>(const DTFecha& otra) const;
        std::string toString() const; // devuelve la fecha como string tipo dd/mm/aaaa
        int getDia() const; 
        int getMes() const;
        int getAnio() const;
};

#endif
