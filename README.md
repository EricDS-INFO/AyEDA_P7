# ESTE REPOSITORIO CONTIENE LA SÉPTIMA PRÁCTICA DE AyEDA.
*( Implementación de AVL )*
***

## Contenido:
**En el include:**
- [Plantilla de función del algoritmo de Inserción](./include/insertion_sorting.hpp)

- [Definición de la clase DNI](./include/dni.hpp)

**En el modif:**


**En el src:**
- [Implementación de la clase de clave DNI](./src/dni.cpp)
- [Implementación del programa principal](./src/BST_main.cpp)

## Dependencias

- [Catch2](https://github.com/catchorg/Catch2)
  > Librería de testing para C++ con BDD
  

## Funciones del makefile 

- make       :arrow_right: compila el fichero fuente básico solicitado
> genera el ejecutable como "runner" 
- make test  :arrow_right: compila los test
> genera el ejecutable como "test_runner". Si se ejecuta con "-s" se despliegan todos 
> los test

- make mod :arrow_right: compila el programa modificado
> genera el ejecutable como "modif_runner" 
- make clean :arrow_right: eliminar ejecutables
