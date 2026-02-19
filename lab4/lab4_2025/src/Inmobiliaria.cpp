#include "../include/Inmobiliaria.h"
#include "../include/AdministraPropiedad.h"
#include "../include/Propietario.h"
#include "../include/DTUsuario.h"
#include "../include/DTInmuebleAdministrado.h"
#include "../include/DTInmuebleListado.h"
#include "../include/DTFecha.h"
#include "../include/Publicacion.h"
#include <algorithm>

Inmobiliaria::Inmobiliaria(std::string nickname, std::string contrasena, std::string nombre,
                           std::string email, std::string direccion, std::string url, std::string telefono)
    : Usuario(nickname, contrasena, nombre, email),
      direccion(direccion), url(url), telefono(telefono) {}

Inmobiliaria::~Inmobiliaria() {
    for (auto* ap : propiedadesAdministradas)
        delete ap;
    propiedadesAdministradas.clear();
    propietariosRepresentados.clear();
    suscriptores.clear();
}

std::string Inmobiliaria::getDireccion() { return direccion; }
std::string Inmobiliaria::getUrl() { return url; }
std::string Inmobiliaria::getTelefono() { return telefono; }

void Inmobiliaria::setDireccion(std::string& dir) { direccion = dir; }
void Inmobiliaria::setUrl(std::string& u) { url = u; }
void Inmobiliaria::setTelefono(std::string& tel) { telefono = tel; }

DTUsuario Inmobiliaria::getDT() const {
    return DTUsuario(getNickname(), getNombre());
}

void Inmobiliaria::altaAdminitracionPropiedad(Inmueble* inmueble, DTFecha* fecha) {
    auto* ap = new AdministraPropiedad(fecha);
    propiedadesAdministradas.push_back(ap);
    inmueble->asociarAdministracionPropiedad(ap);
}

std::vector<DTInmuebleAdministrado> Inmobiliaria::listarInmuebles() {
    std::vector<DTInmuebleAdministrado> resultado;
    for (auto* ap : propiedadesAdministradas) {
        if (ap->getInmueble() != nullptr) {
            resultado.push_back(ap->getInmueble()->getDTInmuebleAdministrado());
        }
    }
    return resultado;
}

std::set<DTInmuebleListado> Inmobiliaria::getInmueblesNoAdminPropietario() {
    std::set<DTInmuebleListado> resultado;
    for (auto* p : propietariosRepresentados) {
        std::set<DTInmuebleListado> lista = p->getInmueblesNoAdmin(this);
        resultado.insert(lista.begin(), lista.end());
    }
    return resultado;
}

bool Inmobiliaria::yaExiste(int codigoInmueble, TipoPublicacion tipo, const std::string& texto, float precio) {
    for (auto* ap : propiedadesAdministradas) {
        Inmueble* in = ap->getInmueble();
        if (in != nullptr && in->getCodigo() == codigoInmueble) {
            if (ap->yaExiste(tipo, texto, precio))
                return true;
        }
    }
    return false;
}

void Inmobiliaria::agregarPublicacion() {
}

void Inmobiliaria::agregarPropietario(Propietario* propietario) {
    propietariosRepresentados.insert(propietario);
}

void Inmobiliaria::agregarSuscriptor(ISuscrito* observer) {
    suscriptores.insert(observer);
}

void Inmobiliaria::eliminarSuscriptor(ISuscrito* observer) {
    suscriptores.erase(observer);
}

bool Inmobiliaria::esSuscriptor(const std::string& nicknameCliente) const {
    for (auto* obs : suscriptores) {
        if (obs->getNickname() == nicknameCliente)
            return true;
    }
    return false;
}

void Inmobiliaria::notificarSuscriptores(const DTNotificacion& notificacion) {
    for (auto* s : suscriptores) {
        s->notificar(notificacion);
    }
}
