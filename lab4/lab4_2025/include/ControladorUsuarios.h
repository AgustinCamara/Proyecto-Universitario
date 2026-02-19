#ifndef CONTROLADORUSUARIOS_H
#define CONTROLADORUSUARIOS_H

#include "IControladorUsuarios.h"
#include <map>
#include <string>
#include "Usuario.h"
#include "DTUsuario.h"
#include "Propietario.h"
#include "Inmobiliaria.h"
#include "DTInmuebleAdministrado.h"
#include "DTPublicacion.h"
#include "TipoPublicacion.h"
#include "TipoInmueble.h"
#include <string>
#include <set>
#include <vector>

class ControladorUsuarios: public IControladorUsuarios {
private:
    std::map<std::string, Usuario*> usuarios;
    static ControladorUsuarios* instance;
    Propietario* propietarioRecordado;
    Inmobiliaria* inmobiliariaRecordada;
    std::string nicknameUsuarioRecordado;
    ControladorUsuarios();
public:
    static ControladorUsuarios* getInstance();
    bool altaCliente(const std::string& nickname, const std::string& contrasena, const std::string& nombre, const std::string& email, const std::string& apellido, const std::string& documento);
    bool altaPropietario(const std::string& nickname, const std::string& contrasena, const std::string& nombre, const std::string& email, const std::string& cuentaBancaria, const std::string& telefono);
    bool altaInmobiliaria(const std::string& nickname, const std::string& contrasena, const std::string& nombre, const std::string& email, const std::string& direccion, const std::string& url, const std::string& telefono);
    Propietario* getPropietarioRecordado();
    Inmobiliaria* getInmobiliariaRecordada();
    void finalizarAltaUsuario();
    void representarPropietario(const std::string& nicknamePropietario);
    std::set<DTUsuario> listarInmobiliarias();
    std::vector<DTInmuebleAdministrado> listarInmueblesAdministrados(const std::string& nicknameInmobiliaria);
    Usuario* getUsuario(const std::string& nickname);
    ~ControladorUsuarios();
    std::set<DTUsuario> listarPropietarios();
    std::set<DTInmuebleListado> listarInmueblesNoAdministradosInmobiliaria(const std::string& nicknameInmobiliaria);
    void altaAdministraPropiedad(std::string nicknameInmobiliaria, int codigoInmueble);
    std::set<DTUsuario> listarInmobiliariasNoSuscripto(std::string nicknameCliente);
    bool suscribirAInmobiliaria(std::string nicknameInmobiliaria);
    void finalizarSuscripcion();
    std::set<DTNotificacion> listarNotificaciones(std::string nicknameCliente);
    void eliminarNotificaciones();
    void finalizarConsulta(); 

    //achequearrrr
    std::set<DTUsuario> listarInmobiliariasSuscripto(const std::string nicknameCliente);
    bool desuscribirDeInmobiliaria(std::string nicknameInmobiliaria);
};

#endif