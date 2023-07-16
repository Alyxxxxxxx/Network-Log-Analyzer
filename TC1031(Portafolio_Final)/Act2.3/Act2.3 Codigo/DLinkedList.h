#ifndef _DOUBLELINKEDLIST_H_
#define _DOUBLELINKEDLIST_H_

#include <iostream>
#include <stdexcept>
#include "DLLNode.h"
#include "Registro.h"

template <class T>
class DLinkedList{

    private:
        DLLNode<T> *head;
        DLLNode<T> *tail;
        int numElements;

       /* 
        * merge(): Combina dos sublistas ordenadas en una sola lista ordenada
        * a través de un enfoque recursivo. Forma parte del algoritmo que da 
        * solución al ordenamiento adecuado de la lista.
        *
        * Parámetros:
        * @first, puntero que apunta al primer nodo de la priemra sublista
        * ordenada.
        * 
        * @second, puntero que apunta al primer nodo de la segunda sublista
        * ordenada.
        *
        * Valor de retorno: puntero al nodo que representa el inicio de la
        * lista combinada y ordenadda.
        * 
        * Complejidad temporal: O(n)
        */

        DLLNode<T> *merge(DLLNode<T> *first, DLLNode<T> *second);

       /*
        * splitList(): divide una lista doblemente enlazada en dos mitades
        * aproximadamente iguales a través del algoritmo conocido como
        * "tortuga y liebre".
        *
        * Parámetros: @head, un puntero al nodo inicial de la lista doblemente
        * enlazada que se desea dividir. 
        * 
        * Valor de retorno: puntero al nodo que repreenta el inicio de la segunda 
        * mitad de la lista, es decir, el nodo siguiente al nodo medio.
        * 
        * Complejidad temporal: O(n)
        */

        DLLNode<T> *splitList(DLLNode<T> *head);

       /*
        * mergeSort(): implementa el algoritmo de ordenación Merge Sort en
        * una lista doblemente enlazada. Divide la lista en mitades, aplica 
        * recursivamente Merge Sort en las mitades, y luego combina las mitades 
        * ordenadas en una única lista ordenada.
        * 
        * Parámetro: @headRef,  Un puntero doble que apunta al puntero al nodo 
        * inicial de la lista doblemente enlazada que se desea ordenar
        *
        * Valor de retorno: No retorna ningún valor.
        * 
        * Complejidad temporal: O(n log n)
        */

        void mergeSort(DLLNode<T> **headRef);

       /*
        * medio(): encuentra el nodo medio entre dos nodos dados
        * (start y last) en la lista. Es un método auxiliar y
        * wraper de binarySearch.
        * 
        * Parámetros: 
        * @start, puntero de nodo tipo DLLNode que representa el
        * nodo inicial desde el cual se comenzará a buscar el nodo
        * medio. Es el punto de partida para el algoritmo de búsqueda.
        * 
        * @last, puntero de nodo tipo DLLNode que representa el
        * nodo final hasta el cual se buscará el nodo medio. Es
        * el límite superior del espacio de búsqueda.
        * 
        * Valor de retorno: puntero al nodo medio encontrado entre los
        * nodos stary y last en la lista.
        * 
        * Complejidad temporal: O(n/2)
        */

        DLLNode<T> *medio(DLLNode<T> *start, DLLNode<T> *last);

    public:

       /*
        * Constructor de la clase DLinkedList. Inicializa los miembros de datos
        * head y tail a nullptr, y el número de elementos a 0.
        *
        * Parámetros: No recibe ningún parámetro.
        * 
        * Valor de retorno: Al ser constructor no retorna ningún valor.
        * 
        * Complejidad tempora: O(1)
        */
        DLinkedList();

       /*
        * Destructor de la clase DLinkedList. Libera la memoria ocupada por los nodos
        * de la lista enlazada.
        *
        * Parámetros: No recibe ningún parámetro.
        * 
        * Valor de retorno: Al ser destructor no retorna ningún valor.
        * 
        * Complejidad temporal: O(n)
        */

        ~DLinkedList();
    
       /*
        * addFirst(T value): Agrega un elemento al principio de la lista.
        *
        * Parámetro: @value, el valor del elemento a agregar, de variable.
        * tipo T.
        * 
        * Valor de retorno: No retorna ningún valor.
        * 
        * Complejidad temporal: O(1)
        */

        void addFirst(T value);

