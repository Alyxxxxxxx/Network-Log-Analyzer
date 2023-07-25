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
#include "MaxHeap.h"
#include "IpAdress.h"
#include "IpDegreeOut.h"
#include "Distance.h"


#define INF 0x3f3f3f3f

template <class T>
class Graph {
  private: 
    int numNodes;
    int numEdges;
    int directedGraph; 
    int weightedGraph;

    std::map<int, T> nodesInfo;
    std::vector<ipAddress> ips;
    std::vector<LinkedList<std::pair<int, int>>> adjList;

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
       *     numNodes, numEdges, representation, directedGraph y weightedGraph.
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
       *      limpieza antes de que un objeto de la clase Graph sea eliminado. Dependiendo de
       *      la representación elegida (representation), se libera la memoria de la matriz de
       *      adyacencia (adjMatrix) o de la lista de adyacencia (adjList). Además, restablece
       *      los valores miembro a sus valores predeterminados.
       *
       * Parámetros de entrada:
       *      No posee parámetros de entrada.
       *
       * Valor de retorno:
       *      No retorna ningún valor.
       *
       * Complejidad temporal:
       *      Si se trata de una lista de adyacencia: O(n)
       *      Si se trata de una matriz de adyacencia: O(n^2)
       */

      ~Graph();

      /*
       * Descripción: readGraph()
       *      Método que lee la lista de adyacencia del grafo desde la apertura de
       *      un archivo y construye la representación del grafo en la memoria mediante
       *      la estructura de datos adjList.
       *
       * Parámetros de entrada:
       *      @inputFile: string que representa el nombre del archivo que contiene la lista
       *      de adyacencia del grafo.
       *
       *      @_directed: Un entero que indica si el grafo es dirigido (1) o no dirigido (0).
       *
       *      @_weighted: Un entero que indica si el grafo es ponderado (1) o no ponderado (0).
       *
       * Valor de retorno:
       *      No retorna ningún valor.
       *
       * Complejidad temporal:
       *      O(n + m) donde n es el número de nodos y m el número de aristas del grafo.
       */

      void readGraph(std::string inputFile, int _directed, int _weighted);

      /*
       * Descripción: print()
       *      Método utilizado para imprimir el grafo almacenado en una estructura de
       *      lista de adyacencia. El grafo puede ser ponderado o no ponderado, y se
       *      pueden proporcionar detalles adicionales de los nodos (como una etiqueta)
       *      si se especifica flagInfo como 1.
       *
       * Parámetros de entrada:
       *      @flagInfo: Un entero que indica si se deben imprimir detalles adicionales de
       *       los nodos (etiquetas). Si flagInfo es igual a 1, se imprimirán los detalles
       *       adicionales. De lo contrario, solo se imprimirán los números de los nodos.
       *
       * Valor de retorno:
       *      No retorna ningún valor.
       *
       * Complejidad temporal:
       *      O(n + m) donde n es el número de nodos y m es el número de aristas.
       */

      void print(int flagInfo = 0);

      /*
       * Descripción: printInfo()
       *      Método utilizado para imprimir información básica del grafo almacenado en
       *      la estructura de lista de adyacencias. La información que se muestra
       *      incluye el número total de nodos en el grafo (numNodes) y el número total de
       *      aristas (numEdges). Además, se indica que la representación del grafo es mediante
       *      una lista de adyacencia.
       *
       * Parámetros de entrada:
       *      Este método no toma ningún parámetro de entrada adicional. Sin embargo, se accede 
       *      a los atributos de la clase Graph<T> para obtener la información necesaria para la 
       *      impresión.
       *
       * Valor de retorno:
       *      No retorna ningún valor.
       *
       * Complejidad temporal:
       *      O(1)
       */

      void printInfo();

      /*
       * Descripción: getAllDegreeOut()
       *      Este método se utiliza para obtener y guardar información sobre los grados de salida de
       *      cada nodo en el grafo. El método utiliza un MaxHeap llamado ipSort para almacenar objetos
       *      IpDegreeOut que contienen información sobre las direcciones IP y sus grados de salida.
       *      A continuación, se guardan las 5 IPs con mayor grado de salida en un archivo denominado topFile,
       *      y todos los grados de salida se guardan en un archivo denominado allFile. Además, se imprime
       *      en la consola la información sobre las 5 IPs con mayor grado de salida y la información sobre
       *      el nodo que tiene el grado de salida máximo (Boot Master).
       *
       * Parámetros de entrada:
       *      @allFile: Nombre del archivo donde se guardarán todos los grados de salida de cada nodo.
       *
       *      @topFile: Nombre del archivo donde se guardarán las 5 IPs con mayor grado de salida.
       *
       * Valor de retorno:
       *      El método devuelve el índice del nodo que tiene el grado de salida máximo (Boot Master) 
       *      en el grafo.
       *
       * Complejidad temporal:
       *      O(n log n)
       */

