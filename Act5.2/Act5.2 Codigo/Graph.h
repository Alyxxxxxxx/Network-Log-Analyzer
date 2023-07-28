#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include "LinkedList.h"
#include "IpAddress.h"
#include "HashTable.h"
#include "Numbers.h"


template <class T>
class Graph{
private:
    int numNodes;
    int numEdges;
    int directedGraph;
    int weightedGraph;
    int sizeHT;
    std::map<int, T> nodesInfo;
    std::vector<ipAddress> ips;
    std::vector<int> vecSizeHash;
    std::vector<LinkedList<std::pair<int, int>>> adjList;
    HashTable<unsigned int, ipAddress> hashTableIp;

    /*
     * Descripción: split()
     *      Toma una cadena de entrada (line) que contiene números enteros
     *      separados por espacios y divide esa cadena en números enteros
     *      individuales, almacenándolos en un vector de enteros (res).
     *
     * Parámetros de entrada:
     *      @line: Una cadena de texto que contiene los números enteros separados
     *      por espacios que se dividirán.
     *
     *      @res: Una referencia a un vector de enteros donde se almacenarán los
     *      números enteros resultantes después de dividir la cadena.
     *
     * Valor de retorno:
     *      No retorna ningún valor.
     *
     * Complejidad temporal:
     *      O(n) donde n es el número de elemento separadoss por espacios en la
     *      línea.
     */

    void split(std::string line, std::vector<int> &res);

    /*
     * Descripción: binarySearch()
     *      Método que implementa la búsqueda binaria para encontrar una dirección IP
     *      (ipAddress) específica dentro de un vector de direcciones IP (ips). El método
     *      busca la dirección IP 'key' en el vector 'ips' y devuelve su índice si se encuentra,
     *      o -1 si no se encuentra.
     *
     * Parámetros de entrada:
     *      @key: Dirección IP que se desea buscar dentro del vector 'ips'.
     *
     * Valor de retorno:
     *      Si la dirección IP 'key' se encuentra en el vector 'ips', el método devuelve el índice
     *      de la dirección IP en el vector. Si la dirección IP no se encuentra, el método devuelve
     *      -1 para indicar que no se ha encontrado.
     *
     * Complejidad temporal:
     *      O(log n), donde n es el tamaño del vector ips.
     */

    int binarySearch(ipAddress Key);

public:

    /*
     * Descripción:
     *     Constructor de la clase Graph. Se utiliza para inicializar un objeto de
     *     la clase Graph. Establece los valores iniciales de las variables miembro
     *     numNodes, numEdges, directedGraph y weightedGraph.
     *
     * Parámetros de entrada:
     *      No posee parámetros de entrada.
     *
     * Valor de retorno:
     *      No retorna ningún valor.
     *
     * Complejidad temporal:
     *      O(1)
     */

    Graph();

    /*
     * Descripción:
     *      Destructor de la clase Graph. Se utiliza para liberar la memoria y realizar
     *      limpieza antes de que un objeto de la clase Graph sea eliminado. Se libera la 
     *      memoria de la lista de adyacencia (adjList). Además, restablece los valores 
     *      miembro a sus valores predeterminados.
     *
     * Parámetros de entrada:
     *      No posee parámetros de entrada.
     *
     * Valor de retorno:
     *      No retorna ningún valor.
     *
     * Complejidad temporal:
     *      O(n)
     */

    ~Graph();

    /*
     * Descripción: readGraph()
     *      Método que lee la lista de adyacencia del grafo desde la apertura de
     *      un archivo y construye la representación del grafo en la memoria mediante
     *      la estructura de datos adjList. A su vez, inicializa una Tabla Hash con un
     *      tamaño máximo, primo, mayor y cercano al numero de direcciones iP en la 
     *      bitácora de acuerdo con lo seleccionado con el usuario.
     *
     * Parámetros de entrada:
     *      @inputFile: string que representa el nombre del archivo que contiene la lista
     *      de adyacencia del grafo.
     *
     *      @_directed: Un entero que indica si el grafo es dirigido (1) o no dirigido (0).
     *
     *      @_weighted: Un entero que indica si el grafo es ponderado (1) o no ponderado (0).
     * 
     *      @option: Un int que representa la opción para determinar el tamaño máximo (MaxSize) 
     *      de la tabla hash.
     *
     * Valor de retorno:
     *      No retorna ningún valor.
     *
     * Complejidad temporal:
     *      O(n + m) donde n es el número de nodos y m el número de aristas del grafo.
     */