       /*
        * addLast(T value): Agrega un elemento al final de la lista.
        *
        * Parámetro: @value, el valor del elemento a agregar, de variable
        * tipo T.
        * 
        * Valor de retorno: No retorna ningún valor.
        * 
        * Complejidad temporal: O(1)
        */

        void addLast(T value);

       /*
        * getNumElements(): Obtiene el número de elementos en la lista.
        *
        * Parámetro: No recibe ningún parámetro.
        * 
        * Valor de retorno: Variable de tipo entero, retorna el número 
        * de elementos en la lista.
        * 
        * Complejidad temporal: O(1)
        */

        int getNumElements();

       /*
        * printList(): Imprime los elementos de la lista auxiliándose
        * del método de la clase Registro.
        * 
        * Parámetro: No recibe ningún parámetro.
        * 
        * Valor de retorno: No retorna ningún valor.
        * 
        * Complejidad temporal: O(n)
        */

        void printList();

       /*
        * saveList(): guarda la lista en un archivo cuyo nombre es
        * indicado por el usuario. Se auxilia del método de la clase
        * Registro para acceder a los elementos de la lista.
        * 
        * Parámetro: @nombreArch, variable de tipo string, nombre del
        * archivo donde se desea guardar la lista.
        * 
        * Valor de retorno: no retorna ningún valor.
        * 
        * Complejidad temporal: O(n)
        */

        void saveList(std::string nombreArch);

       /*
        * binarySearch(): realiza una búsqueda de tipo binaria dentro
        * de la lista y verifica la existencia del elemento que el
        * usuario le indique.
        *
        * Parámetro: @fechaBuscada, variable de tipo T, el elemento
        * de la lista que se desea buscar.
        * 
        * Valor de retorno: puntero de instancia de la clase DLLNode,
        * el cual representa el nodo de la lista que se busca. En caso
        * de que no se encuentre el elemento buscado el puntero se iguala
        * a nullptr.
        * 
        * Complejidad temporal: O(log n)
        */

        DLLNode<T>* binarySearch(T fechaBuscada);

       /*
        * mSort(): Método wraper. Ordena una lista enlazada doble por medio del algoritmo 
        * de ordenamiento Merge Sort.
        * 
        * Parámetros: no recibe ningún parámetro.
        *
        * Valor de retorno: no retorna ningún valor.
        * 
        * Complejidad temporal: O(n log n)
        */

        void mSort();
    
       /*
        * getSublist(): Crea una sublista dado un nodo inicial y final
        * de la lista, especificado por el usuario. Se auxilia del método
        * de la misma clase addLast para añadir los elementos deseados en
        * la nueva sublista.
        * 
        * Parámetros:
        * @newList, [parámetro por referencia] lista de tipo DLinkedList en 
        * la cual se almacenarán los registros que estén dentro del rango
        * especificado.
        * 
        * @fechaInicio, puntero de un nodo DLLNode el cual posee el elemento 
        * inicial que delimita el rango.
        * 
        * @fechaFin, puntero de un nodo DLLNode el cual posee el elemento 
        * final que delimita el rango.
        * 
        * Complejidad temporal: O(k) donde k es el número de nodos dentro del rango 
        * fechaInicio y fechaFin.
        */

        void getSublist(DLinkedList<T> &newList, DLLNode<T> *fechaInicio, DLLNode<T> *fechaFin);

       /*
        * restartList(): reinicia una lista doblemente enlazada al eliminar todos los
        * nodos de la lista y restablecer los punteros "head", "tail", y "numElements"
        * a sus valores iniciales.
        * 
        * Parámetros: no posee parámetros.
        * 
        * Valor de retorno: no retorna ningún valor.
        * 
        * Complejidad temporal: O(n), donde n es el número de nodos en la lista.
        */

        void restartList();
};

template <class T>
DLinkedList<T>::DLinkedList(){
    head = nullptr;
    tail = nullptr;
    numElements = 0;
}

template <class T>
DLinkedList<T>::~DLinkedList(){

    DLLNode<T> *p, *q;
    p = head;

    while (p != nullptr){
        q = p->next;
        delete p;
        p = q;
    }

    head = nullptr;
    tail = nullptr;
    numElements = 0;
}

