#ifndef _HASH_TABLE_H_
#define _HASH_TABLE_H_

#include <vector>
#include <iostream>
#include <stdexcept>
#include "HashNode.h"

template <class K, class T>
class HashTable{
private:
    std::vector<HashNode<K, T>> table;
    int numElements;
    int numCollisions;
    int maxSize;

public:

    /*
     * Descripión:
     *      Constructor de la clase HashTable, que se utiliza para inicializar un
     *      objeto de la clase y crear la tabla hash con un tamaño inicial especificado 
     *      por maxSize.
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

    HashTable();

    /*
     * Descripión:
     *      Destructor de la clase utilizado para liberar los recursos y limpiar la 
     *      memoria asignada durante el ciclo de vida del objeto HashTable. En este caso, 
     *      el destructor se encarga de resetear las variables miembro y liberar la 
     *      memoria asignada al vector table.
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

    ~HashTable();

    /*
     * Descripión: setMaxSize()
     *      Método utilizado para establecer el tamaño máximo de la tabla hash y realizar
     *      una reestructuración apropiada cuando se cambia el tamaño. La función asigna
     *      un nuevo tamaño máximo a la tabla y crea un nuevo vector de nodos hash (table)
     *      con el nuevo tamaño, eliminando cualquier contenido anterior.
     *
     * Parámetros de entrada:
     *      @selectedMaxSize: un número entero que representa el nuevo tamaño máximo 
     *      deseado para la tabla hash.
     *
     * Valor de retorno:
     *      No retorna ningún valor.
     *
     * Complejidad temporal:
     *      O(n)
     */

    void setMaxSize(int selectedMaxSize);

    /*
     * Descripión: getHashIndex()
     *      Método utilizado para calcular el índice de hash de una clave (keyValue)
     *      en la tabla hash. El índice de hash se utiliza para determinar la posición
     *      en la tabla donde se almacenará o buscará el valor asociado a la clave
     *
     * Parámetros de entrada:
     *      @keyValue: que es la clave para la cual se desea calcular el índice de hash. 
     *      La clave (K) puede ser de cualquier tipo de datos que sea válido para el 
     *      operador % (módulo).
     *
     * Valor de retorno:
     *      El método devuelve un valor entero que representa el índice de hash calculado 
     *      para la clave keyValue.
     *
     * Complejidad temporal:
     *      O(1)
     */

    int getHashIndex(K keyValue);

    /*
     * Descripión: getNumElements()
     *      Método utilizado para obtener el número actual de elementos almacenados en
     *      la tabla hash.
     *
     * Parámetros de entrada:
     *      No posee parámetros de entrada.
     *
     * Valor de retorno:
     *      El método devuelve un valor entero que representa el número actual de elementos
     *      almacenados en la tabla hash.
     *
     * Complejidad temporal:
     *      O(1)
     */

    int getNumElements();

    /*
     * Descripión: print()
     *      Método utilizado para imprimir el contenido de la tabla hash en la consola, mostrando
     *      las celdas ocupadas con sus respectivas claves, valores y tamaños de desbordamiento.
     *
     * Parámetros de entrada:
     *      No posee parámetros de entrada.
     *
     * Valor de retorno:
     *      No retorna ningún valor.
     *
     * Complejidad temporal:
     *      O(n) donde n es el tamaño de la tabla hash.
     */

    void print();

    /*
     * Descripión: add()
     *      Método utilizado para agregar un nuevo elemento a la tabla hash. Si la tabla está
     *      llena o si la clave ya existe en la tabla, se lanzan excepciones para manejar estos
     *      casos de error. Si la celda en el índice de hash ya está ocupada, se debe manejar
     *      una colisión utilizando el método de "doble dispersión cuadrática". Esto implica
     *      un bucle while que busca una celda vacía en la tabla utilizando cálculos basados
     *      en la dispersión cuadrática.
     *
     * Parámetros de entrada:
     *      @keyValue: representa la clave del nuevo elemento que se agregará a la tabla.
     *
     *      @dataValue: es el valor asociado a esa clave que se almacenará en la tabla.
     *
     * Valor de retorno:
     *      No retorna ningún valor.
     *
     * Complejidad temporal:
     *      La complejidad temporal en el caso promedio de el método add sería cercana a
     *      O(1 + factor de carga) (proporción entre el número de elementos almacenados en 
     *      la tabla hash y el tamaño total de la tabla). Sin embargo, en el peor escenario, 
     *      cuando hay muchas colisiones, la complejidad temporal podría acercarse a O(n).
     */

