#ifndef _BITACORA_H_
#define _BITACORA_H_

#include <vector>
#include <fstream>
#include <stdexcept>
#include <string>
#include "Graph.h"

class Bitacora{

private:
    Graph<std::string> graph;

public:

    /*
     * Descripción:
     *      Constructor por defecto de la clase Bitácora.
     *      Crea un objeto de la clase Bitacora sin realizar ninguna operación.
     *
     * Parámetros de entrada:
     *      No posee parámetros, no recibe argumentos.
     *
     * Valor de retorno:
     *      No retorna ningún valor.
     *
     * Complejidad Temporal:
     *      O(1)
     */

    Bitacora();

    /*
     * Descripción:
     *      Crea un objeto de la clase Bitacora y realiza una serie de operaciones en el
     *      grafo almacenado en el objeto, incluyendo la lectura del grafo desde un
     *      archivo, la impresión de información del grafo, la obtención de los grados de
     *      salida de los nodos y la ejecución del algoritmo de Dijkstra para encontrar los
     *      caminos más cortos desde un nodo específico hasta los demás nodos del grafo.
     *
     * Parámetros de entrada:
     *      @fileName: Una cadena que representa el nombre del archivo desde el cual se leerá
     *      el grafo.
     *
     * Valor de retorno:
     *      No retorna ningún valor.
     *
     * Complejidad Temporal:
     *      O((n + m) * log(n))
     */

    Bitacora(std::string fileName);

    /*
     * Descripción:
     *      Destructor por defecto de la clase Bitácora.
     *
     * Parámetros de entrada:
     *      No posee parámetros, no recibe argumentos.
     *
     * Valor de retorno:
     *      No retorna ningún valor.
     *
     * Complejidad Temporal:
     *      O(1)
     */

    ~Bitacora();
};

Bitacora::Bitacora(){

}

Bitacora::Bitacora(std::string fileName){

    try{
        graph.readGraph(fileName, 1, 1);
        graph.printInfo();
        int bootMaster = graph.getAllDegreeOut("grados_ips.txt", "mayores_grados_ips.txt");
        graph.dijkstraAlgorithm(bootMaster, "distancia_bootmaster.txt");
    }
    
    catch (const std::exception &e){
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

Bitacora::~Bitacora(){
    
}

#endif // _BITACORA_H_