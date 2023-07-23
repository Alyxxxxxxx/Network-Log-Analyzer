#ifndef _MAXHEAP_H_
#define _MAXHEAP_H_

#include "Registro.h"

#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>

template <class T>
class MaxHeap{
private:
    std::vector<T> data;
    int maxCapacity;
    int currentSize;

    /*
     * Descripción: parent()
     *  Método que calcula el índice del nodo padre de un nodo dado en el 
     *  Max Heap.
     *
     * Parámetros de entrada:
     *  @k: Entero que representa el índice del nodo para el cual se quiere 
     *  encontrar el índice del nodo padre.
     *
     * Valor de retorno:
     *  Variable entera que representa el índice del nodo padre del nodo en la 
     *  posición 'k'.
     * 
     * Complejidad temporal:
     *  O(1)
     */

    int parent(int k);

    /*
     * Descripción: left()
     *  Método que calcula el índice del nodo hijo izquierdo de un nodo dado en el
     *  Max Heap.
     *
     * Parámetros de entrada:
     *  @k: Entero que representa el índice del nodo para el cual se quiere encontrar 
     *  el índice del nodo hijo izquierdo.
     *
     * Valor de retorno:
     *  Variable entera que representa el índice del nodo hijo izquierdo del nodo en
     *  la posición 'k'.
     *
     * Complejidad temporal:
     *  O(1)
     */

    int left(int k);

    /*
     * Descripción: right()
     *  Método que calcula el índice del nodo hijo derecho de un nodo dado en el
     *  Max Heap.
     *
     * Parámetros de entrada:
     *  @k: Entero que representa el índice del nodo para el cual se quiere encontrar
     *  el índice del nodo hijo derecho.
     *
     * Valor de retorno: 
     *  Variable entera que representa el índice del nodo hijo derecho del nodo en 
     *  la posición 'k'.
     *
     * Complejidad temporal:
     *  O(1)
     */

    int right(int k);

    /*
     * Descripción: heapifyHelper()
     *  Método auxiliar utilizado por el método heapSort() y Pop() para
     *  realizar la operación de heapify en el heap.
     *
     *  En el contexto del Max Heap, la operación heapify consiste en
     *  comparar un nodo padre con sus nodos hijos (izquierdo y derecho)
     *  y asegurarse de que el nodo padre sea mayor o igual que sus nodos
     *  hijos. Si el nodo padre es menor que alguno de sus nodos hijos, se
     *  intercambian las posiciones del nodo padre con el nodo hijo más grande
     *  y luego se realiza heapify recursivamente en el nodo hijo afectado para
     *  garantizar que la propiedad del Max Heap se mantenga.
     *
     * Parámetros de entrada:
     *  @vectorRegistros: Una referencia al vector que se va a ordenar.
     *
     *  @n: El tamaño del heap (o subárbol del heap) en el que se va a
     *  aplicar la operación de heapify.
     *
     *  @k: El índice del nodo padre en el heap (o subárbol del heap).
     *
     *  @comparacion: Una referencia a una variable de tipo unsigned int
     *  que llevará el conteo de las comparaciones realizadas durante el
     *  algoritmo.
     *
     *  @intercambio: Una referencia a una variable de tipo unsigned int que
     *  llevará el conteo de los intercambios realizados durante el algoritmo.
     * 
     * Valor de retorno:
     *  No retorna ningún valor.
     * 
     * Complejidad temporal:
     *  O(log n)
     */

    void heapifyHelper(std::vector<T> &vectorRegistros, int n, int k, unsigned int &comparacion, unsigned int &intercambio);

    /*
     * Descripción: heapifyPop()
     *  Método auxiliar utilizada por el método pop() para realizar la operación
     *  de heapify después de eliminar la raíz del heap.
     *
     * Parámetros de entrada:
     *  @k: El índice del nodo padre en el heap.
     * 
     * Valor de retorno:
     *  No retorna ningún valor.
     * 
     * Complejidad temporal:
     *  O(log n)
     */

    void heapifyPop(int k);

public:

    /*
     * Descripción:
     *  Constructor sin argumentos de la clase MaxHeap. Inicializa
     *  un MaxHeap vacío.
     *
     * Parámetros de entrada:
     *  No posee parámetros de entrada.
     *
     * Valor de retorno:
     *  No retorna ningún valor.
     *
     * Complejidad temporal:
     *  O(n)
     */

    MaxHeap();

    /*
     * Descripción:
     *  Constructor de la clase MaxHeap que establece la capacidad máxima
     *  del heap y lo redimensiona para almacenar elementos.
     *
     * Parámetros de entrada:
     *  @_maxCapacity: entero que representa la capacidad máxima inicial del
     *  heap que se está creando.
     *
     * Valor de retorno:
     *  No retorna ningún valor.
     *
     * Complejidad temporal:
     *  O(n)
     */

