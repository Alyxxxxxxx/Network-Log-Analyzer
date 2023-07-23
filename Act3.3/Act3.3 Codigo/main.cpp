/**
 * Autores:
 *  Alyson Melissa Sánchez Serratos - A01771843
 *  Karen Nikole Morales Rosa - A01782557
 *
 * Fecha de creación:
 *  Martes, 18 de julio de 2023
 * 
 * Fecha de modificación:
 *  Miércoles, 19 de julio de 2023
 * 
 * Descripción del programa:
 *  El presente código en lenguaje C++ permite leer 
 *  y almacenar en una estructura de datos los 
 *  registros encontrados en el archivo BitacoraHeap.txt.
 *  A su vez, se utiliza el algoritmo Heap Sort para ordenar 
 *  los registros por IP, ignorando los puertos.
 *  Implementa un método eficiente para contabilizar la cantidad 
 *  de accesos de cada IP y almacenarlos en una estructura de datos 
 *  jerárquica. La estructura de datos permite recuperar de manera 
 *  eficiente las IP con el mayor número de accesos.
 * 
 * Banderas de compilación y ejecución:
 *  Compilacion para debug:
 *    g++ -std=c++17 -g -o main *.cpp
 *  Ejecucion con valgrind:
 *    nix-env -iA nixpkgs.valgrind
 *    valgrind --leak-check=full ./main
 *  Compilacion para ejecucion:
 *    g++ -std=c++17 -O3 -o main *.cpp
 *  Ejecucion:
 *    ./main
 * 
 * Link de Replit:
 *  https://replit.com/join/vzqgvmbdni-alyson-melissa1
 * 
 * Fuentes de información:
 *  1. Follow, H. A. A. (2019, abril 16). Building heap from array. 
 *  GeeksforGeeks. https://www.geeksforgeeks.org/building-heap-from-array/
 * 
 *  2. Binary Heap. (2014, noviembre 1). GeeksforGeeks. 
 *  https://www.geeksforgeeks.org/binary-heap/
 * 
 *  3. Unordered_map in C++ STL. (2016, marzo 24). GeeksforGeeks. 
 *  https://www.geeksforgeeks.org/unordered_map-in-cpp-stl/
 **/

#include <iostream>
#include <limits>
#include <stdexcept>

#include "AdministraRegistros.h"

int main(){
    unsigned int comparacion, intercambio;
    AdministraRegistros registroAdmin;
    std::cout << "\n--------------------------------ABERTURA DE ARCHIVO BITACORA-----------------------------------\n" << std::endl;
        
    try{
        registroAdmin.leerArchivo("bitacoraHeap.txt");
    }

    catch (const std::exception &e){
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "\n--------------------------------ORDENAMIENTO DE BITACORA HEAP SORT-------------------------------\n" << std::endl;
    
    try{
        registroAdmin.ordenaRegistros(comparacion, intercambio);
        registroAdmin.guardaRegistros("bitacora_ordenada.txt");
    }

    catch (const std::exception &e){
        std::cout << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    
    std::cout << "\n-------------------------------------CONTABILIZACION DE IPs---------------------------------------\n" << std::endl;

    try{
        registroAdmin.cuentaAccesoIp();
    }

    catch (const std::exception &e){
        std::cout << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

  

}
