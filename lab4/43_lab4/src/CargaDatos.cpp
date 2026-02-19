#include "../include/CargaDatos.h"
#include "../include/ControladorUsuarios.h"
#include "../include/Factory.h"
#include <cstddef>

CargaDatos* CargaDatos::instance = NULL;

CargaDatos::CargaDatos() {
    IControladorFechaActual* controladorFechaActual = Factory::getInstance()->getControladorFechaActual();
    IControladorUsuarios* controladorUsuarios  = Factory::getInstance()->getControladorUsuarios();
    IControladorInmuebles* controladorInmuebles  = Factory::getInstance()->getControladorInmuebles();

controladorUsuarios->altaCliente("luisito23", "qweasd12", "Luis", "Pérez", "46859342", "luisito23@gmail.com");
controladorUsuarios->altaCliente("anarojo88", "claveAna1", "Ana", "Rojo", "31287465", "anarojo88@hotmail.com");   
controladorUsuarios->altaPropietario("marcelom", "banco123", "Marcelo", "marcelo.m@gmail.com", "123456789012", "099876543");
controladorInmuebles->altaCasa("Av. Rivera", 1011, 120, 1995, true, Plano);
controladorInmuebles->altaApartamento("Av. Brasil", 2031, 75, 1980, 5, true, 3500);
controladorUsuarios->altaPropietario("robertarce", "pass456", "Roberto", "roberto.a@yahoo.com", "987654321001", "091234567");
controladorInmuebles->altaCasa("Camino Maldonado", 1540, 95, 1988, false, Plano);
controladorUsuarios->altaPropietario("soledadf", "sole789", "Soledad", "soledad.f@gmail.com", "654321987654", "092345678");
controladorInmuebles->altaApartamento("Colonia", 1542, 60, 1978, 12, true, 2800);
controladorUsuarios->altaPropietario("martagal", "martA01", "Marta", "marta.galvez@outlook.com", "321098765432","098765432");
controladorInmuebles->altaCasa("Juan Paullier", 801, 110, 2000, true, Liviano);
controladorUsuarios->altaPropietario("jorge88", "jorgepass88", "Jorge", "jorge.rivera@uy.com", "890123456789", "097654321");
controladorInmuebles->altaApartamento("Bulevar Artigas", 871, 68, 2002, 3, false, 2200);
controladorInmuebles->altaApartamento("Sarmiento", 1476, 80, 2008, 6, true, 3100);
controladorInmuebles->altaCasa("Cno. Carrasco", 1576, 140, 2007, true, Plano);
controladorUsuarios->altaInmobiliaria("casasur123", "casasur99", "Casa Sur", "contacto@casasur.com","Canelones 2345","https://casasur.com.uy","24012345");
controladorUsuarios->representarPropietario("marcelom");
controladorUsuarios->representarPropietario("jorge88");
controladorUsuarios->altaInmobiliaria("idealhome", "home2025", "IHome", "info@idealhome.uy","Av. Italia 4567","https://idealhome.uy", "099123456");
controladorUsuarios->representarPropietario("marcelom");
controladorUsuarios->representarPropietario("jorge88");
controladorUsuarios->representarPropietario("martagal");
controladorUsuarios->altaInmobiliaria("vivaurbana", "viva4567", "Viva Urbana", "contacto@vivaurbana.com", "18 de Julio 7890","https://vivaurbana.com","29109876");
controladorUsuarios->representarPropietario("jorge88");
controladorUsuarios->representarPropietario("robertarce");
controladorUsuarios->representarPropietario("soledadf");
controladorFechaActual->setNewFechaActual(12,12,2015);
controladorUsuarios->altaAdministraPropiedad("casasur123", 2);
controladorFechaActual->setNewFechaActual(25,9,2023);
controladorUsuarios->altaAdministraPropiedad("idealhome",1);
controladorFechaActual->setNewFechaActual(20,7,2022);
controladorUsuarios->altaAdministraPropiedad("vivaurbana",3);
controladorFechaActual->setNewFechaActual(1,1,2022);
controladorUsuarios->altaAdministraPropiedad("vivaurbana",4);
controladorFechaActual->setNewFechaActual(3,7,2010);
controladorUsuarios->altaAdministraPropiedad("idealhome",5);
controladorFechaActual->setNewFechaActual(4,11,2019);
controladorUsuarios->altaAdministraPropiedad("casasur123",6);
controladorFechaActual->setNewFechaActual(19,5,2020);
controladorUsuarios->altaAdministraPropiedad("vivaurbana",6);
controladorFechaActual->setNewFechaActual(19,7,2024);
controladorUsuarios->altaAdministraPropiedad("idealhome",6);
controladorFechaActual->setNewFechaActual(18,9,2023);
controladorUsuarios->altaAdministraPropiedad("idealhome",7);
controladorFechaActual->setNewFechaActual(19,5,2022);
controladorUsuarios->altaAdministraPropiedad("vivaurbana",8);
controladorFechaActual->setNewFechaActual(9,10,2011);
controladorInmuebles->altaPublicacion("idealhome",5, Venta,"Casa al fondo Juan Paullier con 110 m fondo y techo liviano.", 47000);
controladorFechaActual->setNewFechaActual(15,1,2016);
controladorInmuebles->altaPublicacion("casasur123",2, Alquiler,"Oportunidad en Av. Brasil: apartamento de 75 m piso 5 con ascensor.", 28000);
controladorFechaActual->setNewFechaActual(5,3,2019);
controladorInmuebles->altaPublicacion("casasur123", 2, Alquiler, "Apartamento luminoso en Av. Brasil piso alto con excelentes servicios.", 29500);
controladorFechaActual->setNewFechaActual(3,4,2019);
controladorInmuebles->altaPublicacion("idealhome", 5, Alquiler, "Casa ideal para familia en Juan Paullier barrio tranquilo.", 38500);
controladorFechaActual->setNewFechaActual(12,12,2019);
controladorInmuebles->altaPublicacion("casasur123", 6, Venta, "Apartamento en Bulevar Artigas piso 3 muy luminoso y moderno.", 37500);
controladorFechaActual->setNewFechaActual(12,6,2020);
controladorInmuebles->altaPublicacion("casasur123", 2, Venta, "Excelente apartamento en Av. Brasil con 75 m ideal para reforma.", 39000);
controladorFechaActual->setNewFechaActual(20,7,2020);
controladorInmuebles->altaPublicacion("vivaurbana", 6, Alquiler, "Apartamento 68 m en Bulevar Artigas tercer piso sin ascensor.", 23000);
controladorFechaActual->setNewFechaActual(4,3,2022);
controladorInmuebles->altaPublicacion("vivaurbana", 6, Alquiler, "Apartamento con ascensor en Colonia 1542 piso 12 excelente conectividad.", 26000);
controladorFechaActual->setNewFechaActual(12,9,2022);
controladorInmuebles->altaPublicacion("vivaurbana", 4, Venta,"Casa excelente en Camino Maldonado de 95 m con patio al fondo.", 27000);
controladorFechaActual->setNewFechaActual(1,10,2023);
controladorInmuebles->altaPublicacion("idealhome", 1, Venta, "Casa en Av. Rivera de 120 m con techo plano ideal para familia.", 520000);
controladorFechaActual->setNewFechaActual(18,10,2023);
controladorInmuebles->altaPublicacion("idealhome", 7, Alquiler, "Apartamento amplio en Sarmiento 1476 piso 6 con ascensor.", 32000);
controladorFechaActual->setNewFechaActual(19,10,2023);
controladorInmuebles->altaPublicacion("idealhome", 7, Venta,"Apartamento de 80 m en Sarmiento excelente estado y vista.", 455000);
controladorFechaActual->setNewFechaActual(20,11,2023);
controladorInmuebles->altaPublicacion("idealhome", 6, Alquiler, "Apartamento con gran vista a la rambla", 31000);
controladorFechaActual->setNewFechaActual(20,11,2023);
controladorInmuebles->altaPublicacion("idealhome", 7, Venta, "Apartamento en excelentes condiciones de 80 m", 450000);
controladorFechaActual->setNewFechaActual(8,3,2024);
controladorInmuebles->altaPublicacion("vivaurbana", 3, Venta, "Venta de casa en Camino Maldonado 95 m bien distribuidos.", 430000);
controladorFechaActual->setNewFechaActual(5,5,2024);
controladorInmuebles->altaPublicacion("idealhome", 7, Alquiler, "Alquiler en Sarmiento 80 m piso alto con excelentes terminaciones.", 33000);
controladorFechaActual->setNewFechaActual(1,8,2024);
controladorInmuebles->altaPublicacion("idealhome", 6, Venta,"A estrenar en Bulevar Artigas 871 apartamento moderno.", 400000);
controladorUsuarios->suscribirAInmobiliaria("luisito23","casasur123");
controladorUsuarios->suscribirAInmobiliaria("luisito23","idealhome");
controladorUsuarios->suscribirAInmobiliaria("anarojo88","casasur123");  
controladorUsuarios->suscribirAInmobiliaria("anarojo88","idealhome");
controladorUsuarios->suscribirAInmobiliaria("anarojo88","vivaurbana");
controladorUsuarios->suscribirAInmobiliaria("marcelom","idealhome");
controladorUsuarios->suscribirAInmobiliaria("robertarce","idealhome");
controladorUsuarios->suscribirAInmobiliaria("soledadf","vivaurbana");
controladorUsuarios->suscribirAInmobiliaria("martagal","vivaurbana");
controladorUsuarios->suscribirAInmobiliaria("jorge88","casasur123");  
controladorUsuarios->suscribirAInmobiliaria("jorge88","idealhome");
controladorUsuarios->suscribirAInmobiliaria("jorge88","vivaurbana");
controladorFechaActual->setNewFechaActual(23,6,2025);
}

CargaDatos* CargaDatos::getInstance() {
    if (instance == 0) {
        instance = new CargaDatos();
    }
    return instance;
}