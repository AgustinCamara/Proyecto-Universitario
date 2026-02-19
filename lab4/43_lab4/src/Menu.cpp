#include <iostream>
#include "../include/Menu.h"
#include "../include/CargaDatos.h"
#include "../include/TipoInmueble.h"
#include "../include/TipoPublicacion.h"
#include "../include/TipoTecho.h"
#include "../include/Factory.h"
#include "../include/DTApartamento.h"
#include "../include/DTCasa.h"
#include "../include/DTFecha.h"
#include "../include/Apartamento.h"
#include "../include/Casa.h"
#include "../include/DTInmueble.h"
#include "../include/DTInmuebleAdministrado.h"
#include "../include/DTInmuebleListado.h"
#include "../include/DTPublicacion.h"
#include "../include/DTUsuario.h"
#include <cstdlib>
#include <algorithm>
#include <string>
#include <set>
#include <limits>

void mostrarMenu() {
    std::cout << "=== Menu de Operaciones ===" << std::endl;
    std::cout << "1. Alta de Usuario" << std::endl;
    std::cout << "2. Alta de Publicacion" << std::endl;
    std::cout << "3. Consulta de Publicaciones" << std::endl;
    std::cout << "4. Eliminar Inmueble" << std::endl;
    std::cout << "5. Suscribirse a Notificaciones" << std::endl;
    std::cout << "6. Consulta de Notificaciones" << std::endl;
    std::cout << "7. Eliminar Suscripciones" << std::endl;
    std::cout << "8. Alta de Administracion de Propiedad" << std::endl;
    std::cout << "9. Cargar Datos" << std::endl;
    std::cout << "10. Ver fecha actual" << std::endl;
    std::cout << "11. Asignar fecha actual" << std::endl;
    std::cout << "0. Salir" << std::endl;
    std::cout << "Ingrese el codigo de operacion: ";
}

int obtenerOpcion() {
    int opcion;
    std::cin >> opcion;
    std::cin.ignore();
    return opcion;
}

void ejecutarOpcion(int opcion) {
    switch (opcion) {
        case 1:
            std::cout << " - ALTA DE USUARIO - " << std::endl;
            altaUsuario();
            break;
        case 2:
            std::cout << " - ALTA DE PUBLICACION - " << std::endl;
            altaPublicacion();
            break;
        case 3:
            std::cout << " - CONSULTA DE PUBLICACIONES - " << std::endl;
            consultaPublicaciones();
            break;
        case 4:
            std::cout << " - ELIMINAR INMUEBLE - " << std::endl;
            eliminarInmueble();
            break;
        case 5:
            std::cout << " - SUSCRIBIRSE A NOTIFICACIONES - " << std::endl;
            suscribirseNotificaciones();
            break;
        case 6:
            std::cout << " - CONSLTAR NOTIFICACIONES - " << std::endl;
            consultaNotificaciones();
            break;
        case 7:
            std::cout << " - ELIMINAR SUSCRIPCIONES - " << std::endl;
            eliminarSuscripciones();
            break;
        case 8:
            std::cout << " - ALTA ADMINISTRACION DE PROPIEDAD - " << std::endl;
            altaAdministracionPropiedad();
            break;
        case 9:
            std::cout << " - CARGAR DATOS - " << std::endl;
            cargarDatos();
            break;
        case 10:
            std::cout << " - VER FECHA ACTUAL - " << std::endl;
            verFechaActual();
            break;
        case 11:
            std::cout << " - ASIGNAR FECHA ACTUAL - " << std::endl;
            asignarFechaActual();
            break;
        case 0:
            std::cout << "Saliendo del programa..." << std::endl;
            exit(0);
        default:
            std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
    }
}

