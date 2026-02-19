#ifndef DTINMUEBLE_H
#define DTINMUEBLE_H
#include <string>

class DTInmueble {
    private:
        int codigo;
        std::string direccion;
        int numeroPuerta;
        int superficie;
        int anioConstruccion;

    public:
        DTInmueble(int codigo, std::string direccion, int numeroPuerta, int superficie, int anioConstruccion);
        int getCodigo() const;
        std::string getDireccion() const;
        int getNumeroPuerta() const;
        int getSuperficie() const;
        int getAnioConstruccion() const;
        virtual ~DTInmueble();
};

#endif