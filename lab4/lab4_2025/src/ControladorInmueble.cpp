#include "../include/ControladorInmueble.h"

// Inicialización del puntero estático
ControladorInmueble* ControladorInmueble::instancia = NULL;

// Constructor privado
ControladorInmueble::ControladorInmueble() {
    // Por ahora vacío
}

// Destructor
ControladorInmueble::~ControladorInmueble() {
    // Por ahora vacío
}

// Singleton
ControladorInmueble* ControladorInmueble::getInstancia() {
    if (instancia == NULL) {
        instancia = new ControladorInmueble();
    }
    return instancia;
}

// Métodos mínimos vacíos para evitar errores de linker

std::set<DTPublicacion> ControladorInmueble::listarPublicacion(TipoPublicacion, float, float, TipoInmueble) {
    return std::set<DTPublicacion>(); // stub
}

void ControladorInmueble::eliminarInmueble(int) {
    // stub
}

bool ControladorInmueble::altaPublicacion(const std::string&, int, TipoPublicacion, const std::string&, float) {
    return false; // stub
}

bool ControladorInmueble::altaCasa(const std::string& nicknamePropietario, const std::string& direccion, int numeroPuerta, int superficie, int anioConstruccion, bool esPH, TipoTecho techo) {
    Propietario* propietario = propietarios[nicknamePropietario];
    Casa* casa = new Casa(0, direccion, numeroPuerta, superficie, anioConstruccion, esPH, techo);
    propietario->agregarInmueble(casa);
    return true;
}

bool ControladorInmueble::altaApartamento(const std::string& nicknamePropietario, const std::string& direccion, int numeroPuerta, int superficie, int anioConstruccion, int piso, bool tieneAscensor, float gastosComunes) {
    Propietario* propietario = propietarios[nicknamePropietario];
    Apartamento* apartamento = new Apartamento(0, direccion, numeroPuerta, superficie, anioConstruccion, piso, tieneAscensor, gastosComunes);
    propietario->agregarInmueble(apartamento);
    return true;
}

DTInmueble ControladorInmueble::detalleInmueblePublicacion(int) {
    return DTInmueble(); // stub
}

DTInmueble ControladorInmueble::detalleInmueble(int) {
    return DTInmueble(); // stub
}
