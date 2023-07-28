#ifndef _NODELINKEDLIST_H_
#define _NODELINKEDLIST_H_

template <class T>
class NodeLinkedList{
public:
    T data;
    NodeLinkedList<T> *next;

    /*
     * Descripción:
     *      Constructor sin parámetros el cual crea un nodo de la lista
     *      enlazada sin asignar un valor específico. La inicialización se
     *      realiza utiizando la lista de inicialización.
     *
     * Parámetros de entrada:
     *      No posee parámetros.
     *
     * Valor de retorno:
     *      No retorna ningún valor.
     *
     * Complejidad Temporal:
     *      O(1)
     */

    NodeLinkedList();

    /*
     * Descripción:
     *      Constructor con parámetros el cual permite crear nodos de la
     *      lista enlazada y asignar un valor específico. La inicialización
     *      se realiza utilizando la lista de inicialización.
     *
     * Parámetros de entrada:
     *      @value, parámetro de cualquier tipo T utilizado para asignar un
     *      valor específico al miembro de datos "data" del nodo de la lista
     *      enlazada.
     *
     * Valor de retorno:
     *      No retorna ningún valor.
     *
     * Complejidad Temporal:
     *      O(1)
     */

    NodeLinkedList(T value);
};

template <class T>
NodeLinkedList<T>::NodeLinkedList() : data{}, next{nullptr} {}

template <class T>
NodeLinkedList<T>::NodeLinkedList(T value) : data{value}, next{nullptr} {}

#endif // _NODELINKEDLIST_H_