    void readGraph(std::string inputFile, int _directed, int _weighted, int option);

    /*
     * Descripción: getIPSummary()
     *     Método utilizado para un obtener un resumen de información relacionada con una dirección
     *     IP específica en el grafo. La dirección IP se busca en el vector ips utilizando una
     *     búsqueda binaria (binarySearch), y si se encuentra, se procede a obtener información
     *     adicional relacionada con esa dirección IP dentro de la tabla hash.
     *
     * Parámetros de entrada:
     *      @searchedIp: Un string que representa la dirección IP que se desea obtener el resumen.
     *
     * Valor de retorno:
     *      No retorna ningún valor.
     *
     * Complejidad temporal:
     *      O(n log n)
     */

    void getIPSummary(std::string searchedIp);

    /*
     * Descripción: getHashT()
     *      Método utilizado para construir una tabla hash (hashTableIp) a partir de las direcciones IP
     *      almacenadas en el vector ips. Cada dirección IP se agrega a la tabla hash utilizando el método
     *      add de la tabla hash, donde la dirección IP es la clave y el objeto ipAddress correspondiente es
     *      el valor.
     *
     * Parámetros de entrada:
     *      No posee parámetros de entrada.
     *
     * Valor de retorno:
     *      No retorna ningún valor.
     *
     * Complejidad temporal:
     *      add() tiene una complejidad promedio de O(1) para una tabla hash bien implementada, por lo que
     *      la complejidad total de método getHashT es aproximadamente O(n).
     */

    void getHashT();

    /*
     * Descripción: printCollisions()
     *      Método utilizado para imprimir el número total de colisiones que ocurren al generar una tabla 
     *      hash de tamaño sizeHT utilizando la tabla hash hashTableIp.
     *
     * Parámetros de entrada:
     *      No posee parámetros de entrada.
     *
     * Valor de retorno:
     *      No retorna ningún valor.
     *
     * Complejidad temporal:
     *      O(1)
     */

    void printCollisions();
};

template <class T>
Graph<T>::Graph(){
    numNodes = 0;
    numEdges = 0;
    directedGraph = 1;
    weightedGraph = 1;
}

template <class T>
Graph<T>::~Graph(){
    adjList.clear();
    numNodes = 0;
    numEdges = 0;
    directedGraph = 1;
    weightedGraph = 1;
}

template <class T>
void Graph<T>::split(std::string line, std::vector<int> &res){
    size_t strPos = line.find(" ");
    size_t lastPos = 0;

    while (strPos != std::string::npos){
        res.push_back(stoi(line.substr(lastPos, strPos - lastPos)));
        lastPos = strPos + 1;
        strPos = line.find(" ", lastPos);
    }

    res.push_back(stoi(line.substr(lastPos, line.size() - lastPos)));
}

template <class T>
int Graph<T>::binarySearch(ipAddress key){
    int low = 0;
    int high = ips.size() - 1;
    int mid = 0;

    while (low <= high){
        mid = low + (high - low) / 2;

        if (key == ips[mid]){
            return mid;
        }

        else if (key < ips[mid]){
            high = mid - 1;
        }

        else{
            low = mid + 1;
        }
    }

    return -1;
}