void altaUsuario(){

    Factory* factory = Factory::getInstance();

    std::cout << "Ingrese el tipo de usuario (0: Cliente, 1: Inmobiliaria, 2: Propietario): ";
    int tipoUsuario;
    std::cin >> tipoUsuario;
    std::cin.ignore();
    if (tipoUsuario < 0 || tipoUsuario > 2){
        std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
        return;
    }

    bool usuarioOk = false;
    
    std::string nickname;
    std::string contrasena;
    std::string nombre;
    std::string email;
    std::string apellido;
    std::string documento;
    std::string url;
    std::string telefono;
    std::string direccion;
    std::string cuentaBancaria;
    
    std::cout << "Nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Contrasena: ";
    std::getline(std::cin, contrasena);
    std::cout << "Nombre: ";
    std::getline(std::cin, nombre);
    std::cout << "Email: ";
    std::getline(std::cin, email);

    if (tipoUsuario == 0){
        std::cout << "Apellido: ";
        std::getline(std::cin, apellido);
        std::cout << "Documento: ";
        std::getline(std::cin, documento);
        usuarioOk = factory->getControladorUsuarios()->altaCliente(nickname, contrasena, nombre, email, apellido, documento);

    }else if (tipoUsuario == 1){
        std::cout << "Direccion: ";
        std::getline(std::cin, direccion);
        std::cout << "URL: ";
        std::getline(std::cin, url);
        std::cout << "Telefono: ";
        std::getline(std::cin, telefono);
        usuarioOk = factory->getControladorUsuarios()->altaInmobiliaria(nickname, contrasena, nombre, email, direccion, url, telefono);

    }else if (tipoUsuario == 2){
        std::cout << "Cuenta Bancaria: ";
        std::getline(std::cin, cuentaBancaria);
        std::cout << "Telefono: ";
        std::getline(std::cin, telefono);
        usuarioOk = factory->getControladorUsuarios()->altaPropietario(nickname, contrasena, nombre, email, cuentaBancaria, telefono);

    }
    if (usuarioOk){
        if (tipoUsuario == 1 || tipoUsuario == 2){
            int salir = 1;
            std::cout << "¿Quiere ingresar los datos relacionados? (1: Si, 0: No): ";
            std::cin >> salir;
            std::cin.ignore();
            std::string inmuebleDireccion;
            int numeroPuerta;
            int superficie;
            int anoConstruccion;
            while (salir != 0){
                if (tipoUsuario == 1){
                    std::cout << "Lista de Propietarios:\n";
                    std::set<DTUsuario*> propietarios = factory->getControladorUsuarios()->listarPropietarios();
                        for (const auto& propietario : propietarios) {
                        std::cout << "- Nickname: " << propietario->getNickname()
                        << ", Nombre: " << propietario->getNombre() << std::endl;
                    }   

                    std::cout << "Nickname propietario a representar: ";
                    std::string nicknamePropietario;
                    std::getline(std::cin, nicknamePropietario);
                    factory->getControladorUsuarios()->representarPropietario(nicknamePropietario);
                }else if (tipoUsuario == 2){
                    int tipoInmueble;
                    std::cout << "Indique el tipo de inmueble (1: Casa, 0: Apartamento): ";
                    std::cin >> tipoInmueble;
                    std::cin.ignore();
    
                    std::cout << "Direccion: ";
                    std::getline(std::cin, inmuebleDireccion);
                    std::cout << "Numero de Puerta: ";
                    std::cin >> numeroPuerta;
                    std::cin.ignore(); 
                    std::cout << "Superficie: ";
                    std::cin >> superficie;
                    std::cin.ignore();
                    std::cout << "Ano de Construccion: ";
                    std::cin >> anoConstruccion;
                    std::cin.ignore();

                    if (tipoInmueble == 1){
                        std::cout << "Es PH (1 para si, 0 para no): ";
                        int inEsPH;
                        std::cin >> inEsPH;
                        bool esPH = (inEsPH == 1);
                        std::cin.ignore();
                        std::cout << "Tipo de Techo (0: Liviano 1: A dos aguas, 2: Plano): ";
                        int inTipoTecho;
                        std::cin >> inTipoTecho;
                        std::cin.ignore();
                        TipoTecho techo = Liviano;
                        if(inTipoTecho == 1){
                            techo = A_dos_aguas;
                        }else if (inTipoTecho == 2){
                            techo = Plano;
                        }
                        factory->getControladorInmuebles()->altaCasa(inmuebleDireccion, numeroPuerta, superficie, anoConstruccion, esPH, techo);
                    }else{
                        int piso;
                        std::cout << "Piso: ";
                        std::cin >> piso;
                        std::cin.ignore();
                        std::cout << "Tiene Ascensor (1 para si, 0 para no): ";
                        int inTieneAscensor;
                        std::cin >> inTieneAscensor;
                        bool tieneAscensor = (inTieneAscensor == 1);
                        std::cin.ignore();
                        std::cout << "Gastos Comunes: ";
                        float gastosComunes;
                        std::cin >> gastosComunes;
                        std::cin.ignore();
                        factory->getControladorInmuebles()->altaApartamento(inmuebleDireccion, numeroPuerta, superficie, anoConstruccion, piso, tieneAscensor, gastosComunes);
                    }
                }
                std::cout << "¿Quiere seguir ingresando? (1: Si, 0: No): ";
                std::cin >> salir;
                std::cin.ignore();
            }
        }
        factory->getControladorUsuarios()->finalizarAltaUsuario();
    }else{
        std::cout << "Error al crear el usuario" << std::endl;
    }
}

