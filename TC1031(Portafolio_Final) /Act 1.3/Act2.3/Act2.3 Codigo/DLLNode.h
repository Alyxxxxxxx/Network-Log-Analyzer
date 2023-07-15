#ifndef _DLLNODE_H_
#define _DLLNODE_H_

template <class T>
class DLLNode{
    public:
        T data;
        DLLNode<T> *next;
        DLLNode<T> *prev;

    /*
        * Constructor sin parámetros el cual crea un nodo de la lista
        * enlazada doble sin asignar un valor específico. La inicialización
        * se realiza utilizando la lista de inicialización.
        *
        * Parámetros: No posee parámetros.
        *
        * Valor de retorno: No retorna ningún valor.
        *
        * Complejidad temporal: O(1)
        */

        DLLNode();

    /*
        * Constructor con parámetros el cual permite crear nodos de la
        * lista enlazada doble y asignar un valor específico. La inicialización
        * se realiza utilizando la lista de inicialización.
        *
        * Parámetro: @valor, parámetro de cualquier tipo T utilizado para asignar 
        * un valor específico al miembro de datos "data" del nodo de la lista
        * enlazada doble.
        *
        * Valor de retorno: No retorna ningún valor.
        *
        * Complejidad temporal: O(1)
        */

        DLLNode(T value);
};

template <class T>
DLLNode<T>::DLLNode() : data{}, next{nullptr}, prev{nullptr} {}

template <class T>
DLLNode<T>::DLLNode(T value) : data{value}, next{nullptr}, prev{nullptr} {}

#endif // _DLLNODE_H