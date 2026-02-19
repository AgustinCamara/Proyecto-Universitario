#include "../include/Usuario.h"
#include "DTUsuario.h"

Usuario::Usuario(std::string nickname, std::string contrasena, std::string nombre, std::string email)
    : nickname(nickname), contrasena(contrasena), nombre(nombre), email(email) {
}

Usuario::~Usuario() {
};



std::string Usuario:: getNombre()const{
    return this->nombre;
} 

std::string Usuario:: getNickname() const{
    return this->nickname;
}