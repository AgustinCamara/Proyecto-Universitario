# P4 — Programación 4 Lab

> University project for Programación 4 covering multiple progressive labs in C++, applying object-oriented design principles, design patterns, and software engineering best practices.

---

## Description

This repository contains the set of submissions for the **Programación 4** course, where management systems are modeled and developed using advanced OOP concepts in C++. The project is divided into two main domains:

### Academic Publications Management System (Lab 0)

System that models academic publications and researchers. Allows creating, listing, associating, filtering, and deleting publications with proper memory management.

- **Publications:** Journal articles, books, and web pages, each with specific attributes.
- **Researchers:** Identified by ORCID, linked to publications through a many-to-many relationship.
- **Operations:** Creation with date, researcher–publication association, keyword search, date range filtering, and cascading deletion.

### Real Estate Management System (Lab 4)

Interactive console application for managing real estate properties, users, and sale/rental listings.

- **Users:** Clients, owners, and real estate agencies, each with distinct roles and permissions.
- **Properties:** Houses and apartments with specific attributes (roof type, floor, elevator, common expenses, etc.).
- **Listings:** Sale or rental listings linked to properties, with active/inactive states.
- **Notifications:** Subscription system that alerts clients and owners about changes in listings.
- **Administration:** Real estate–property relationship for delegated property management.

---

## Implemented Design Patterns

| Pattern | Application |
|---|---|
| **Singleton** | `Factory`, controllers (`ControladorInmuebles`, `ControladorUsuarios`, `ControladorFechaActual`) — single instance with `getInstance()` |
| **Abstract Factory** | `Factory` returns interfaces (`IControladorX`), decoupling the creation of concrete controllers |
| **Observer** | `Inmobiliaria` acts as observable subject; `Cliente` and `Propietario` implement `ISuscrito` and receive notifications |
| **DTO (Data Transfer Object)** | `DT*` classes (`DTInmueble`, `DTUsuario`, `DTPublicacion`, etc.) for transferring data between layers without exposing the model |
| **Controller (GRASP)** | Controllers encapsulate use case logic behind interfaces |
| **Polymorphism / Strategy** | Hierarchies `Publicacion`, `Inmueble → Casa/Apartamento` and `Usuario → Cliente/Propietario/Inmobiliaria` with virtual methods |


## Project Structure

```
P4-MONITOREO-main/
├── main.cpp                    # Lab 0 — Academic publications
├── Makefile
├── include/                    # Lab 0 headers
│   ├── Publicacion.h
│   ├── ArticuloRevista.h
│   ├── Libro.h
│   ├── PaginaWeb.h
│   ├── Investigador.h
│   ├── DTFecha.h
│   └── DTRefer.h
├── src/                        # Lab 0 implementations
│   ├── Publicacion.cpp
│   ├── ArticuloRevista.cpp
│   ├── Libro.cpp
│   ├── PaginaWeb.cpp
│   ├── Investigador.cpp
│   ├── DTFecha.cpp
│   └── DTRefer.cpp
├── lab1/                       # Domain model (Draw.io)
├── lab2/                       # Use case model (Draw.io)
└── lab4/
  ├── 43_lab4/                # Real estate system — main version
  │   ├── main
  │   ├── Makefile
  │   ├── include/            # Headers (users, properties, controllers, DTOs)
  │   └── src/                # Complete implementations
  └── lab4_2025/              # Real estate system — refactored version
    ├── main.cpp
    ├── Makefile            # Includes execution with Valgrind
    ├── include/
    └── src/
```

---


## Technologies and Tools

- **Language:** C++ (C++98 / C++11)
- **Compiler:** g++
- **Build system:** GNU Make
- **Memory leak detection:** Valgrind
- **STL containers:** `map`, `set`, `list`, `vector`, `string`
- **UML modeling:** Draw.io (domain and use case diagrams)

---

## Simplified Class Diagram

### Publications Domain (Lab 0)

```
Publicacion (abstract)
  ├── ArticuloRevista
  ├── Libro
  └── PaginaWeb

Investigador ◆——▷ Publicacion  (many-to-many)
```

### Real Estate Domain (Lab 4)

```
Usuario (abstract)
  ├── Cliente         ──implements──▷ ISuscrito
  ├── Propietario     ──implements──▷ ISuscrito
  └── Inmobiliaria    ──notifies──▷ ISuscrito (Observer)

Inmueble (abstract)
  ├── Casa
  └── Apartamento

AdministraPropiedad ──links──▷ Inmobiliaria ↔ Inmueble
Publicacion ──belongs to──▷ AdministraPropiedad
```

---

## Key Concepts Demonstrated

- Object-oriented design with inheritance, polymorphism, and abstract classes
- Separation of responsibilities with controllers and interfaces
- Dynamic memory management in C++ with `new`/`delete` and validation using Valgrind
- GoF design patterns (Singleton, Observer, Abstract Factory)
- GRASP patterns (Controller, Creator, Expert)
- Use of DTOs for safe data transfer between layers
- UML modeling prior to implementation (domain and use case diagrams)

---


*Academic project developed as part of the Programación 4 course.*