template <class T>
void Graph<T>::readGraph(std::string inputFile, int _directed, int _weighted, int option){
    directedGraph = _directed;
    weightedGraph = _weighted;
    std::string line, ip1, ip2, peso;
    int i = 0;
    std::ifstream file(inputFile);

    if (!file.good()){
        file.close();
        throw std::invalid_argument("File not found");
    }

    else{
        while (std::getline(file, line)){

            if (i == 0){
                std::vector<int> res;
                split(line, res);
                numNodes = res[0];
                numEdges = res[1];

                adjList.resize(numNodes);
                Numbers getSizes;
                vecSizeHash = getSizes.findClosePrime(numNodes);
                sizeHT = vecSizeHash[option-1];
                hashTableIp.setMaxSize(sizeHT);
                i++;
                continue;
            }

            else if (i > 0 && i <= numNodes){
                T data = line;
                nodesInfo.insert(std::make_pair(i - 1, data));
                ipAddress tmpIP(line, i - 1);
                ips.push_back(tmpIP);

                if (i == numNodes){
                    std::sort(ips.begin(), ips.end());
                }

                i++;
                continue;
            }

            std::size_t found = line.find(":", 15);
            ip1 = line.substr(15, found - 15);

            std::size_t found2 = line.find(" ", found + 1);
            std::size_t found3 = line.find(":", found2 + 1);
            ip2 = line.substr(found2, found3 - found2);

            std::size_t found4 = line.find(" ", found3 + 1);
            std::size_t found5 = line.find(" ", found4 + 1);
            peso = line.substr(found4, found5 - found4);

            int pos1 = binarySearch(ipAddress(ip1, 0)); 
            int nodoU = ips[pos1].getIpIndex(); 

            int pos2 = binarySearch(ipAddress(ip2, 0));
            int nodoV = ips[pos2].getIpIndex();

            int weight = std::stoi(peso);

            adjList[nodoU].addLast(std::make_pair(nodoV, weight));

            ips[pos1].addToDegreeOut();
            ips[pos2].addToDegreeIn();
           
            i++;
        }

        file.close();
    }
}

template <class T>
void Graph<T>::getHashT(){

    for (int i = 0; i < numNodes; i++){
        hashTableIp.add(ips[i].getIpValue(), ips[i]);
    }
}

template <class T>
void Graph<T>::printCollisions(){
    std::cout << "-+----------------------------------------------------------+-" << std::endl;
    std::cout << "Colisiones totales al generar una Tabla Hash de tamaño " << sizeHT << " |\n";
    std::cout << "-+----------------------------------------------------------+-" << std::endl;
    std::cout << "COLISIONES     |\t\t       " << hashTableIp.getNumCollisions() << "\t\t     |" << std::endl;
    std::cout << "-+----------------------------------------------------------+-" << std::endl;
}

template <class T>
void Graph<T>::getIPSummary(std::string searchedIp){
    
    int indexIp= binarySearch(ipAddress(searchedIp, 0)); //buscar indice del ip en ips

    if (indexIp != -1){
        int nodoU = ips[indexIp].getIpIndex(); // obtener indice real en bitacora
        MaxHeap<ipAddress> accessedIpSort(ips[indexIp].getDegreeOut());
        int indexHashT = hashTableIp.find(ips[indexIp].getIpValue()); // indice en el hash
        
        if (indexHashT != -1){
            
            std::cout << "-+----------------------------------------------------------+-" << std::endl;
            std::cout << "|          Resumen de la informacion relativa al IP:         |" << std::endl;
            std::cout << "-+----------------------------------------------------------+-" << std::endl;
            std::cout << hashTableIp.getDataAt(indexHashT) << std::endl;
            std::cout << "-+----------------------------------------------------------+-\n" << std::endl;
           

            NodeLinkedList<std::pair<int, int>> *p = adjList[nodoU].getHead();

            while (p != nullptr){
                int indexNodoV = p->data.first; //indice bitacora
                auto it = nodesInfo.find(indexNodoV); //buscar ip de indice de la bitacora

                if (it != nodesInfo.end()){
                    int realIndex = binarySearch(ipAddress(it->second, 0)); //obtener su indice en ips

                    if(realIndex != -1){
                        ips[realIndex].showAccessedIp = true;
                        accessedIpSort.push(ips[realIndex]);
                        p = p->next;
                    }

                    else{
                        throw std::invalid_argument("Direccion IP no encontrada.");
                    }
                }

                else{
                    throw std::invalid_argument("Direccion IP no encontrada.");
                }
            }

            std::cout << "\n-+----------------------------------------------------------+-" << std::endl;
            std::cout << "|  Lista de direcciones accesadas desde la IP recibida:      |" << std::endl;
            std::cout << "-+----------------------------------------------------------+-" << std::endl;   
            int i = 1;
            while(!accessedIpSort.isEmpty()){
                std::cout << i << ".\t|\t  " << accessedIpSort.getTop() << "\t\t\t     |" << std::endl;
                accessedIpSort.pop();
                i++;
            }

             std::cout << "-+----------------------------------------------------------+-\n" << std::endl;
        }

        else{
            throw std::invalid_argument("Direccion IP no encontrada en la Tabla Hash.");
        }
    }

    else{
        throw std::invalid_argument("Direccion IP no encontrada en la Bitacora.");
    }
}

#endif // _GRAPH_H_
