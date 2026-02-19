#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H

#include "Usuario.h"
#include "TipoPublicacion.h"
#include "DTUsuario.h"
#include "DTInmuebleListado.h"
#include "DTInmuebleAdministrado.h"
#include "ISuscrito.h"
#include "DTNotificacion.h"
#include "Inmueble.h"
#include <vector>
#include <set>
#include <string>

class AdministraPropiedad;
class Propietario;

class Inmobiliaria : public Usuario {
private:
    std::string direccion;
    std::string url;
    std::string telefono;

    std::vector<AdministraPropiedad*> propiedadesAdministradas;
    std::set<Propietario*> propietariosRepresentados;
    std::set<ISuscrito*> suscriptores;

public:
    Inmobiliaria(std::string nickname, std::string contrasena, std::string nombre,
                 std::string email, std::string direccion, std::string url, std::string telefono);
    ~Inmobiliaria();

    std::string getDireccion();
    std::string getUrl();
    std::string getTelefono();
    void setDireccion(std::string& direccion);
    void setUrl(std::string& url);
    void setTelefono(std::string& telefono);
    DTUsuario getDT() const override;

    std::vector<DTInmuebleAdministrado> listarInmuebles();
    std::set<DTInmuebleListado> getInmueblesNoAdminPropietario();
    void altaAdminitracionPropiedad(Inmueble* inmueble, DTFecha* fecha);
    bool yaExiste(int codigoInmueble, TipoPublicacion tipoPublicacion, const std::string& texto, float precio);
    void agregarPublicacion(); 

    void agregarPropietario(Propietario* propietario);

    void agregarSuscriptor(ISuscrito* observer);
    void eliminarSuscriptor(ISuscrito* observer);
    void notificarSuscriptores(const DTNotificacion& notificacion);
    bool esSuscriptor(const std::string& nicknameCliente) const;
};

#endif