      int getAllDegreeOut(std::string allFile, std::string topFile);

      /*
       * Descripción: Método público dijkstraAlgorithm()
       *      Este método implementa el algoritmo de Dijkstra para encontrar los caminos más cortos desde
       *      un nodo de inicio dado (vertice 'v') hacia todos los demás nodos en el grafo. El método
       *      utiliza una estructura de MaxHeap llamada bootMasterDist para almacenar objetos Distance,
       *      que contienen información sobre las direcciones IP y sus respectivas distancias mínimas desde
       *      el nodo de inicio 'v'. Además, se almacenan las distancias mínimas en un archivo especificado
       *      por el parámetro 'inputFile'.
       *
       * Parámetros de entrada:
       *      @v: Vertice de inicio desde el cual se encuentran los caminos más cortos hacia los demás nodos.
       *
       *      @inputFile: Nombre del archivo donde se guardarán las distancias mínimas desde el vertice de
       *      inicio hacia los demás
       *
       * Valor de retorno:
       *      No retorna ningún valor.
       *
       * Complejidad temporal:
       *      O((n + m) * log(n))
       */

      void dijkstraAlgorithm(int v, std::string inputFile);
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
void Graph<T>::readGraph(std::string inputFile, int _directed, int _weighted){
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
        while(std::getline(file,line)){ 

            if (i == 0){
                std::vector<int> res;
                split(line, res);
                numNodes = res[0];
                numEdges = res[1];
                adjList.resize(numNodes);
                i++;
                continue; 
            }

            else if (i > 0 && i <= numNodes) {
                T data = line; 
                nodesInfo.insert(std::make_pair(i-1, data));  
                ipAddress tmpIP(line, i-1);
                ips.push_back(tmpIP);

                if (i == numNodes) {
                    std::sort(ips.begin(), ips.end());
                }

                i++;
                continue;
            }

        std::size_t found = line.find(":", 15);
        ip1 = line.substr(15, found-15);

        std::size_t found2 = line.find(" ", found+1);
        std::size_t found3 = line.find(":", found2+1);
        ip2 = line.substr(found2, found3-found2);

        std::size_t found4 = line.find(" ", found3+1);
        std::size_t found5 = line.find(" ", found4+1);
        peso = line.substr(found4, found5-found4);

        int pos1 = binarySearch(ipAddress(ip1, 0));
        int nodoU = ips[pos1].getIpIndex();

        int pos2 = binarySearch(ipAddress(ip2, 0));
        int nodoV = ips[pos2].getIpIndex();

        int weight = std::stoi(peso);

        adjList[nodoU].addLast(std::make_pair(nodoV,weight));
        ips[pos1].addToDegreeOut(); 
        i++;
    }
  }

  file.close();
}

template <class T>
int Graph<T>::getAllDegreeOut(std::string allFile, std::string topFile){
    std::cout << "\n-----------------------------------------GRADOS DE SALIDA DE CADA NODO-------------------------------------------" << std::endl;

    MaxHeap<IpDegreeOut> ipSort(numNodes);
    std::ofstream allFileStream(allFile);
    std::ofstream topFileStream(topFile);
    int num = 0;

    if (!allFileStream.good() || !topFileStream.good()){
        allFileStream.close();
        topFileStream.close();
        throw std::invalid_argument("File not found");
    }

    std::cout << "Las 5 IPs con mayor grado de salida son: \n" << std::endl;
 
    for (auto& ip : ips){
            ipSort.push(IpDegreeOut(ip.getIp(), ip.getDegreeOut(), ip.getIpIndex()));
    }

    IpDegreeOut bootMaster = ipSort.getTop();

    while (!ipSort.isEmpty()){
        allFileStream << ipSort.getTop() << std::endl;
            
        if(num < 5){
            topFileStream << ipSort.getTop() << std::endl;
            std::cout << ipSort.getTop() << std::endl;
        }
            
        num++;
        ipSort.pop();
    }

    std::cout << "\nSe ha guardado correctamente los grados de salida en: " <<  allFile << " y en " << topFile << "\n" << std::endl;

    topFileStream.close();
    allFileStream.close();

    std::cout << "\n\t\t\t----  ----  ----  ----  ----BOOT MASTER----  ----  ----  ----  ----\n" << std::endl;
    std::cout << "El Boot Master se encuentra en el vertice " << bootMaster.getIpIndex() + 1 << " ,su direccion IP es " << bootMaster.getIpAccess() << " y su grado de salida es de " << bootMaster.getDegreeOut() << std::endl;
        
    std::cout << "-------------------------------------------------------------------------------------------------------------------\n" << std::endl;

    return bootMaster.getIpIndex();
}

