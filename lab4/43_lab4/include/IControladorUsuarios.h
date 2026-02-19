#ifndef ICONTROLADORUSUARIOS_H
#define ICONTROLADORUSUARIOS_H
#include <string>  
#include <list>  

#include <set>
#include "Propietario.h"
#include "TipoInmueble.h"
#include "TipoPublicacion.h"
#include "DTPublicacion.h"
#include "Inmobiliaria.h"
#include "DTUsuario.h"
#include "DTPublicacion.h"
#include "DTInmuebleAdministrado.h"

class IControladorUsuarios{
    public:
    virtual bool altaCliente(const std::string& nickname, const std::string& contrasena, const std::string& nombre, const std::string& email, const std::string& apellido, const std::string& documento)=0;
    virtual bool altaPropietario(const std::string& nickname, const std::string& contrasena, const std::string& nombre, const std::string& email, const std::string& cuentaBancaria, const std::string& telefono)=0;
    virtual bool altaInmobiliaria(const std::string& nickname, const std::string& contrasena, const std::string& nombre, const std::string& email, const std::string& direccion, const std::string& url, const std::string& telefono)=0;
    virtual Propietario* getPropietarioRecordado()=0;
    virtual Inmobiliaria* getInmobiliariaRecordada()=0;
    virtual void finalizarAltaUsuario()=0;
    virtual void representarPropietario(const std::string& nicknamePropietario)=0;
    virtual std::set<DTUsuario*> listarInmobiliarias()=0;
    virtual std::list<DTInmuebleAdministrado*> listarInmueblesAdministrados(const std::string& nicknameInmobiliaria)=0;
    virtual std::set<DTUsuario*> listarPropietarios()=0;
    virtual std::set<DTUsuario*> listarInmobiliariasNoSuscripto(const std::string& nicknameCliente)=0;
    virtual bool suscribirAInmobiliaria(const std::string& nicknameCliente, const std::string& nicknameInmobiliaria)=0;
    virtual void finalizarSuscripcion()=0;
    virtual std::set<DTNotificacion*> listarNotificaciones(std::string nicknameCliente)=0;
    virtual void eliminarNotificaciones(std::string nicknameUsuario)=0;
    virtual void finalizarConsulta()=0;
    virtual std::set<DTInmuebleListado*> listarInmueblesNoAdministradosInmobiliaria(const std::string& nicknameInmobiliaria)=0;
    virtual void altaAdministraPropiedad(std::string nicknameInmobiliaria, int codigoInmueble)=0;
    virtual Usuario* getUsuario(const std::string& nickname)=0;

    virtual std::set<DTUsuario*> listarInmobiliariasSuscripto(const std::string& nicknameCliente) = 0;

    virtual bool desuscribirDeInmobiliaria(const std::string& nicknameCliente ,const std::string& nicknameInmobiliaria) = 0;

   
};

#endif
