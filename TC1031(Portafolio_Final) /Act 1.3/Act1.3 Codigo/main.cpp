#include <iostream>
#include <stdexcept>
#include "Registro.h"
#include "AdministradorRegistros.h"

/*
 * Autores:
 * Alyson Melissa Sánchez Serratos - A01771843
 * Karen Nikole Morales Rosa - A01782557
 *
 * Fecha de creación:
 * Jueves 06 de julio de 2023
 *
 * Fecha de modificación:
 * Sábado 09 de julio de 2023
 *
 * Descripción del programa:
 * El código en lenguaje C++ lee y almacena datos del
 * archivo bitacora.txt, ordena los registros por fecha,
 * permite buscar registros dentro de un rango de fechas
 * especificado por el usuario y los despliega en pantalla,
 * y por último, guarda el resultado del ordenamiento de la
 * bitácora completa en otro archivo llamado bitacora_ordenada.txt
 *
 * Link de Replit:
 * https://replit.com/join/djsjpereev-alyson-melissa1
 *
 * Banderas de compilación y ejecución:
 *    Compilación para debug:
 *    g++ -std=c++17 -g -o main *.cpp
 *    Compilación para ejecución:
 *    g++ -std=c++17 -O3 -o main *.cpp
 *    Ejecucion con valgrind:
 *    valgrind --leak-check=full ./main
 *    Ejecución:
 *    ./main
 */

int main(){
    int intervalo = 1;
    int continuar = 1;
    unsigned int comparaciones = 0;
    AdministradorRegistros administra;
    Registro registra;
    std::vector<Registro> vectorFechas = administra.obtenerLinea("bitacora.txt");

    vectorFechas = administra.ordenaVector(vectorFechas);
    registra.guardarBitacoraOrd(vectorFechas, "bitacora_ordenada.txt");

    while (continuar == 1){
        Registro dataIn = administra.ingresarDatos(intervalo); // fecha inicio
        int pruebaExistencia = registra.busquedaBinaria(vectorFechas, dataIn, comparaciones);

        if (pruebaExistencia == -1){
            throw std::invalid_argument("Fecha ingresada no encontrada.");
        }

        else{
            std::cout << "Se encontro la primera fecha ingresada en " << comparaciones << " comparaciones." << std::endl;
            intervalo++;

            Registro dataFin = administra.ingresarDatos(intervalo); // fecha fin
            int pruebaExistencia = registra.busquedaBinaria(vectorFechas, dataFin, comparaciones);

            if (pruebaExistencia == -1){
                throw std::invalid_argument("Fecha ingresada no encontrada.");
            }
            
            else{
                std::cout << "Se encontro la segunda fecha ingresada en " << comparaciones << " comparaciones." << std::endl;
        
                Registro registroPersonalizado;
                std::vector<Registro> vectorFechasInt;

                vectorFechasInt = registroPersonalizado.buscarFechas(vectorFechas, dataIn, dataFin);
                registroPersonalizado.imprimirDatos(vectorFechasInt);
                intervalo = 1;
            }
        }
        
        std::cout << "\n¿Desea continuar? 1 = continuar y 2 = detener ---> ";
        std::cin >> continuar;
        std::cout << std::endl;
    }
}