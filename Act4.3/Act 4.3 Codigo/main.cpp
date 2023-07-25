/**
 * Autores:
 *    Alyson Melissa Sánchez Serratos - A01771843
 *    Karen Nikole Morales Rosa - A01782557
 *
 * Descripción:
 *  Código creado en el lenguaje c++ el cual implementa una clase de
 *  grafo que puede cargar grafos desde un archivo en formato de lista
 *  de lista de adyacencia. El grafo posee métodos para leer un grafo desde
 *  un archivo, realizar el algoritmo de Dijkstra para encontrar los caminos
 *  más cortos hacia un nodo objetivo, imprimir información del grafo y visualizarlo.
 *  Además, esta implementación del grafo es especialmente útil para almacenar
 *  direcciones IP y obtener información relevante sobre posibles atacantes. El grafo
 *  se puede utilizar para modelar y analizar redes de computadoras y evaluar la
 *  seguridad de un sistema informático al encontrar las rutas más cortas desde
 *  un nodo central (Boot Master) hasta otras direcciones IP.
 *
 * Fecha de creación:
 *     Domingo, 23 de julio de 2023
 *
 * Fecha de modificación:
 *     Martes, 25 de julio de 2023
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
 *  https://replit.com/join/wdntaygvgf-alyson-melissa1
 * 
 * Fuentes de información:
 *  Join ertello’s “Asesoria Act 4-3”. (s/f). Replit. Recuperado el 25 de julio de 2023,
 *  de https://replit.com/join/ykcsbkuryp-ertello
 **/

#include <iostream>
#include <sstream>
#include "Bitacora.h"

int main(){
    Bitacora myBitacora("bitacoraGrafos.txt");

    return 0;
}