#ifndef PROPIETARIO_H
#define PROPIETARIO_H
#include "Usuario.h"
#include <string>
#include "DTNotificacion.h"
#include "ISuscrito.h"
#include "Inmueble.h"
#include "DTInmuebleListado.h"
#include "Inmobiliaria.h"

class Propietario : public Usuario, public ISuscrito {
    private:
        std::string cuentaBancaria;
        std::string telefono;
        std::vector<Inmueble*> inmuebles;
        std::set<DTNotificacion> notificaciones;

    public:
    DTUsuario getDT() const override;

        Propietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono);
        void agregarInmueble(Inmueble* inmueble); 
        void eliminarInmueble(Inmueble* inmueble);
        ~Propietario();
        std::set<DTInmuebleListado> getInmueblesNoAdmin(Inmobiliaria* inmobiliaria);
        void notificar(const DTNotificacion& notificacion);
        std::set<DTNotificacion> getNotificaciones() const;
        void limpiarNotificaciones();
        std::string getNickname() const;
};

#endif