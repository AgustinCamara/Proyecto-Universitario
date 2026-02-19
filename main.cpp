#include <iostream>
#include <list>
#include <map>
#include "ArticuloRevista.h"
#include "DTFecha.h"
#include "Investigador.h"
#include "Libro.h"
#include "PaginaWeb.h"
#include "Publicacion.h"

std::list<Publicacion*> publicaciones;
std::map<std::string, Publicacion*> map_publicaciones;

std::list<Investigador*> investigadores;
std::map<std::string, Investigador*> map_investigadores;
 
void coleccion_guardarPublicacion(Publicacion* pub){
	publicaciones.push_back(pub);
	std::pair<std::string, Publicacion*> entry(pub->getDOI(), pub);
    map_publicaciones.insert(entry);
}
void coleccion_eliminarPublicacion(Publicacion* pub) {
    if (!pub) return;
    publicaciones.remove(pub);
    map_publicaciones.erase(pub->getDOI());
    for (std::list<Investigador*>::iterator it = investigadores.begin();
        it != investigadores.end(); ++it) {
            (*it)->removerPublicacion(pub);
        } 
        delete pub;
}

void coleccion_guardarInvestigador(Investigador* inv){  
	investigadores.push_back(inv);
	std::pair<std::string, Investigador*> entry(inv->getORCID(), inv);
    map_investigadores.insert(entry);
}

Investigador* coleccion_getInvestigador(std::string ORCID){
	return map_investigadores[ORCID];
}

Publicacion* coleccion_getPublicacion(std::string DOI){
	return map_publicaciones[DOI];
}

void parte_a(){
	// creo un nuejo objeto articuloRevista
	ArticuloRevista* art1 = new ArticuloRevista(
		"10.1234/abc123",
		"Fundamentos de POO",
		DTFecha(15, 5, 2023),
		"Programación Avanzada",
		"Introduccion a los principios fundamentales de la programacion orientada a objetos, explicando sus conceptos clave como clases, objetos, herencia y polimorfismo"
	);
	// lo guardo en la coleccion
	coleccion_guardarPublicacion(art1);
		
	ArticuloRevista* art2 = new ArticuloRevista(
		"10.4567/jkl012",
		"Utilidad de diagramas UML",
		DTFecha(10, 2, 2024),
		"Modelado de Software",
		"Ejercicio empirico de como los diagramas UML pueden ayudar en el proceso y documentacion de software, cubriendo los tipos mas importantes utilizados, como clases."
	);
	coleccion_guardarPublicacion(art2);
	std::cout << std::endl;
}

void parte_b(){
	//hago el set con las palabras claves
	std::set<std::string> kW1;
	kW1.insert("Diseno");
	kW1.insert("OOP");
	kW1.insert("Class");

	//creo el objeto libro
	Libro* lbr1 = new Libro(
		"10.2345/def456",
		"Patrones de Diseno en c++", 
		DTFecha(20, 8 ,2022), 
		"Software Design",
		kW1
	);

	//lo agrego a la coleccion
	coleccion_guardarPublicacion(lbr1);

	std::set<std::string> kW2;
	kW2.insert("Diagramas");
	kW2.insert("UML");
	kW2.insert("Software");
	kW2.insert("Modelado");

	Libro* lbr2 = new Libro(
		"10.5678/mno345", 
		"Guia de UML",  
		DTFecha(20, 8 ,2022),  
		"IEEE", 
		kW2 
	);
	coleccion_guardarPublicacion(lbr2);
	std::cout << std::endl;
}

void parte_c(){
	//creo el objeto paginaWeb
	PaginaWeb* pagW = new PaginaWeb(
		"10.3456/ghi789",  
		"Diagramas para Principiantes",  
		DTFecha(20, 10, 2024),  
		"www.umlparaprincipiantes.com",  
		"En esta pagina web se presenta una gui completa sobre los diagramas UML, abordando los diagramas de casos de uso, de clases, de secuencia y de actividades."
	);

	//lo agrego a la coleccion
	coleccion_guardarPublicacion(pagW);
	std::cout << std::endl;
}

void parte_d(){
	if (publicaciones.empty()){
        std::cout << "No hay publicaciones registradas." << std::endl;
    } else{
        std::cout << "Se encontraron " << publicaciones.size() << " publicaciones:" << std::endl;
        for (std::list<Publicacion*>::iterator it = publicaciones.begin(); it != publicaciones.end(); ++it){
            std::cout << (*it)->getDT() << std::endl;
        }
    }
	std::cout << std::endl;
}

