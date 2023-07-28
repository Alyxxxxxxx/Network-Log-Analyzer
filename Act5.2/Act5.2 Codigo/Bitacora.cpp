#include "Bitacora.h"

Bitacora::Bitacora() {}

Bitacora::Bitacora(std::string fileName){
    int option;

    try{
        std::cout << "Ingrese un número del 1 al 5 para determinar el tamaño máximo (MaxSize) de la Tabla Hash. Estos numeros representan los 5 numeros primos mayores mas cercanos al numero de direcciones IP de la bitacora:  ";
        std::cin >> option;

        std::cout << std::endl;

        if(std::cin.fail() || option > 5 || option < 1 ){
            throw std::invalid_argument("Valor ingresado invalido. Ingrese un numero entre el 1 al 5.");
        }

        graph.readGraph(fileName, 1, 1, option);
        graph.getHashT();
        graph.printCollisions();

        std::cout << "\nIngrese la direccion IP en formato string del cual desea obtener su resumen: ";
        std::cin >> searchedIp;
        graph.getIPSummary(searchedIp);
    }

    catch (const std::exception &e){
        std::cout << "Error detectado: " << e.what() << std::endl;
    }
}

Bitacora::~Bitacora() {}