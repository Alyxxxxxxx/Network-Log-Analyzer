#include <iostream>
#include <limits>
#include <stdexcept>
#include "AdministraRegistros.h"
#include "DLinkedList.h"

/*
 * Autores:
 * Alyson Melissa Sánchez Serratos - A01771843
 * Karen Nikole Morales Rosa - A01782557
 *
 * Fecha de creación:
 * Jueves, 13 de julio de 2023
 *
 * Fecha de modificación:
 * Sábado, 15 de julio de 2023
 *
 * Decripción del programa:
 * El código en lenguaje C++ lee y almacena datos del
 * archivo bitacora.txt, ordena los registros por fecha y hora,
 * permite buscar registros dentro de un rango de fechas
 * especificado por el usuario y los despliega en pantalla,
 * al igual que también crea un archivo de salida llamado
 * "resultado_busqueda.txt" con el resultado de las
 * busquedas dentro de los rangos dados por el usuario.
 * Por último, guarda el resultado del ordenamiento de la
 * bitácora completa en otro archivo llamado "bitacora_ordenada.txt"
 *
 * Banderas de compilación y ejecución:
 *    Compilación para debug:
 *    g++ -std=c++17 -g -o main *.cpp
 *    Compilación para ejecución:
 *    g++ -std=c++17 -O3 -o main *.cpp
 *    Ejecucion con valgrind:
 *    nix-env -iA nixpkgs.valgrind
 *    valgrind --leak-check=full ./main
 *    Ejecución:
 *    ./main
 *
 * Link de Replit:
 * https://replit.com/join/ybaeupyxde-alyson-melissa1
 *
 * Fuente de información:
 * Merge sort for doubly linked list. (2015, mayo 2). GeeksforGeeks.
 * https://www.geeksforgeeks.org/merge-sort-for-doubly-linked-list/
 *
 * Coding ninjas studio. (s/f). Codingninjas.com. Recuperado el 15 de julio de 2023,
 * de https://www.codingninjas.com/studio/library/binary-search-on-linked-list
 */

int main(){
    bool continuar = true;
    AdministraRegistros<Registro> administraLista("bitacora.txt");
    administraLista.sort();
    administraLista.saveList("bitacora_ordenada.txt", 1);

    while (continuar){
        administraLista.restartSubList();
        int intervalo = 1;
        DLLNode<Registro> *fechaInicio = administraLista.ingresarDatos(intervalo);
        intervalo++;
        DLLNode<Registro> *fechaFin = administraLista.ingresarDatos(intervalo);
        administraLista.getSublist(fechaInicio, fechaFin);
        administraLista.printList();
        administraLista.saveList("resultado_busqueda.txt", 2);

        bool opcionValida = false;

        do{
            try{
                int consulta;
                std::cout << "¿Desea hacer otra consulta?. NO = 0. SI = 1: ";
                std::cin >> consulta;

                if (std::cin.fail()) {
                    throw std::invalid_argument("Opción no válida. Intente de nuevo presionando [ENTER] ");
                }
    
                if (consulta != 1 && consulta != 0 ){
                    throw std::invalid_argument("Opcion no valida. Intente de nuevo presionando [ENTER] ");
                }

                opcionValida = true;

                if (consulta == 0){
                    std::cout << "Cerrando programa..." << std::endl;
                    continuar = false;
                }

                else{
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    
                    for (int i = 0; i < 40; i++) {
                        std::cout << std::endl;
                    }
                }

            }
           
            catch (const std::invalid_argument &e){
                std::cout << "Error: " << e.what();
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.ignore(); 

                for (int i = 0; i < 40; i++) {
                std::cout << std::endl;
                }
            }

        } while (!opcionValida);
    }

   return 0;
}