void parte_e(){
	//creo el objeto investigador
	Investigador* inves1 = new Investigador(
		"0000-0003-1234-5678", 
		"Carla Oliveri",
		"Universidad de la Republica" 
	);
	//lo agrego a la coleccion
	coleccion_guardarInvestigador(inves1);

	Investigador* inves2 = new Investigador(
		"0000-0001-8765-4321", 
		"Alberto Santos", 
		"Instituto Tecnico"
	);
	coleccion_guardarInvestigador(inves2);
	std::cout << std::endl;
}

void parte_f(){
	for (std::list<Investigador*>::const_iterator it = investigadores.begin(); it != investigadores.end(); ++it) {
        std::cout << (*it)->toString() <<  std::endl;
    }
std::cout << std::endl;
}

void parte_g(){
	Investigador* carla = coleccion_getInvestigador("0000-0003-1234-5678");
	Investigador* alberto = coleccion_getInvestigador("0000-0001-8765-4321");
	carla->agregarPublicacion(coleccion_getPublicacion("10.1234/abc123"));
	carla->agregarPublicacion(coleccion_getPublicacion("10.4567/jkl012"));
	carla->agregarPublicacion(coleccion_getPublicacion("10.5678/mno345"));
	carla->agregarPublicacion(coleccion_getPublicacion("10.3456/ghi789"));
	alberto->agregarPublicacion(coleccion_getPublicacion("10.1234/abc123"));
	alberto->agregarPublicacion(coleccion_getPublicacion("10.2345/def456"));
	alberto->agregarPublicacion(coleccion_getPublicacion("10.4567/jkl012"));
	std::cout << std::endl;
}

void parte_h(){
	std::map<std::string, Investigador*>::const_iterator invC = map_investigadores.find("0000-0003-1234-5678");
	std::vector<std::string> resultados = invC->second->listarPublicaciones(DTFecha(10, 12, 2023), "UML");
	for (std::vector<std::string>::const_iterator it = resultados.begin(); it != resultados.end(); ++it){
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;
}

void parte_i(){
	Publicacion* p = coleccion_getPublicacion("10.4567/jkl012");
	std::string doi = p->getDOI();
	coleccion_eliminarPublicacion(p); 
	std::cout << std::endl;
}

void parte_j(){
	std::map<std::string, Investigador*>::const_iterator invC = map_investigadores.find("0000-0003-1234-5678");
	std::vector<std::string> resultados = invC->second->listarPublicaciones(DTFecha(1, 1, 2020), "UML");
	for (std::vector<std::string>::const_iterator it = resultados.begin(); it != resultados.end(); ++it){
		std::cout << *it << std::endl;
	}
std::cout << std::endl;
}

void parte_k(){
	parte_d();
	std::cout << std::endl;
}

void cleanUp() {
    // libero publicaciones
    for (std::list<Publicacion*>::const_iterator it = publicaciones.begin(); it != publicaciones.end(); ++it) {
        delete *it;
    }
    publicaciones.clear();

    // libero investigadores
    for (std::list<Investigador*>::const_iterator it = investigadores.begin(); it != investigadores.end(); ++it) {
        delete *it; 
    }
    investigadores.clear();

    // limpio los mapas
    map_publicaciones.clear();
    map_investigadores.clear();
}

int main() {
	std::cout << "parte_a" <<  std::endl;
	parte_a();
	std::cout << "parte_b" <<  std::endl;
	parte_b();
	std::cout << "parte_c" <<  std::endl;
	parte_c();
	std::cout << "parte_d" <<  std::endl;
	parte_d();
	std::cout << "parte_e" <<  std::endl;
	parte_e();
	std::cout << "parte_f" <<  std::endl;
	parte_f();
	std::cout << "parte_g" <<  std::endl;
	parte_g();
	std::cout << "parte_h" <<  std::endl;
	parte_h();
	std::cout << "parte_i" <<  std::endl;
	parte_i();
	std::cout << "parte_j" <<  std::endl;
	parte_j();
	std::cout << "parte_k" <<  std::endl;
	parte_k();
	std::cout << "cleanUp" <<  std::endl;
	cleanUp();
	std::cout << "fin" <<  std::endl;

	return 0;
}