    MaxHeap(int _maxCapacity);

    /*
     * Descripión:
     *  Destructor de la clase MaxHeap, limpia los atributos y libera la
     *  memoria utilizada por el vector.
     *
     * Parámetros de entrada:
     *  No posee parámetros de entrada.
     *
     * Valor de retorno:
     *  No retorna ningún valor.
     *
     * Complejidad temporal:
     *  O(n)
     */

    ~MaxHeap();

    /*
     * Descripción: isEmpty()
     *  Método que verifica si el MaxHeap está vacío.
     *
     * Parámetros de entrada:
     *  No posee parámetros de entrada.
     *
     * Valor de retorno:
     *  Un valor booleano que indica si el MaxHeap está
     *  vacío o no.
     *
     * Complejidad temporal:
     *  O(1)
     */

    bool isEmpty();

    /*
     * Descripción: getMaxCapacity()
     *  Método que devuelve la capacidad máxima del MaxHeap.
     *
     * Parámetros de entrada:
     *  No posee parámetros de entrada.
     *
     * Valor de retorno:
     *  Valor entero que representa la capacidad máxima del heap
     *  que fue establecida cuando se creó la instancia del objeto.
     *
     * Complejidad temporal:
     *  O(1)
     */

    int getMaxCapacity();

    /*
     * Descripción: getCurrentSize()
     *  Método que devuelve la cantidad actual de elementos en
     *  el MaxHeap.
     *
     * Parámetros de entrada:
     *  No posee parámetros de entrada.
     *
     * Valor de retorno:
     *  Valor entero que representa el número actual de elementos 
     *  presentes en el heap en el momento en que se llama la función.
     *
     * Complejidad temporal:
     *  O(1)
     */

    int getCurrentSize();

    /*
     * Descripción: print()
     *  Método que imprime los elementos almacenados en el MaxHeap.
     *
     * Parámetros de entrada:
     *  No posee parámetros de entrada.
     *
     * Valor de retorno:
     *  No retorna ningún valor.
     *
     * Complejidad temporal:
     *  O(n)
     */

    void print();

    /*
     * Descripción: saveHeap()
     *  Método que guarda los elementos del MaxHeap en un archivo dado su
     *  dirección.
     *
     * Parámetros de entrada:
     *  @direccionArch: String que representa la dirección del archivo donde 
     *  se guardarán los elementos del MaxHeap.
     *
     * Valor de retorno:
     *  No retorna ningún valor.
     *
     * Complejidad temporal:
     *  O(n)
     */

    void saveHeap(std::string direccionArch);

    /*
     * Descripción: push()
     *  Método para insertar un nuevo elemento en el MaxHeap y mantener su
     *  propiedad de MaxHeap.
     *
     * Parámetros de entrada:
     *  @key: Variable de tipo T que representa el elemento a insertar en el 
     *  MaxHeap
     * 
     * Valor de retorno:
     *  No retorna ningún valor.
     * 
     * Complejidad temporal:
     *  O(log n)
     */

    void push(T key);

    /*
     * Descripción: getTop()
     *  Método que devuelve el elemento máximo (raíz) del MaxHeap.
     *
     * Parámetros de entrada:
     *  No posee parámetros de entrada.
     *
     * Valor de retorno:
     *  Variable de tipo T que representa el elemento máximo (raíz) del 
     *  MaxHeap.
     * 
     * Complejidad temporal:
     *  O(1)
     */

    T getTop();

    /* 
     * Descripción: pop()
     *  Método que elimina el elemento máximo (raíz) del MaxHeap y 
     *  ajusta el heap hacia abajo para mantener la  propiedad de 
     *  MaxHeap.
     * 
     * Parámetros de entrada:
     *  No posee parámetros de entrada.
     * 
     * Valor de retorno:
     *  No retorna ningún valor.
     * 
     * Complejidad temporal:
     *  O(log n)
     */

    void pop();

    /*
     * Descripción: heapSort()
     *  Este método implementa el algoritmo de ordenamiento HeapSort
     *  utilizando un Max Heap para ordenar un vector de elementos en
     *  orden ascendente.
     *
     * Parámetros de entrada:
     *  @vectorRegistros: Una referencia al vector que se va a ordenar.
     *
     *  @n: El tamaño del vector a ordenar.
     *
     *  @comparacion: Una referencia a una variable de tipo unsigned int
     *  que llevará el conteo de las comparaciones realizadas durante el
     *  algoritmo.
     *
     *  @intercambio: Una referencia a una variable de tipo unsigned int que 
     *  llevará el conteo de los intercambios realizados durante el algoritmo.
     * 
     * Valor de retorno:
     *  No retorna ningún valor.
     * 
     * Complejidad temporal:
     *  O(n log n)
     */