template <class T>
void DLinkedList<T>::addFirst(T value){

    DLLNode<T> *newNode = new DLLNode<T>(value);

    if (head == nullptr && tail == nullptr){
        head = newNode;
        tail = newNode;
    }

    else{
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    numElements++;
}

template <class T>
void DLinkedList<T>::addLast(T value){

    if (head == nullptr && tail == nullptr){
        addFirst(value);
    }

    else{
        DLLNode<T> *newNode = new DLLNode<T>(value);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        numElements++;
    }
}

template <class T>
int DLinkedList<T>::getNumElements(){
    return numElements;
}

template <class T>
void DLinkedList<T>::printList(){

    if (head == nullptr && tail == nullptr){
        std::cout << "La lista esta vacia" << std::endl;
    }

    else{
        std::cout << "Presione [ENTER] para mostrar el contenido de la lista... ";
        std::cin.ignore();
        DLLNode<T> *p = head;

        while (p != nullptr){
            std::cout << p -> data.imprimirDatos() << std::endl;
            p = p -> next;
        }

        std::cout << std::endl;
    }
}

template <class T>
void DLinkedList<T>::saveList(std::string nombreArch){
    std::ofstream archivo(nombreArch);

    try{
        if (!archivo.is_open()){
            throw std::invalid_argument("No fue posible acceder al archivo.");
        }

        else{
            DLLNode<T> *p = head;

            while (p != nullptr){
                archivo << p -> data.imprimirDatos() << std::endl;
                p = p->next;
            }

            archivo.close();
            std::cout << "La bitacora ha sido guardada con exito en el archivo " << nombreArch << std::endl;
        }
    }

    catch (const std::exception &e){
        archivo.close();
        std::cout << "Error: " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
}

template <class T>
DLLNode<T>* DLinkedList<T>::binarySearch(T fechaBuscada){
    DLLNode<T> *start = head;
    DLLNode<T> *last = nullptr;

    do{
        DLLNode<T> *mid = medio(start, last);
        if (mid == nullptr){
            return nullptr;
        }
           
        if (mid->data ==fechaBuscada){
            std::cout << "¡Se encontro con exito la entrada ingresada!" << std::endl;
            return mid;
        }

        else if (mid->data < fechaBuscada){

            start = mid->next;
        }

        else{
            last = mid;
        }

    } while (last == nullptr || last != start);

    return nullptr;
}

template <class T>
DLLNode<T> *DLinkedList<T>::medio(DLLNode<T> *start, DLLNode<T> *last){
   
    if (start == nullptr){
        return nullptr;
    }

    DLLNode<T> *slow = start;
    DLLNode<T> *fast = start->next;

    while (fast != last){
        fast = fast->next;

        if (fast != last){
            slow = slow->next;
            fast = fast->next;
        }
    }

    return slow;
}

template <class T>
void DLinkedList<T>::mergeSort(DLLNode<T> **headRef){
    DLLNode<T> *head = *headRef;

    if (head == nullptr || head->next == nullptr){
        return;
    }

    DLLNode<T> *second_half = splitList(head);

    mergeSort(&head);
    mergeSort(&second_half);

    *headRef = merge(head, second_half);
}

template <class T>
void DLinkedList<T>::mSort(){
    mergeSort(&head);
}

template <class T>
DLLNode<T>* DLinkedList<T>::merge(DLLNode<T> *first, DLLNode<T> *second){
    if (first == nullptr){
        return second;
    }
    if (second == nullptr){
        return first;
    }

    if (first->data <= second->data){
        first->next = merge(first->next, second);
        first->next->prev = first;
        first->prev = nullptr;
        return first;
    }

    else{
        second->next = merge(first, second->next);
        second->next->prev = second;
        second->prev = nullptr;
        return second;
    }
}

template <class T>
DLLNode<T>* DLinkedList<T>::splitList(DLLNode<T> *head){
    DLLNode<T>* slow = head;
    DLLNode<T>* fast = head;

    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    DLLNode<T> *second_half = slow->next;
    slow->next = nullptr;
    return second_half;
}


template <class T>
void DLinkedList<T>::getSublist(DLinkedList<T> &newList, DLLNode<T> *fechaInicio, DLLNode<T> *fechaFin){
    DLLNode<T> *p = fechaInicio;
    int registros = 0;

    while (p != nullptr && p -> data <= fechaFin -> data){
        DLLNode<T> *q = p->next;
        newList.addLast(p -> data);
        registros++;
        p = q;
    }

    std::cout << "\nSe encontraron " << registros << " registros en la bitacora.\n" << std::endl;
}

template <class T>
void DLinkedList<T>::restartList(){
        
    DLLNode<T> *p, *q;
    p = head;

    while (p != nullptr){
        q = p->next;
        delete p;
        p = q;
    }

    head = nullptr;
    tail = nullptr;
    numElements = 0;
}

#endif // _DOUBLELINKEDLIST_H_
