#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include "DTUsuario.h"

class Usuario {
private:
    std::string nickname;
    std::string contrasena;
    std::string nombre;
    std::string email;

public:
    Usuario(std::string nickname, std::string contrasena, std::string nombre, std::string email);
    virtual ~Usuario();

    virtual DTUsuario getDT() const = 0;  
    std::string getNickname() const;
    std::string getNombre() const;
};

#endif
