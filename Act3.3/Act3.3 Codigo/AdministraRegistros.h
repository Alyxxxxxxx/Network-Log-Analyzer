#ifndef _ADMINISTRAREGISTROS_H_
#define _ADMINISTRAREGISTROS_H_

#include "Registro.h"
#include "MaxHeap.h"
#include "AccessTracker.h"

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>

class AdministraRegistros{
    private:
        std::vector<Registro> listaRegistros;
        int numeroRegistros;
    
    public:

        /*
         * Descripción:
         *  Constructor de la clase AdministraRegistros. Inicializa la lista
         *  de registros (listaRegistros) y establece el número de registros
         *  a cero (numeroRegistros).
         *
         * Parámetros de entrada:
         *  No posee parámetros de entrada.
         *
         * Valor de retorno:
         *  No retorna ningún valor.
         *
         * Complejidad temporal:
         *  O(1)
         */

        AdministraRegistros();

        /*
         * Descripción:
         *  Destructor de la clase AdministraRegistros. Limpia la lista de
         *  registros (listaRegistros) y establece el número de registros a
         *  cero (numeroRegistros).
         *
         * Parámetros de entrada:
         *  No posee parámetros de entrada.
         *
         * Valor de retorno:
         *  No retorna ningún valor.
         *
         * Complejidad temporal:
         *  O(1)
         */

        ~AdministraRegistros();

        /*
         * Descripción: leerArchivo()
         *  Método que lee un archivo de bitácora dado una dirección. Extrae
         *  los registros de cada línea del archivo y los almacena en la lista
         *  de registros (listaRegistros). Actualiza el número de registros
         *  (numeroRegistros).
         *
         * Parámetros de entrada:
         *  @direccionArch: Una cadena que representa la dirección del archivo
         * de bitácora a leer.
         *
         * Valor de retorno:
         *  No retorna ningún valor.
         *
         * Complejidad temporal:
         *  O(n) donde n representa el número de líneas en el archivo.
         */

        void leerArchivo(std::string direccionArch);

        /*
         * Descripción: ordenaRegistros()
         *  Método que ordena los registros almacenados en listaRegistros
         *  utilizando el algoritmo Heap Sort. Se utiliza una estructura
         *  MaxHeap para realizar el ordenamiento y se actualizan los valores
         *  de comparacion e intercambio para reflejar la cantidad de comparaciones
         *  e intercambios realizados durante el proceso de ordenamiento.
         *
         * Parámetros de entrada:
         *  @comparacion: Una referencia a un entero sin signo que almacenará la
         *  cantidad de comparaciones realizadas durante el ordenamiento.
         *
         *  @intercambio: Una referencia a un entero sin signo que almacenará la
         *  cantidad de intercambios realizados durante el ordenamiento.
         *
         * Valor de retorno:
         *  No retorna ningún valor.
         *
         * Complejidad temporal:
         *  O(n log n) donde n es la cantidad de registros.
         */

        void ordenaRegistros(unsigned int &comparacion, unsigned int &intercambio);

        /*
         * Descripción: guardaRegistros()
         *  Método que guarda los registros ordenados en un archivo dado una
         *  dirección. Escribe cada registro en una línea separada en el archivo.
         *
         * Parámetros de entrada:
         *  @direccionArch: Una cadena que representa la dirección del archivo
         *  de bitácora donde se guardarán los registros ordenados.
         *
         * Valor de retorno:
         *  No retorna ningún valor.
         *
         * Complejidad temporal:
         *  O(n)
         */

        void guardaRegistros(std::string direccionArch);

        /*
         * Descripción: cuentaAccesoIp()
         *  Método cuyo objetivo es contar la cantidad de accesos para cada dirección 
         *  IP presente en una lista de registros listaRegistros. Para ello, utiliza 
         *  la clase AccessTracker y su método cuentaAccesos para realizar el conteo 
         *  y guardar los resultados en un Heap Tree. A su vez, imprime y guarda los 
         *  10 IPs con más accesos.
         *
         * Parámetros de entrada:
         *  No posee parámetros de entrada.
         *
         * Valor de retorno:
         *  No retorna ningún valor.
         *
         * Complejidad temporal:
         *  O(n log n)
         */

        void cuentaAccesoIp();
};

AdministraRegistros::AdministraRegistros(){
    listaRegistros.clear();
    numeroRegistros = 0;
}

AdministraRegistros::~AdministraRegistros(){
    listaRegistros.clear();
    numeroRegistros = 0;
}

void AdministraRegistros::leerArchivo(std::string direccionArch){
    std::string mes, dia, horas, minutos, segundos, direccionIp, puerto, error;
    std::ifstream archivo(direccionArch);

    if (!archivo.is_open()){
        archivo.close();
        throw std::invalid_argument("No fue posible acceder al archivo. Verifique su existencia y comience de nuevo.");
    }

    std::cout << "¡Archivo abierto con exito!..... ";

    while (std::getline(archivo, mes, ' ') &&
            std::getline(archivo, dia, ' ') &&
            std::getline(archivo, horas, ':') &&
            std::getline(archivo, minutos, ':') &&
            std::getline(archivo, segundos, ' ') &&
            std::getline(archivo, direccionIp, ':') &&
            std::getline(archivo, puerto, ' ') &&
            std::getline(archivo, error)){
    
        Registro registroTemporal(mes, dia, horas, minutos, segundos, direccionIp, puerto, error);
        listaRegistros.push_back(registroTemporal);
        numeroRegistros++;
    }

    archivo.close();
    std::cout << "¡Archivo leido con exito!" << std::endl;
    std::cout << "\n---------------------------------FINALIZACION DE LECTURA DE ARCHIVO------------------------------\n" << std::endl;
    
}

void AdministraRegistros::ordenaRegistros(unsigned int &comparacion, unsigned int &intercambio){
    MaxHeap<Registro> heapRegistros;
    heapRegistros.heapSort(listaRegistros, numeroRegistros, comparacion, intercambio);
}

void AdministraRegistros::guardaRegistros(std::string direccionArch){
     std::ofstream archivo(direccionArch);

    if (!archivo.is_open()){
        archivo.close();
        throw std::invalid_argument("No fue posible acceder al archivo.");
    }

    for (const Registro &registro : listaRegistros){
        archivo << registro.getAll() << std::endl;
    }

    archivo.close();
    std::cout << "La bitacora ordenada ha sido guardada con éxito en el archivo " << direccionArch << std::endl;
    std::cout << "\n------------------------------------FINALIZACION DE ORDENAMIENTO----------------------------------\n" << std::endl;
}

void AdministraRegistros::cuentaAccesoIp(){
    AccessTracker ipRegistro;
    ipRegistro.cuentaAccesos(listaRegistros);
}

#endif //_ADMINISTRAREGISTROS_H_