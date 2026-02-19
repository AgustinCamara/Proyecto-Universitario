#ifndef CLIENTE_H
#define CLIENTE_H
#include "Usuario.h"
#include <string>
#include <set>
#include "DTNotificacion.h"
#include "ISuscrito.h"

class Cliente : public Usuario, public ISuscrito {
    private:
        std::string apellido;
        std::string documento;
        std::set<DTNotificacion> notificaciones;

    public:
        Cliente(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string apellido, std::string documento);
        ~Cliente();
DTUsuario getDT() const override;

        void notificar(const DTNotificacion& notificacion);
        std::set<DTNotificacion> getNotificaciones() const;
        void limpiarNotificaciones();
        std::string getNickname() const; 
};

#endif