    void heapSort(std::vector<T> &vectorRegistros, int n, unsigned int &comparacion, unsigned int &intercambio);
};

template <class T>
MaxHeap<T>::MaxHeap(){
    data.clear();
    maxCapacity = 0;
    currentSize = 0;
}

template <class T>
MaxHeap<T>::MaxHeap(int _maxCapacity){
    maxCapacity = _maxCapacity;
    data.resize(maxCapacity);
    currentSize = 0;
}

template <class T>
MaxHeap<T>::~MaxHeap(){
    maxCapacity = 0;
    currentSize = 0;
    data.clear();
}

template <class T>
bool MaxHeap<T>::isEmpty(){
    return (currentSize <= 0);
}

template <class T>
int MaxHeap<T>::getMaxCapacity(){
    return maxCapacity;
}

template <class T>
int MaxHeap<T>::getCurrentSize(){
    return currentSize;
}

template <class T>
void MaxHeap<T>::print(){
    std::cout << "Contenido del maxheap:" << std::endl;

    for (int i = 0; i < currentSize; i++){
        std::cout << data[i] << " ";
    }

    std::cout << std::endl;
}

template <class T>
void MaxHeap<T>::saveHeap(std::string direccionArch){
    std::ofstream archivo(direccionArch);

    if (!archivo.is_open()){
        archivo.close();
        throw std::invalid_argument("No fue posible acceder al archivo.");
    }

    for (int i = 0; i < currentSize; i++){
        archivo << data[i] << "\n";
    }

    archivo.close();
}

template <class T>
int MaxHeap<T>::parent(int k){
    return (k - 1) / 2;
}

template <class T>
int MaxHeap<T>::left(int k){
    return (2 * k + 1);
}

template <class T>
int MaxHeap<T>::right(int k){
    return (2 * k + 2);
}

template <class T>
void MaxHeap<T>::push(T key){

    try{
        if (currentSize == maxCapacity){
            throw std::out_of_range("Overflow: no se puede insertar la llave");
        }

        int k = currentSize;
        data[k] = key;
        currentSize++;

        while (k != 0 && data[parent(k)] < data[k]){
            std::swap(data[k], data[parent(k)]);
            k = parent(k);
        }
    }

    catch (const std::exception &e){
        std::cout << "Error: " << e.what() << std::endl;
    }
}

template <class T>
T MaxHeap<T>::getTop(){

    try{
        if (isEmpty()){
            throw std::out_of_range("El heap esta vacio");
        }

        return data[0];
    }

    catch (const std::exception &e){
        std::cout << "Error: " << e.what() << std::endl;
        return {};
    }
}

template <class T>
void MaxHeap<T>::heapSort(std::vector<T> &vectorRegistros, int n, unsigned int &comparacion, unsigned int &intercambio){
    comparacion = intercambio = 0;
 
    for (int i = n / 2 - 1; i >= 0; i--){
        heapifyHelper(vectorRegistros, n, i, comparacion, intercambio);
    }

    for (int i = n - 1; i > 0; i--){
        std::swap(vectorRegistros[0], vectorRegistros[i]);
        intercambio++;
        heapifyHelper(vectorRegistros, i, 0, comparacion, intercambio);
    }
}

template <class T>
void MaxHeap<T>::heapifyHelper(std::vector<T> &vectorRegistros, int n, int k, unsigned int &comparacion, unsigned int &intercambio){
    int largest = k;
    int left = 2 * k + 1;
    int right = 2 * k + 2;

    if (left < n && vectorRegistros[left] > vectorRegistros[largest])
        largest = left;

    if (right < n && vectorRegistros[right] > vectorRegistros[largest])
        largest = right;
        
    comparacion += 2;

    if (largest != k){
        std::swap(vectorRegistros[k], vectorRegistros[largest]);
        intercambio++;
        heapifyHelper(vectorRegistros, n, largest, comparacion, intercambio);
    }
}

template <class T>
void MaxHeap<T>::pop(){

    try{
        if (isEmpty()){
            throw std::out_of_range("El heap está vacío");
        }

        std::swap(data[0], data[currentSize - 1]);
        currentSize--;
        heapifyPop(0);
    }

    catch (const std::exception &e){
        std::cout << "Error: " << e.what() << std::endl;
    }
}

template <class T>
void MaxHeap<T>::heapifyPop(int k){
    unsigned int comparacionPop, intercambioPop = 0;
    heapifyHelper(data, currentSize, k, comparacionPop, intercambioPop);
}

#endif //_MAXHEAP_H_