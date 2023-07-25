#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <iostream>
#include <stdexcept>
#include "NodeLinkedList.h"

template <class T> 
class LinkedList{
  private:
    NodeLinkedList<T> *head;
    NodeLinkedList<T> *tail;
    int numElements;
  
  public:
      /*
       * Descripción:
       *      Constructor de LinkedList, se utiliza para crear una instancia
       *      de la clase. En ella se inicializan los miembros de datos head y
       *      tail, estableciendose como nullptr, indicando que la lista está
       *      vacía. El número de elementos también se establece a cero,
       *      indicando que no hay elementos al momento de su creación.
       *
       * Parámetros de entada:
       *      No posee parámetros, no recibe argumentos.
       *
       * Valor de retorno:
       *      No retorna ningún valor.
       *
       * Complejidad Temporal:
       *      O(1)
       */

      LinkedList();

      /*
       * Descripción:
       *      Destructor de la clase, encargado de liberar la memoria
       *      utilizada por todos los nodos de la lista enlazada,
       *      eliminando uno por uno los nodos a través de un puntero.
       *
       * Parámetros de entrada:
       *      No posee parámetros.
       *
       * Valor de retorno:
       *      No posee valores de retorno.
       *
       * Complejidad  Temporal:
       *      O(n)
       */

      ~LinkedList();

      /*
       * Descripción: addFirst()
       *      Agrega un nuevo nodo con un valor determinado al principio de
       *      una lista enlazada. Actualiza los punteros head, tail y numElementos
       *      según sea necesario para mantener la coherencia de la lista.
       *
       * Parámetros de entrada:
       *      @value, dato que se desea almacenar en el nuevo nodo que se está
       *      agregando al inicio de la lista enlazada. El valor puede ser de
       *      cualquier tipo T.
       *
       * Valor de retorno:
       *      No posee valores de retorno.
       *
       * Complejidad temporal:
       *      O(1)
       */

      void addFirst(T value);

      /*
       * Descripción: addLast()
       *      Agrega un nuevo nodo con un valor determinado al final
       *      de una lista enlazada. Si la lista está vacía, se llama
       *      a laa función addFirst. De lo contrario se crea un nuevo
       *      nodo y se actualizan los punteros tail y numElementos.
       *
       * Parámetros de entrada:
       *      @value, dato que se desea almacenar en el nuevo nodo que se está
       *      agregando al final de la lista enlazada. El dato puede ser de
       *      cualquier tipo T.
       *
       * Valor de retorno:
       *      No posee valores de retorno.
       *
       * Complejidad Temporal:
       *      O(1)
       */

      void addLast(T value);

      /*
       * Descripción: getNumElements()
       *      Retorna el número de elementos en la lista enlazada. El
       *      valor de retorno es obtenido directamente del atributo
       *      de la clase numElementos.
       *
       * Parámetros de entrada:
       *      El método no posee parámetros, no recibe ningún argumento.
       *
       * Valor de retorno:
       *      El método retorna una variable entera la cual representa el
       *      número de nodos/elementos en una lista enlazada.
       *
       * Complejidad Temporal:
       *      O(1)
       */

      int getNumElements();

      /*
       * Descripción: printList()
       *      Imprime el contenido de la lista enlazada, mostrando
       *      los valores de los nodos en orden. Si la lista está
       *      vacía, se imprime un mensaje indicando su falta de
       *      elementos.
       *
       * Parámetros de entrada:
       *      El método no recibe ningún argumento, no tiene
       *      parámetros.
       *
       * Valor de retorno:
       *      El método no retorna ningún valor, solo imprime.
       *
       * Complejidad Temporal:
       *      O(n)
       */

      void printList();

      /*
       * Descripción: deleteData()
       *      Elimina un nodo que contiene un valor específico de la lista
       *      enlazada. Dependiendo de su ubicación se actualizan los
       *      punteros y se libera la memoria correspondiente. Al final se
       *      actualiza el contador de número de elementos.
       *
       * Parámetros de entrada:
       *      @value, representa el valor que se desea eliminar de la lista
       *      enlazada. El valor puede ser de cualquier tipo T.
       *
       * Valor de retorno:
       *      El método retorna un valor booleano que indica el resultado
       *      de la operación de eliminación. True para una eliminación
       *      del valor exitosa, y False para una eliminación fallida.
       *
       * Complejidad temporal:
       *      O(n)
       */

      bool deleteData(T value);

      /*
       * Descripción: deleteAt()
       *      Elimina un nodo que se encuentra en una posición especificada.
       *      Dependiendo de su ubicación se actualizan los punteros y se libera
       *      la memoria correspondiente. Al final se actualiza el contador de
       *      número de elementos.
       *
       * Parámetros de entrada:
       *      @position, variable de valor entero que representa la posición del
       *      nodo que se desea eliminar en la lista enlazadaa.
       *
       * Valor de retorno:
       *      El método retorna True si se eliminó el elemento exitosamente y
       *      False, en caso contrario.
       *
       * Complejidad Temporal:
       *       O(n)
       */