    void add(K keyValue, T dataValue);

    /*
     * Descripión: find()
     *      Método utilizado para buscar una clave (keyValue) en la tabla hash y devolver el
     *      índice donde se encuentra el elemento. Si la clave no se encuentra en la tabla,
     *      el método devuelve -1 para indicar que la búsqueda no tuvo éxito.
     *
     * Parámetros de entrada:
     *      keyValue: la clave que se desea buscar en la tabla hash.
     *
     * Valor de retorno:
     *      El método devuelve un valor entero que representa el índice donde se encuentra el
     *      elemento con la clave keyValue. Si la clave no se encuentra en la tabla, el método
     *      devuelve -1.
     *
     * Complejidad temporal:
     *      En el mejor caso, cuando no hay colisiones y la clave se encuentra en la celda principal, 
     *      la complejidad es O(1). En el peor caso, cuando todas las celdas tienen desbordamientos 
     *      y se realiza una búsqueda en todas las celdas de desbordamiento, la complejidad es 
     *      O(node.getOverflowSize()).
     */

    int find(K keyValue);

    /*
     * Descripión: getDataAt()
     *      Método utilizado para obtener el valor (data) asociado a un elemento de la tabla hash
     *      en un índice específico (index).
     *
     * Parámetros de entrada:
     *      @index: el índice de la tabla hash donde se encuentra el elemento cuyo valor se desea 
     *      obtener.
     *
     * Valor de retorno:
     *      Devuelve un valor de tipo T, que representa el valor asociado al elemento en el índice 
     *      index de la tabla hash.
     *
     * Complejidad temporal:
     *      O(1)
     */

    T getDataAt(int index);

    /*
     * Descripión: remove()
     *      Método utilizado para eliminar un elemento de la tabla hash que tiene una clave
     *      específica (keyValue). Si la clave no se encuentra en la tabla, se lanza una excepción
     *      indicando que el elemento no existe. Si el índice del elemento a eliminar (pos) es
     *      diferente del índice de hash (hashIndex), significa que el elemento está en una celda
     *      de desbordamiento y no en la celda principal. En este caso, la función elimina el índice
     *      pos de la lista de desbordamientos de la celda principal (hashIndex). Esta operación
     *      implica utilizar el método removeFromOverflow de la clase HashNode.
     *
     * Parámetros de entrada:
     *      @keyValue: la clave del elemento que se desea eliminar de la tabla hash.
     *
     * Valor de retorno:
     *       No retorna ningún valor.
     *
     * Complejidad temporal:
     *       En situaciones normales, donde no hay muchas colisiones y la tabla no está completamente 
     *       llena, la complejidad suele ser cercana a O(1) para la mayoría de las eliminaciones. 
     *       Sin embargo, en el peor caso, cuando todas las celdas tienen desbordamientos y se debe 
     *       recorrer una lista de desbordamientos grande, la complejidad puede aumentar hasta O(n) 
     *       (donde n es el número total de elementos en la tabla).
     */

    void remove(K keyValue);

    /*
     * Descripión: getNumCollisions()
     *      Método utilizado para obtener el número total de colisiones que han ocurrido en la tabla
     *      hash.
     *
     * Parámetros de entrada:
     *      No posee parámetros de entrada.
     *
     * Valor de retorno:
     *      La función devuelve un valor entero que representa el número total de colisiones que han
     *      ocurrido en la tabla hash. Se cuenta una colisión cada vez que se realiza un intento de 
     *      resolución de colisiones en el bucle de while encontrado en el método add()
     *
     * Complejidad temporal:
     *      O(1)
     */

