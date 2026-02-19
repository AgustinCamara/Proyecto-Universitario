#ifndef ICONTROLADORUSUARIO_H
#define ICONTROLADORUSUARIO_H

#include <string>
#include <set>
#include <vector>

#include "TipoTecho.h"
#include "TipoPublicacion.h"
#include "DTUsuario.h"
#include "DTInmuebleAdministrado.h"
#include "DTInmuebleListado.h"

class IControladorUsuario {
public:
virtual ~IControladorUsuario() {}
    virtual bool altaCliente(const std::string& nickname, const std::string& contrasena, const std::string& nombre, const std::string& email, const std::string& apellido, const std::string& documento) = 0;
    virtual bool altaPropietario(const std::string& nickname, const std::string& contrasena, const std::string& nombre, const std::string& email, const std::string& cuentaBancaria, const std::string& telefono) = 0;
    virtual bool altaInmobiliaria(const std::string& nickname, const std::string& contrasena, const std::string& nombre, const std::string& email, const std::string& direccion, const std::string& url, const std::string& telefono) = 0;

    virtual void altaAdministraPropiedad(const std::string& nicknameInmobiliaria, int codigoInmueble) = 0;
    virtual std::vector<DTInmuebleAdministrado> listarInmueblesAdministrados(const std::string& nicknameInmobiliaria) = 0;
    virtual std::set<DTInmuebleListado> listarInmueblesNoAdministradosInmobiliaria(const std::string& nicknameInmobiliaria) = 0;
    virtual std::set<DTUsuario> listarPropietarios() = 0;
    virtual std::set<DTUsuario> listarInmobiliarias() = 0;
    virtual std::string representarPropietario(const std::string& nicknamePropietario) = 0;
    virtual void suscribirseAInmobiliaria(const std::string& nicknameUsuario, const std::string& nicknameInmobiliaria) = 0;
    virtual void mostrarNotificaciones(const std::string& nicknameUsuario) = 0;
    virtual void eliminarSuscripcion(const std::string& nicknameUsuario, const std::string& nicknameInmobiliaria) = 0;
    virtual std::set<std::string> listarInmobiliariasNoSuscripto(const std::string& nicknameUsuario) = 0;


};

#endif
