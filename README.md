# P4 — Laboratorios de Programación 4

> Proyecto universitario de Programación 4 (Grupo 43) que abarca múltiples laboratorios progresivos en C++, aplicando principios de diseño orientado a objetos, patrones de diseño y buenas prácticas de ingeniería de software.

---

## Descripción

Este repositorio contiene el conjunto de entregas del curso **Programación 4**, donde se modelan y desarrollan sistemas de gestión aplicando conceptos avanzados de OOP en C++. El proyecto se divide en dos dominios principales:

### Sistema de Gestión de Publicaciones Académicas (Lab 0)

Sistema que modela publicaciones académicas e investigadores. Permite crear, listar, asociar, filtrar y eliminar publicaciones con manejo correcto de memoria.

- **Publicaciones:** Artículos de revista, libros y páginas web, cada uno con atributos específicos.
- **Investigadores:** Identificados por ORCID, vinculados a publicaciones mediante relación muchos-a-muchos.
- **Operaciones:** Creación con fecha, asociación investigador–publicación, búsqueda por palabra clave, filtrado por rango de fechas y eliminación en cascada.

### Sistema de Gestión Inmobiliaria (Lab 4)

Aplicación de consola interactiva para la gestión de propiedades inmobiliarias, usuarios y publicaciones de venta/alquiler.

- **Usuarios:** Clientes, propietarios e inmobiliarias, cada uno con roles y permisos diferenciados.
- **Inmuebles:** Casas y apartamentos con atributos específicos (tipo de techo, piso, ascensor, gastos comunes, etc.).
- **Publicaciones:** Listados de venta o alquiler vinculados a inmuebles, con estados activos/inactivos.
- **Notificaciones:** Sistema de suscripción que alerta a clientes y propietarios sobre cambios en publicaciones.
- **Administración:** Relación inmobiliaria–inmueble para gestión delegada de propiedades.

---

## Patrones de Diseño Implementados

| Patrón | Aplicación |
|---|---|
| **Singleton** | `Factory`, controladores (`ControladorInmuebles`, `ControladorUsuarios`, `ControladorFechaActual`) — instancia única con `getInstance()` |
| **Abstract Factory** | `Factory` retorna interfaces (`IControladorX`), desacoplando la creación de controladores concretos |
| **Observer** | `Inmobiliaria` actúa como sujeto observable; `Cliente` y `Propietario` implementan `ISuscrito` y reciben notificaciones |
| **DTO (Data Transfer Object)** | Clases `DT*` (`DTInmueble`, `DTUsuario`, `DTPublicacion`, etc.) para transferir datos entre capas sin exponer el modelo |
| **Controller (GRASP)** | Controladores que encapsulan la lógica de casos de uso detrás de interfaces |
| **Polimorfismo / Strategy** | Jerarquías `Publicacion`, `Inmueble → Casa/Apartamento` y `Usuario → Cliente/Propietario/Inmobiliaria` con métodos virtuales |

---

## Estructura del Proyecto

```
P4-MONITOREO-main/
├── main.cpp                    # Lab 0 — Publicaciones académicas
├── Makefile
├── include/                    # Headers Lab 0
│   ├── Publicacion.h
│   ├── ArticuloRevista.h
│   ├── Libro.h
│   ├── PaginaWeb.h
│   ├── Investigador.h
│   ├── DTFecha.h
│   └── DTRefer.h
├── src/                        # Implementaciones Lab 0
│   ├── Publicacion.cpp
│   ├── ArticuloRevista.cpp
│   ├── Libro.cpp
│   ├── PaginaWeb.cpp
│   ├── Investigador.cpp
│   ├── DTFecha.cpp
│   └── DTRefer.cpp
├── lab1/                       # Modelo de dominio (Draw.io)
├── lab2/                       # Modelo de casos de uso (Draw.io)
└── lab4/
    ├── 43_lab4/                # Sistema inmobiliario — versión principal
    │   ├── main
    │   ├── Makefile
    │   ├── include/            # Headers (usuarios, inmuebles, controladores, DTOs)
    │   └── src/                # Implementaciones completas
    └── lab4_2025/              # Sistema inmobiliario — versión refactorizada
        ├── main.cpp
        ├── Makefile            # Incluye ejecución con Valgrind
        ├── include/
        └── src/
```

---

## Tecnologías y Herramientas

- **Lenguaje:** C++ (C++98 / C++11)
- **Compilador:** g++
- **Build system:** GNU Make
- **Detección de memory leaks:** Valgrind
- **Contenedores STL:** `map`, `set`, `list`, `vector`, `string`
- **Modelado UML:** Draw.io (diagramas de dominio y casos de uso)

---

## Compilación y Ejecución

### Lab 0 — Publicaciones Académicas

```bash
make          # Compila el ejecutable 'lab0'
./lab0        # Ejecuta las partes a–k de forma secuencial
make clean    # Limpia archivos generados
```

### Lab 4 — Sistema Inmobiliario

```bash
cd lab4/43_lab4
make          # Compila el ejecutable 'main'
./main        # Aplicación interactiva por menú de consola
make clean    # Limpia archivos generados
```

### Lab 4 (2025) — Versión Refactorizada

```bash
cd lab4/lab4_2025
make          # Compila y ejecuta análisis con Valgrind
./main        # Aplicación interactiva por menú de consola
make clean    # Limpia archivos generados
```

---

## Diagrama de Clases Simplificado

### Dominio de Publicaciones (Lab 0)

```
Publicacion (abstracta)
  ├── ArticuloRevista
  ├── Libro
  └── PaginaWeb

Investigador ◆——▷ Publicacion  (muchos a muchos)
```

### Dominio Inmobiliario (Lab 4)

```
Usuario (abstracta)
  ├── Cliente         ──implements──▷ ISuscrito
  ├── Propietario     ──implements──▷ ISuscrito
  └── Inmobiliaria    ──notifica──▷ ISuscrito (Observer)

Inmueble (abstracta)
  ├── Casa
  └── Apartamento

AdministraPropiedad ──vincula──▷ Inmobiliaria ↔ Inmueble
Publicacion ──pertenece──▷ AdministraPropiedad
```

---

## Conceptos Clave Demostrados

- Diseño orientado a objetos con herencia, polimorfismo y clases abstractas
- Separación de responsabilidades con controladores e interfaces
- Manejo de memoria dinámica en C++ con `new`/`delete` y validación con Valgrind
- Patrones de diseño GoF (Singleton, Observer, Abstract Factory)
- Patrones GRASP (Controller, Creator, Expert)
- Uso de DTOs para transferencia segura de datos entre capas
- Modelado UML previo a la implementación (diagramas de dominio y casos de uso)

---

## Autor

**Agustin Camara** — Grupo 43, Programación 4

---

*Proyecto académico desarrollado como parte del curso de Programación 4.*