    int getNumCollisions();
};

template <class K, class T>
HashTable<K, T>::HashTable(){
    maxSize = 0;
    numElements = 0;
    numCollisions = 0;
    table = std::vector<HashNode<K, T>>(maxSize);
}

template <class K, class T>
HashTable<K, T>::~HashTable(){
    maxSize = 0;
    numElements = 0;
    numCollisions = 0;
    table = std::vector<HashNode<K, T>>(maxSize);
}

template <class K, class T>
void HashTable<K, T>::setMaxSize(int selectedMaxSize){
    maxSize = selectedMaxSize;
    numElements = 0;
    numCollisions = 0;
    table = std::vector<HashNode<K, T>>(maxSize);
}

template <class K, class T>
int HashTable<K, T>::getHashIndex(K keyValue){
    return keyValue % maxSize;
}

template <class K, class T>
int HashTable<K, T>::getNumElements(){
    return numElements;
}

template <class K, class T>
void HashTable<K, T>::print(){
    std::cout << "Contenido de la tabla hash" << std::endl;

    for (int i = 0; i < maxSize; i++){

        if (table[i].getStatus() == 1){
            std::cout << "Celda: " << i << " Key: " << table[i].getKey() << ", Value: " << table[i].getData() << ", Overflow.size: " << table[i].getOverflowSize() << std::endl;
        }
    }
}

template <class K, class T>
void HashTable<K, T>::add(K keyValue, T dataValue){

    if (numElements == maxSize){
        throw std::out_of_range("La hash table esta llena");
    }

    if (find(keyValue) != -1){
        throw std::out_of_range("El elemento ya existe en la tabla hash");
    }

    int hashIndex = getHashIndex(keyValue);
    HashNode<K, T> node = table[hashIndex];

    if (node.getStatus() != 1){ 
        node.setKey(keyValue);
        node.setData(dataValue);
        table[hashIndex] = node;
    }

    else{
        int i = 1;
        int currentHashIndex = getHashIndex(hashIndex + i * i);
        HashNode<K, T> currentNode = table[currentHashIndex];

        while (currentNode.getStatus() == 1){
            i++;
            currentHashIndex = getHashIndex(hashIndex + i * i);
            currentNode = table[currentHashIndex];
            numCollisions++;
        }

        currentNode.setKey(keyValue);
        currentNode.setData(dataValue);
        node.addToOverflow(currentHashIndex);
        table[currentHashIndex] = currentNode;
        table[hashIndex] = node;
    }
    numElements++;
}

template <class K, class T>
int HashTable<K, T>::find(K keyValue){
    int hashIndex = getHashIndex(keyValue);
    HashNode<K, T> node = table[hashIndex];

    if (node.getStatus() == 1){

        if (node.getKey() == keyValue)
            return hashIndex;

        for (int i = 0; i < (int)node.getOverflowSize(); i++){
            int overflowIndex = node.getOverflowAt(i);

            if (table[overflowIndex].getKey() == keyValue)
                return overflowIndex;
        }

        return -1;
    }
    
    return -1;
}

template <class K, class T>
T HashTable<K, T>::getDataAt(int index){
    return table[index].getData();
}

template <class K, class T>
int HashTable<K, T>::getNumCollisions(){
    return numCollisions;
}

template <class K, class T>
void HashTable<K, T>::remove(K keyValue){
    int pos, hashIndex;
    pos = find(keyValue);

    if (pos == -1){
        throw std::out_of_range("El elemento no existe en la tabla hash");
    }

    hashIndex = getHashIndex(keyValue);

    if (pos != hashIndex){
        HashNode<K, T> node = table[hashIndex];
        node.removeFromOverflow(pos);
        table[hashIndex] = node;
    }

    table[pos].clearData();
    numElements--;
}

#endif // _HASH_TABLE_H_