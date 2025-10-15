# Árbol AVL EEDD

[![C++](https://img.shields.io/badge/language-C++-blue.svg)](https://isocpp.org/)
[![Estado](https://img.shields.io/badge/status-active-brightgreen.svg)]()
[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
<br>
[![Build and Run](https://github.com/miguerubsk/Arbol_AVL_EEDD/actions/workflows/build.yml/badge.svg)](https://github.com/miguerubsk/Arbol_AVL_EEDD/actions/workflows/build.yml)
[![CodeQL Advanced](https://github.com/miguerubsk/Arbol_AVL_EEDD/actions/workflows/codeql.yml/badge.svg)](https://github.com/miguerubsk/Arbol_AVL_EEDD/actions/workflows/codeql.yml)

## Descripción

Árbol AVL EEDD es una implementación en C++ de un árbol binario de búsqueda auto-balanceado (AVL), con operaciones de inserción, borrado, recorrido, búsqueda y cálculo de altura. El proyecto incluye ejemplos de uso con la clase `Cliente`, gestión de motos y rutas, y estructuras auxiliares como listas enlazadas y vectores dinámicos.

## Tabla de Contenidos

- [Instalación](#instalación)
- [Uso](#uso)
- [Estructura del Proyecto](#estructura-del-proyecto)
- [Contribuir](#contribuir)
- [Licencia](#licencia)
- [Contacto](#contacto)
- [Reconocimientos](#reconocimientos)

## Instalación

1. Clona el repositorio:
   ```sh
   git clone https://github.com/miguerubsk/Arbol_AVL_EEDD.git
   ```
2. Compila el proyecto con tu compilador C++ favorito:

   ```sh
   g++ main.cpp -o arbol_avl -std=c++11
   ```

   O usa tu IDE (Code::Blocks, Visual Studio, CLion, etc).

3. Ejecuta el binario generado:
   ```sh
   ./arbol_avl
   ```

## Uso

- El proyecto implementa un árbol AVL genérico (`AVL`) con operaciones de inserción, borrado, recorrido inorden, búsqueda y cálculo de altura.
- Incluye ejemplos de uso con objetos `Cliente`, gestión de motos (`Moto`) y rutas (`Itinerario`).
- Permite cargar datos desde archivos y realizar búsquedas eficientes.
- Puedes modificar el código para probar otras estructuras o tipos de datos.

## Estructura del Proyecto

```
Arbol_AVL_EEDD/
│
├── AVL.h                  # Implementación del árbol AVL genérico
├── Cliente.h / Cliente.cpp# Definición e implementación de la clase Cliente
├── EcoCityMoto.h / .cpp   # Gestión de clientes y motos
├── Moto.h / Moto.cpp      # Definición e implementación de la clase Moto
├── Itinerario.h / .cpp    # Definición e implementación de la clase Itinerario
├── ListaDEnlazada.h       # Implementación de lista doblemente enlazada
├── vectordinamico.h       # Implementación de vector dinámico genérico
├── UTM.h                  # Clase para coordenadas geográficas
├── fecha.h / fecha.cpp    # Clase para fechas y horas
├── random.h               # Generador de números aleatorios
├── main.cpp               # Ejemplo de uso y pruebas
├── LICENSE                # Licencia GNU GPL v3
└── README.md              # Este archivo
```

## Contribuir

Las contribuciones son bienvenidas. Puedes abrir issues para sugerencias o errores, y enviar pull requests con mejoras o nuevas funcionalidades.

## Licencia

Distribuido bajo la Licencia GNU GPL v3. Consulta el archivo `LICENSE.md` para más información.

## Contacto

[Fernando Jiménez Quesada](https://github.com/ferazules1998) y [Miguel González García](https://github.com/miguerubsk)

## Reconocimientos

- [othneildrew/Best-README-Template](https://github.com/othneildrew/Best-README-Template) por la plantilla.
- [shields.io](https://shields.io/) por los badges.
- C++ Standard Library.