template <class T>
void Graph<T>::printInfo(){
    std::cout << "------------------------------------------------INFORMACION DEL GRAFO-------------------------------------------" << std::endl;
    std::cout << "- Numero de nodos: " << numNodes << std::endl;
    std::cout << "- Numero de aristas: " << numEdges << std::endl;
    std::cout << "- Seleccion de visualizacion: Lista Adyacente." << std::endl;
    std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
}

template <class T>
void Graph<T>::print(int flagInfo) {
    std::cout << "\n-------------------------------------------VISUALIZACION DEL GRAFO--------------------------------------------" << std::endl;

    for (int nodeU = 0; nodeU < numNodes; nodeU++){

        if (flagInfo){
            std::cout << "vertex " << nodesInfo[nodeU] << ": ";
        }

        else{ 
	        std::cout << "vertex " << nodeU+1 << ": ";
        }

        NodeLinkedList<std::pair<int, int>> *ptr = adjList[nodeU].getHead(); 

        while (ptr != nullptr){
            std::pair<int, int> par = ptr->data;
            int nodeV = par.first;
            int weight = par.second;
            std::string nodeData = (flagInfo) ? nodesInfo[nodeV] + ", " : "";

            if (weightedGraph == 1){
                std::cout << "{" << nodeData << nodeV+1 << ", " << weight << "} ";
            }

            else{
                std::cout << "{" << nodeData << nodeV+1 << "} ";
            }

            ptr = ptr->next;
        }
        std::cout << std::endl;
    }

    std::cout << "----------------------------------------------------------------------------------------------------------------" << std::endl;
}

template <class T>
void Graph<T>::dijkstraAlgorithm(int v, std::string inputFile) {

    std::cout << "----------------------------------------CAMINOS MAS CORTOS HACIA BOOT MASTER----------------------------------------\n" << std::endl;

    MaxHeap<Distance> bootMasterDist(numNodes);

    std::vector<int> dist(numNodes, INF);
    std::vector<int> prev(numNodes, -1);
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> pq;

    pq.push(std::make_pair(0, v)); 
    dist[v] = 0;
    prev[v] = -1;
    while (!pq.empty()){
        int nodeU = pq.top().second; 
        pq.pop();

     
        NodeLinkedList<std::pair<int, int>> *ptr = adjList[nodeU].getHead();

        while (ptr != nullptr){
            std::pair<int, int> par = ptr->data;
            int nodeV = par.first;
            int weight = par.second;

            if (dist[nodeV] > dist[nodeU] + weight){
                dist[nodeV] = dist[nodeU] + weight;
                prev[nodeV] = nodeU;
                pq.push(std::make_pair(dist[nodeV], nodeV));
            } 

            ptr = ptr->next;
            
        }    
    }

    for (int i=0; i < numNodes; i++){

        if (dist[i] != INF){
            bootMasterDist.push(Distance(nodesInfo[i], dist[i]));
        }

        else{
            bootMasterDist.push(Distance(nodesInfo[i], -1));
        }
    }

    std::ofstream file(inputFile);

    if (!file.good()){
        file.close();
        throw std::invalid_argument("File not found");
    }

    Distance largestIpDis = bootMasterDist.getTop();
    int num = 0;

    std::cout << "Las 5 distancias mas grandes desde el Boot Master hasta las Ips: \n"<< std::endl;

    while (!bootMasterDist.isEmpty()) {
        file << bootMasterDist.getTop() << std::endl;

        if (num < 5){
            std::cout << bootMasterDist.getTop() << std::endl;
        }
        
        num++;
        bootMasterDist.pop();
    }

    file.close();

    std::cout << "\nSe ha guardado correctamente las distancias en: " << inputFile << "\n" << std::endl;

    std::cout << "\nTomando en cuenta las distancias minimas, la dirección IP que requiere más esfuerzo para que el boot master la ataque\nes " << largestIpDis.getIpAccess() << " con una distancia de " << largestIpDis.getDistance() << std::endl;

    std::cout << "----------------------------------------------------------------------------------------------------------------------" << std::endl;
}

#endif  // _GRAPH_H_
