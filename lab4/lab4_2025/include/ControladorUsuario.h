#ifndef CONTROLADORUSUARIO_H 
#define CONTROLADORUSUARIO_H

#include <map>
#include <set>
#include <vector>
#include <string>
#include <iostream>

#include "Usuario.h"
#include "Cliente.h"
#include "Propietario.h"
#include "Inmobiliaria.h"
#include "TipoTecho.h"
#include "TipoPublicacion.h"
#include "Inmueble.h"
#include "Casa.h"
#include "Apartamento.h"
#include "DTUsuario.h"
#include "DTInmuebleAdministrado.h"
#include "DTPublicacion.h"
#include "DTInmuebleListado.h"
#include "IControladorUsuario.h"

class ControladorUsuario : public IControladorUsuario {
private:
    static ControladorUsuario* instancia;
    std::map<std::string, Usuario*> usuarios;
    std::map<std::string, Inmobiliaria*> inmobiliarias;
    std::map<std::string, Propietario*> propietarios;
    std::map<std::string, Cliente*> clientes;

    ControladorUsuario();

public:
    static ControladorUsuario* getInstancia();
    virtual ~ControladorUsuario() throw();

    bool altaCliente(const std::string& nickname, const std::string& contrasena,
                     const std::string& nombre, const std::string& email,
                     const std::string& apellido, const std::string& documento);

    bool altaPropietario(const std::string& nickname, const std::string& contrasena,
                         const std::string& nombre, const std::string& email,
                         const std::string& cuentaBancaria, const std::string& telefono);

    bool altaInmobiliaria(const std::string& nickname, const std::string& contrasena,
                          const std::string& nombre, const std::string& email,
                          const std::string& direccion, const std::string& url,
                          const std::string& telefono);

    

    

    std::vector<DTInmuebleAdministrado> listarInmueblesAdministrados(const std::string& nicknameInmobiliaria);
    std::set<DTInmuebleListado> listarInmueblesNoAdministradosInmobiliaria(const std::string& nicknameInmobiliaria);
    void altaAdministraPropiedad(const std::string& nicknameInmobiliaria, int codigoInmueble);

    std::set<DTUsuario> listarPropietarios();
    std::set<DTUsuario> listarInmobiliarias();
    std::string representarPropietario(const std::string& nicknamePropietario);

    // Suscripciones y notificaciones
    void suscribirseAInmobiliaria(const std::string& nicknameUsuario, const std::string& nicknameInmobiliaria);
    void eliminarSuscripcion(const std::string& nicknameUsuario, const std::string& nicknameInmobiliaria);
    void mostrarNotificaciones(const std::string& nicknameUsuario);
    std::set<std::string> listarInmobiliariasNoSuscripto(const std::string& nicknameUsuario);
};

#endif