void altaPublicacion(){

    Factory* factory = Factory::getInstance();

    std::cout << "Lista de Inmobiliarias:\n";
    IControladorUsuarios* controladorUsuarios = factory->getControladorUsuarios();
    IControladorInmuebles* controladorInmuebles = factory->getControladorInmuebles();
    std::set<DTUsuario*> inmobiliarias = factory->getControladorUsuarios()->listarInmobiliarias();
    for (const auto& inmobiliaria : inmobiliarias) {
        std::cout << "- Nickname: " << inmobiliaria->getNickname()
        << ", Nombre: " << inmobiliaria->getNombre() << std::endl;
    }
    std::cout << "Nickname de la inmobiliaria: ";
    std::string nicknameInmobiliaria;
    std::getline(std::cin, nicknameInmobiliaria);
    std::list<DTInmuebleAdministrado*> inmueblesAdmin = controladorUsuarios->listarInmueblesAdministrados(nicknameInmobiliaria);
    for (const auto& inmueble : inmueblesAdmin) {
        std::cout << "- Codigo: " << inmueble->getCodigo()
                << ", Direccion: " << inmueble->getDireccion()
                << ", Fecha comienzo: " << inmueble->getFechaComienzo() << std::endl;
    }
int codigoInmueble;
std::cout << "Inmueble: ";
 while (!(std::cin >> codigoInmueble)) {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    int inTipoPublicacion;
    std::cout << "Tipo de Publicacion: (1: Venta, 0: Alquiler) ";
    std::cin >> inTipoPublicacion;
    TipoPublicacion tipoPublicacion = Alquiler;
    if(inTipoPublicacion == 1){
        tipoPublicacion = Venta;
    }
    std::cin.ignore();
    std::cout << "Texto: ";
    std::string texto;
    std::getline(std::cin, texto);
    std::cout << "Precio: ";
    float precio;
    std::cin >> precio;
    std::cin.ignore();
    controladorInmuebles->altaPublicacion(nicknameInmobiliaria, codigoInmueble, tipoPublicacion, texto, precio);
}

void consultaPublicaciones() {
    Factory *factory = Factory::getInstance();
    IControladorInmuebles* controladorInmuebles = factory->getControladorInmuebles();
    IControladorUsuarios* controladorUsuarios = factory->getControladorUsuarios();

    int inTipoPublicacion;
    std::cout << "Tipo de Publicacion: (1: Venta, 0: Alquiler) ";
    std::cin >> inTipoPublicacion;
    TipoPublicacion tipoPublicacion = Alquiler;
    if (inTipoPublicacion == 1) {
        tipoPublicacion = Venta;
    }
    std::cin.ignore();

    std::cout << "Precio (Min): ";
    float precioMinimo;
    std::cin >> precioMinimo;
    std::cin.ignore();

    std::cout << "Precio (Max): ";
    float precioMaximo;
    std::cin >> precioMaximo;
    std::cin.ignore();

    int inTipoInmueble;
    std::cout << "Tipo de Inmueble: (1: Casa, 2: Apartamento, 0: Todos) ";
    std::cin >> inTipoInmueble;
    std::cin.ignore();

    TipoInmueble tipoInmueble = TipoInmueble::Todos;
    if (inTipoInmueble == 1) {
        tipoInmueble = TipoInmueble::Casa;
    } else if (inTipoInmueble == 2) {
        tipoInmueble = TipoInmueble::Apartamento;
    }

    std::cout << "Publicaciones encontradas:\n";
    std::set<DTPublicacion*> publicaciones = controladorInmuebles->listarPublicacion(tipoPublicacion, precioMinimo, precioMaximo, tipoInmueble);

    std::vector<DTPublicacion*> ordenadas(publicaciones.begin(), publicaciones.end());
    std::sort(ordenadas.begin(), ordenadas.end(), [](DTPublicacion* a, DTPublicacion* b) {
        return a->getCodigo() < b->getCodigo();
    });
    
    for (const auto& pub : ordenadas) {
        DTFecha* fecha = pub->getFecha();
        std::string nombreMostrado = pub->getInmobiliaria();
    Usuario* obj = controladorUsuarios->getUsuario(nombreMostrado);
    nombreMostrado = obj->getNombre();
        std::cout << "- Codigo: " << pub->getCodigo()
                  << ", fecha: " << fecha->toString()
                  << ", texto: " << pub->getTexto()
                  << ", precio: " << pub->getPrecio()
                  << ", inmobiliaria: " << nombreMostrado << std::endl;
    }

    int verDetalle;
    std::cout << "Ver detalle de la publicacion: (1: Si, 0: No)" ;
    std::cin >> verDetalle;
    std::cin.ignore();

    if (verDetalle == 1) {
        std::cout << "Codigo de publicacion: ";
        int codigoPublicacion;
        std::cin >> codigoPublicacion;
        std::cin.ignore();

        std::cout << "Detalle del inmueble:\n";

        DTInmueble* dtInm = controladorInmuebles->detalleInmueblePublicacion(codigoPublicacion);
        DTApartamento* dtApto = dynamic_cast<DTApartamento*>(dtInm);

        if (dtApto) {
            std::cout << "Codigo: " << dtInm->getCodigo()
                      << ", direccion: " << dtInm->getDireccion()
                      << ", nro. puerta: " << dtInm->getNumeroPuerta()
                      << ", superficie: " << dtInm->getSuperficie() << " m2"
                      << ", construccion: " << dtInm->getAnioConstruccion()
                      << ", piso: " << dtApto->getPiso()
                      << ", ascensor: " << (dtApto->getTieneAscensor() ? "Si" : "No")
                      << ", gastos comunes: " << dtApto->getGastosComunes()
                      << std::endl;
        } else if (DTCasa* dtCasa = dynamic_cast<DTCasa*>(dtInm)) {
            std::cout << "Codigo: " << dtInm->getCodigo()
                      << ", direccion: " << dtInm->getDireccion()
                      << ", nro. puerta: " << dtInm->getNumeroPuerta()
                      << ", superficie: " << dtInm->getSuperficie() << " m2"
                      << ", construccion: " << dtInm->getAnioConstruccion()
                      << ", PH: " << (dtCasa->getEsPH() ? "Si" : "No")
                      << ", Tipo de techo: ";
            switch (dtCasa->getTecho()) {
                case Liviano: std::cout << "Liviano"; break;
                case A_dos_aguas: std::cout << "A dos aguas"; break;
                case Plano: std::cout << "Plano"; break;
            }
            std::cout << std::endl;
        }
    }
}




void eliminarInmueble() {
    Factory* factory = Factory::getInstance();
    std::cout << "Listado de inmuebles:\n";
    std::list<DTInmuebleListado*> inmuebles = factory->getControladorInmuebles()->listarInmuebles();
    for (const auto& inmueble : inmuebles) {
        std::cout << "- Codigo: " << inmueble->getCodigo()
                  << ", direccion: " << inmueble->getDireccion()
                  << ", propietario: " << inmueble->getPropietario() << std::endl;
    }
    std::cout << "Codigo del inmueble a eliminar: ";
    int codigoInmueble;
    std::cin >> codigoInmueble;
    std::cin.ignore();
    std::cout << "Detalle del inmueble:\n";

    IControladorInmuebles* controladorInmuebles = factory->getControladorInmuebles();

    Inmueble* inm = controladorInmuebles->obtenerInmueble(codigoInmueble);
    if (!inm) {
        std::cout << "Inmueble no encontrado." << std::endl;
        return;
    }

    DTInmueble* dto = inm->getDTInmueble();

    if (DTApartamento* dtApto = dynamic_cast<DTApartamento*>(dto)) {
        std::cout << "Codigo: " << dtApto->getCodigo()
                  << ", direccion: " << dtApto->getDireccion()
                  << ", nro. puerta: " << dtApto->getNumeroPuerta()
                  << ", superficie: " << dtApto->getSuperficie() << " m2"
                  << ", construccion: " << dtApto->getAnioConstruccion()
                  << ", piso: " << dtApto->getPiso()
                  << ", ascensor: " << (dtApto->getTieneAscensor() ? "Si" : "No")
                  << ", gastos comunes: " << dtApto->getGastosComunes()
                  << std::endl;
    } 
    else if (DTCasa* dtCasa = dynamic_cast<DTCasa*>(dto)) {
        std::cout << "Codigo: " << dtCasa->getCodigo()
                  << ", direccion: " << dtCasa->getDireccion()
                  << ", nro. puerta: " << dtCasa->getNumeroPuerta()
                  << ", superficie: " << dtCasa->getSuperficie() << " m2"
                  << ", construccion: " << dtCasa->getAnioConstruccion()
                  << ", PH: " << (dtCasa->getEsPH() ? "Si" : "No")
                  << ", Tipo de techo: ";
        switch (dtCasa->getTecho()) {
            case Liviano: std::cout << "Liviano"; break;
            case A_dos_aguas: std::cout << "A dos aguas"; break;
            case Plano: std::cout << "Plano"; break;
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "Tipo de inmueble desconocido." << std::endl;
    }

    int deseaEliminar;
    std::cout << "¿Desea eliminar?: (1: Si, 0: No) ";
    std::cin >> deseaEliminar;
    std::cin.ignore();
    if (deseaEliminar == 1){
        factory->getControladorInmuebles()->eliminarInmueble(codigoInmueble);
    }
}

void suscribirseNotificaciones(){
    Factory *factory = Factory::getInstance();
    std::cout << "Nickname del cliente o propietario: ";
    std::string nicknameCliente;
    std::getline(std::cin, nicknameCliente);
    std::set<DTUsuario*> inmobiliarias = factory->getInstance()->getControladorUsuarios()->listarInmobiliariasNoSuscripto(nicknameCliente);
    std::set<DTUsuario*>::iterator iter;
    for (iter = inmobiliarias.begin(); iter != inmobiliarias.end(); ++iter) {
        std::cout << "- Nickname: " << (*iter)->getNickname() << ", - Nombre: " << (*iter)->getNombre() << std::endl;

}
    std::cout << "Nickname de la inmobiliaria: ";
    std::string nicknameInmobiliaria;
    std::getline(std::cin, nicknameInmobiliaria);
    bool suscripcionOk = factory->getInstance()->getControladorUsuarios()->suscribirAInmobiliaria(nicknameCliente, nicknameInmobiliaria);
    if (suscripcionOk) std::cout << "Suscripción exitosa" << std::endl;
    else std::cout << "error" << std::endl;
    factory->getInstance()->getControladorUsuarios()->finalizarSuscripcion();
}

void consultaNotificaciones() {
    Factory *factory = Factory::getInstance();

    std::cout << "Nickname del cliente o propietario: ";
    std::string nicknameUsuario;
    std::getline(std::cin, nicknameUsuario);

    std::set<DTNotificacion*> notificaciones = factory->getInstance()->getControladorUsuarios()->listarNotificaciones(nicknameUsuario);

    for (auto it = notificaciones.begin(); it != notificaciones.end(); ++it) {
        DTNotificacion* notif = *it;
        std::cout << "- Nickname: " << notif->getNickname()
                  << ", mensaje: " << notif->getMensaje()
                  << ", código: " << notif->getCodigo();

        std::cout << ", Tipo Inmueble: ";
        switch (notif->getTipoInmueble()) {
            case TipoInmueble::Casa:
                std::cout << "Casa";
                break;
            case TipoInmueble::Apartamento:
                std::cout << "Apartamento";
                break;
            case TipoInmueble::Todos:
                std::cout << "Todos";
                break;
        }

        std::cout << ", Tipo Publicación: ";
        switch (notif->getTipoPublicacion()) {
            case TipoPublicacion::Venta:
                std::cout << "Venta";
                break;
            case TipoPublicacion::Alquiler:
                std::cout << "Alquiler";
                break;
        }

        std::cout << std::endl;
    }

    factory->getInstance()->getControladorUsuarios()->eliminarNotificaciones(nicknameUsuario);
    factory->getInstance()->getControladorUsuarios()->finalizarConsulta();
}

void eliminarSuscripciones(){
    Factory *factory = Factory::getInstance();
    std::cout << "Nickname del cliente: ";
    std::string nicknameCliente;
    std::getline(std::cin, nicknameCliente);

    std::set<DTUsuario*> inmobiliariasSuscriptas = factory->getControladorUsuarios()->listarInmobiliariasSuscripto(nicknameCliente);

    if (inmobiliariasSuscriptas.empty()) {
        std::cout << "No estás suscripto a ninguna inmobiliaria." << std::endl;
        return;
    }

    std::cout << "Inmobiliarias suscriptas: " << std::endl;
    for (const DTUsuario* inmobiliaria : inmobiliariasSuscriptas) {
        std::cout << "- Nickname: " << inmobiliaria->getNickname() << ", Nombre: " << inmobiliaria->getNombre() << std::endl;
    }

    std::cout << "Nickname de la inmobiliaria a desuscribirse: ";
    std::string nicknameInmobiliaria;
    std::getline(std::cin, nicknameInmobiliaria);

    bool bajaOk = factory->getControladorUsuarios()->desuscribirDeInmobiliaria(nicknameCliente, nicknameInmobiliaria);
    if (bajaOk) std::cout << "Desuscripción realizada correctamente." << std::endl;
    else std::cout << "Error al desuscribirse." << std::endl;

    factory->getControladorUsuarios()->finalizarSuscripcion();

}

void altaAdministracionPropiedad(){
    Factory* factory = Factory::getInstance();

    std::cout << "Lista de Inmobiliarias:\n";
    std::set<DTUsuario*> inmobiliarias = factory->getControladorUsuarios()->listarInmobiliarias();
    for (const auto& inmobiliaria : inmobiliarias) {
        std::cout << "- Nickname: " << inmobiliaria->getNickname()
        << ", Nombre: " << inmobiliaria->getNombre() << std::endl;
    }
    std::cout << "Nickname de la inmobiliaria: ";
    std::string nicknameInmobiliaria;
    std::getline(std::cin, nicknameInmobiliaria);
    std::set<DTInmuebleListado*> inmueblesNoAdministrados = factory->getControladorUsuarios()->listarInmueblesNoAdministradosInmobiliaria(nicknameInmobiliaria);
    std::cout << inmueblesNoAdministrados.size() << " inmuebles no administrados encontrados:\n";
    if (!inmueblesNoAdministrados.empty()) {
        for (const auto& inmueble : inmueblesNoAdministrados) {
             std::cout << "- Codigo: " << inmueble->getCodigo()
                       << ", direccion: " << inmueble->getDireccion()
                       << ", propietario: " << inmueble->getPropietario() << std::endl;
        } 
        std::cout << "Codigo del inmueble a administrar: ";
        int codigoInmueble;
        std::cin >> codigoInmueble;
        std::cin.ignore();
        factory->getControladorUsuarios()->altaAdministraPropiedad(nicknameInmobiliaria, codigoInmueble);
    }
}

void cargarDatos(){
    CargaDatos::getInstance();
}

 void verFechaActual(){
    Factory* factory = Factory::getInstance();
    IControladorFechaActual* cfecha = factory->getControladorFechaActual();
    DTFecha* fechaActual = cfecha->getFechaActual();
    std::cout << "Fecha Actual: " << fechaActual;
    delete fechaActual;
 }

 void asignarFechaActual(){
    Factory* factory = Factory::getInstance();
    IControladorFechaActual* cfecha = factory->getControladorFechaActual();
    std::cout << "dia: ";
    int dia;
    std::cin >> dia;
    std::cin.ignore();
    std::cout << "mes: ";
    int mes;
    std::cin >> mes;
    std::cin.ignore();
    std::cout << "ano: ";
    int ano;
    std::cin >> ano;
    std::cin.ignore();
    cfecha->setNewFechaActual(dia, mes, ano);
 }