      bool deleteAt(int position);

      /*
       * Descripción: getData()
       *      Retorna el valor del elemento en la posición especificada
       *      de la lista enlazada. Si la posición está fuera del rango,
       *      se lanza una excepción.
       *
       * Parámetros de entrada:
       *      @position, valor entero que representa la posición del nodo
       *      del cual se desea obtener el valor de su dato en la lista
       *      enlazada. Se asume que la lista está indexada desde cero.
       *
       * Valor de retorno:
       *      El valor de retorno de tipo T es el valor del elemento en la
       *      posición especificada de la lista enlazada.
       *
       * Complejidad Temporal:
       *      O(n)
       */

      T getData(int position);

      /*
       * Descripción: getHead()
       *       Se encarga de devolver un puntero al nodo que representa el inicio (cabeza) de la lista
       *       enlazada.
       *
       * Parámetros de entrada:
       *       No posee parámetros de entrada.
       *
       * Valor de retorno:
       *       Devuelve un puntero de tipo NodeLinkedList<T>*, que apunta al nodo que representa el inicio
       *       (cabeza) de la lista enlazada.
       *
       * Complejidad temporal:
       *       O(1)
       */
      
      NodeLinkedList<T> *getHead();
};

template <class T> 
LinkedList<T>::LinkedList(){
    head = nullptr;
    tail = nullptr;
    numElements = 0;
}

template <class T> 
LinkedList<T>::~LinkedList(){
    NodeLinkedList<T> *p, *q;
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
void LinkedList<T>::addFirst(T value){
    NodeLinkedList<T> *newNode = new NodeLinkedList<T>(value);
    newNode->next = head;
    head = newNode;

    if (numElements == 0){
        tail = newNode;
    }

    numElements++;
}

template <class T>
void LinkedList<T>::addLast(T value){
    if (head == nullptr && tail == nullptr){
        addFirst(value);
    }

    else{
        NodeLinkedList<T> *newNode = new NodeLinkedList<T>(value);
        tail->next = newNode;
        tail = newNode;
        numElements++;
    }
}

template <class T>
int LinkedList<T>::getNumElements(){
    return numElements;  
}

template <class T>
void LinkedList<T>::printList(){
    if (head == nullptr && tail == nullptr){
        std::cout << "La lista esta vacia" << std::endl;
    }

    else{
        std::cout << "El contenido de la lista es: " << std::endl;
        NodeLinkedList<T> *p = head;

        while(p != nullptr){
            std::cout << p->data << " ";
            p = p->next;
        }

        std::cout << std::endl;
    }    
}
  
template <class T>
bool LinkedList<T>::deleteData(T value){

    if (head == nullptr && tail == nullptr){
        std::cout << "La lista esta vacia" << std::endl;
        return false;
    }

    else{
        NodeLinkedList<T> *p = head;
        NodeLinkedList<T> *prev = nullptr;

        while(p != nullptr && p->data != value){
            prev = p;
            p = p->next;
        }

        if (p == nullptr){
            std::cout << "El valor no existe en la lista" << std::endl;
            return false;
        }

        if (p != nullptr && p == head){
            head = p->next;
            if (head == nullptr){
                tail = nullptr;
            }
        }    

        else if (p->next == nullptr){ 
            prev->next = nullptr;
            tail = prev;
        }

        else{
            prev->next = p->next;
        }

        delete p;
        p = nullptr;
        numElements--;
        return true;
    }
}

template <class T>
bool LinkedList<T>::deleteAt(int position){
    if (position < 0 || position >= numElements){
        throw std::out_of_range("Indice fuera de rango");
    } 
  
    else if (position == 0){
        NodeLinkedList<T> *p = head;

        if (p != nullptr && p->next == nullptr){
            head = nullptr;
            tail = nullptr;
        } 
    
        else{
            head = p->next;
        }
    
        delete p;
        p = nullptr;
        numElements--;
        return true;
    }

    else{ 
        NodeLinkedList<T> *p = head;
        NodeLinkedList<T> *prev = nullptr;
        int index = 0;
 
        while (index != position){
            prev = p;
            p = p->next;
            index++;
        }

        if (p->next == nullptr){
            prev->next = nullptr;
            tail = prev;
        } 

        else{
            prev->next = p->next;
        }

        delete p;
        p = nullptr;
        numElements--;
        return true;
    }
}

template <class T>
T LinkedList<T>::getData(int position){
    if (position < 0 || position >= numElements){
        throw std::out_of_range("Indice fuera de rango");
    } 
    
    else if (position == 0){ 
        return head->data;
    }

    else{ 
        NodeLinkedList<T> *p = head;
        int index = 0;

        while (p != nullptr){

            if (index == position){
                return p->data;
            }

            p = p->next;
            index++;
        }
        
    return {};
  }    
}

template <class T> 
NodeLinkedList<T> * LinkedList<T>::getHead(){ 
    return head; 
}

#endif // _LINKEDLIST_H_

