/**
 * Autores:
 *    Alyson Melissa Sánchez Serratos - A01771843
 *    Karen Nikole Morales Rosa - A01782557
 *
 * Descripción:
 *  Código creado en el lenguaje c++ el cual lee una bitácora de conexiones de red,
 *  construye un grafo dirigido a partir de los datos y crea una tabla hash para
 *  almacenar un resumen de información de cada dirección IP en el grafo. Luego,
 *  el código permite al usuario obtener un resumen detallado de información sobre
 *  una dirección IP específica, especificando el número de direcciones IP acccesadas
 *  y muestra el número total de colisiones generadas durante el proceso de inserción
 *  en la tabla hash.
 *
 * Fecha de creación:
 *     Miércoles, 26 de julio de 2023
 *
 * Fecha de modificación:
 *     Viernes, 28 de julio de 2023
 *
 * Compilacion para debug:
 *    g++ -std=c++17 -g -o main *.cpp
 * Ejecucion con valgrind:
 *    nix-env -iA nixpkgs.valgrind
 *    valgrind --leak-check=full ./main
 * Compilacion para ejecucion:
 *    g++ -std=c++17 -O3 -o main *.cpp
 * Ejecucion:
 *    ./main
 *
 * Código de Replit:
 *  https://replit.com/join/srjndjmlql-alyson-melissa1
 *
 * Fuentes de información:
 *  C++ Program to check Prime Number. (2015, noviembre 21). GeeksforGeeks.
 *  https://www.geeksforgeeks.org/c-program-to-check-prime-number/
 **/

#include <iostream>
#include <sstream>
#include "Bitacora.h"

int main(){
    Bitacora myBitacora("bitacoraGrafos.txt");

    return 0;
}