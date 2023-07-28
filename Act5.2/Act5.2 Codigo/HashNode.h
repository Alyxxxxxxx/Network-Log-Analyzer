#ifndef _HASH_NODE_H_
#define _HASH_NODE_H_

#include <vector>
#include <algorithm>
#include <iterator>

template <class K, class T>
class HashNode{
private:
    K key;
    T data;
    int status;                // 0 empty,  1 used,  2 deleted
    std::vector<int> overflow; 

public:
    /*
     * Descripión:
     *      Constructor predeterminado de la clase HashNode. El constructor se utiliza para 
     *      inicializar los miembros que pertenecen a la representación de un elemento 
     *      en una Tabla Hash.
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

    HashNode();

    /*
     * Descripión:
     *      Destructor de la clase HashNode que se encarga de liberar los recursos asociados 
     *      con un objeto HashNode al eliminarlo.
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

    ~HashNode();

    /*
     * Descripión: getKey()
     *       Método utilizado para obtener la clave (key) asociada al nodo de la tabla hash.
     *
     * Parámetros de entrada:
     *      No posee parámetros de entrada.
     *
     * Valor de retorno:
     *      Devuelve un valor de tipo K, que representa la clave almacenada en el nodo de la tabla hash.
     *
     * Complejidad temporal:
     *      O(1)
     */

    K getKey();

    /*
     * Descripión: getData()
     *       Método utilizado para obtener el valor (data) asociado al nodo de la tabla hash.
     *
     * Parámetros de entrada:
     *      No posee parámetros de entrada.
     *
     * Valor de retorno:
     *      Devuelve un valor de tipo T, que representa el valor almacenado en el nodo de la tabla hash.
     *
     * Complejidad temporal:
     *      O(1)
     */

    T getData();

    /*
     * Descripión: getStatus()
     *       Método utilizado para obtener el estado del nodo en la tabla hash, que puede ser
     *       "vacío" (empty), "usado" (used) o "eliminado" (deleted).
     *
     * Parámetros de entrada:
     *      No posee parámetros de entrada.
     *
     * Valor de retorno:
     *      La función devuelve un valor entero que representa el estado del nodo en la tabla hash. 
     *      Los posibles valores de retorno son:
     * 
     *      - 0: Indica que el nodo está vacío (empty), es decir, no contiene ningún dato válido.
     * 
     *      - 1: Indica que el nodo está siendo utilizado (used) y contiene datos válidos.
     * 
     *      - 2: Indica que el nodo fue marcado como eliminado (deleted). 
     *
     * Complejidad temporal:
     *      O(1)
     */

    int getStatus();

    /*
     * Descripión: setKey()
     *       Método utilizado para establecer la clave (key) asociada al nodo de la tabla hash.
     *
     * Parámetros de entrada:
     *      @keyValue: entrada de tipo K, que representa la nueva clave que se desea asignar 
     *      al nodo de la tabla hash.
     *
     * Valor de retorno:
     *      No retorna ningún valor.
     *
     * Complejidad temporal:
     *      O(1)
     */

    void setKey(K keyValue);

    /*
     * Descripión: setData()
     *       Método utilizado para establecer el valor (data) asociado al nodo de la tabla hash
     *       y, al mismo tiempo, marcar el nodo como "usado" (status = 1).
     *
     * Parámetros de entrada:
     *      @dataValue: entrada de tipo T, que representa el nuevo valor que se desea asignar 
     *      al nodo de la tabla hash.
     *
     * Valor de retorno:
     *      No retorna ningún valor.
     *
     * Complejidad temporal:
     *      O(1)
     */

    void setData(T dataValue);

    /*
     * Descripión: setStatus()
     *       Método utilizado para establecer el estado del nodo en la tabla hash.
     *
     * Parámetros de entrada:
     *      @statusValue: entrada de tipo int, que representa el nuevo estado que se
     *      desea asignar al nodo de la tabla hash. Los posibles valores para el estado son:
     *      0 empty,  1 used,  2 deleted
     *
     * Valor de retorno:
     *      No retorna ningún valor.
     *
     * Complejidad temporal:
     *      O(1)
     */

    void setStatus(int statusValue);

    /*
     * Descripión: clearData()
     *      Método utilizado para  "borrar" los datos del nodo de la tabla hash y marcar el nodo
     *      como "eliminado" (status = 2).
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

    void clearData();

    /*
     * Descripión: addToOverFlow()
     *      Método utilizado para agregar un índice adicional a la lista de desbordamiento (overflow)
     *      en el nodo de la tabla hash. La lista de desbordamiento es un contenedor que se utiliza 
     *      para almacenar índices adicionales cuando se produce una colisión en la tabla hash y se 
     *      necesita almacenar más de un elemento en la misma posición. Cada índice en la lista de 
     *      desbordamiento indica la posición de otro nodo en la tabla hash que ha sido desplazado 
     *      debido a una colisión.
     *
     * Parámetros de entrada:
     *      @hashIndex: entrada de tipo int, que representa el índice que se desea agregar a la lista
     *      de desbordamiento (overflow) del nodo.
     *
     * Valor de retorno:
     *      No retorna ningún valor.
     *
     * Complejidad temporal:
     *      O(1)
     */

    void addToOverflow(int hashIndex);

    /*
     * Descripión: getOverflowSize()
     *      Método utilizado para obtener el tamaño de la lista de desbordamiento (overflow) del nodo en la
     *      tabla hash.  Proporciona una forma sencilla y eficiente de obtener el tamaño de la lista de desbordamiento
     *      en el nodo de la tabla hash. Al tener una complejidad constante, la función ofrece un acceso rápido y
     *      directo para obtener la cantidad de índices adicionales almacenados en la lista de desbordamiento, lo
     *      que puede ser útil para comprender el manejo de colisiones y el rendimiento general de la tabla hash.
     *
     * Parámetros de entrada:
     *      No posee parámetros de entrada.
     *
     * Valor de retorno:
     *      Devuelve un valor entero que representa el tamaño de la lista de desbordamiento (overflow) en el nodo
     *      de la tabla hash. El valor retornado indica cuántos índices adicionales se han almacenado en la lista 
     *      de desbordamiento debido a colisiones en la tabla hash.
     *
     * Complejidad temporal:
     *      O(1)
     */

    int getOverflowSize();

    /*
     * Descripión: getOverflowAt()
     *      Método utilizado para obtener el índice almacenado en la posición especificada de la lista de
     *      desbordamiento (overflow) en el nodo de la tabla hash.
     *
     * Parámetros de entrada:
     *      @index:  entrada de tipo int que representa la posición en la lista de desbordamiento
     *      (overflow) de la que se desea obtener el índice.
     *
     * Valor de retorno:
     *      Devuelve un valor entero (int) que representa el índice almacenado en la posición especificada 
     *      de la lista de desbordamiento (overflow) del nodo.
     *
     * Complejidad temporal:
     *      O(1)
     */

    int getOverflowAt(int index);

    /*
     * Descripión: removeFromOverflow()
     *      Método utilizado para  eliminar un índice específico de la lista de desbordamiento (overflow) en el
     *      nodo de la tabla hash. Busca el índice especificado (index) en la lista de desbordamiento utilizando 
     *      std::find(), y si lo encuentra, lo elimina utilizando std::vector::erase(). Si el índice no se encuentra 
     *      en la lista de desbordamiento, no se realiza ninguna operación.
     * 
     * Parámetros de entrada:
     *      @index: entrada de tipo int que representa el índice que se desea eliminar de la lista de desbordamiento
     *      (overflow) del nodo.
     *
     * Valor de retorno:
     *      No retorna ningún valor.
     *
     * Complejidad temporal:
     *      O(n) o O(n^2) en el peor caso.
     */

    void removeFromOverflow(int index);
};

template <class K, class T>
HashNode<K, T>::HashNode(){
    key = 0;
    data = {};
    status = 0; 
    overflow.clear();
}

template <class K, class T>
HashNode<K, T>::~HashNode(){
    key = 0;
    data = {};
    status = 0; 
    overflow.clear();
}

template <class K, class T>
K HashNode<K, T>::getKey(){
    return key;
}

template <class K, class T>
T HashNode<K, T>::getData(){
    return data;
}

template <class K, class T>
int HashNode<K, T>::getStatus(){
    return status;
}

template <class K, class T>
void HashNode<K, T>::setKey(K keyValue){
    key = keyValue;
}

template <class K, class T>
void HashNode<K, T>::setData(T dataValue){
    data = dataValue;
    status = 1; 
}

template <class K, class T>
void HashNode<K, T>::setStatus(int statusValue){
    status = statusValue;
}

template <class K, class T>
void HashNode<K, T>::clearData(){
    data = {};
    status = 2; 
}

template <class K, class T>
void HashNode<K, T>::addToOverflow(int hashIndex){
    overflow.push_back(hashIndex);
}

template <class K, class T>
int HashNode<K, T>::getOverflowSize(){
    return overflow.size();
}

template <class K, class T>
int HashNode<K, T>::getOverflowAt(int index){
    return overflow[index];
}

template <class K, class T>
void HashNode<K, T>::removeFromOverflow(int index){
    std::vector<int>::iterator it = std::find(overflow.begin(), overflow.end(), index);
 
    if (it != overflow.end()){
        overflow.erase(overflow.begin() + (it - overflow.begin()));
    }
}

#endif // _HASH_NODE_H_