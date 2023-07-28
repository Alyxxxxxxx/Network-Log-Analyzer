#ifndef _IPADDRESS_H_
#define _IPADDRESS_H_

#include <cmath>
#include <iostream>
#include <vector>
#include "MaxHeap.h"

class ipAddress{
private:
    std::string ipString;
    int ipIndex;
    int value;
    unsigned int ipValue;
    int degreeIn; 
    int degreeOut; 

public:
    /*
     * Descripción:
     *      Constructor por defecto de la clase ipAddress. Inicializa los miembros de la clase
     *      con valores predeterminados (ipString = "0.0.0.0", ipIndex = 0, degreeOut = 0, ipValue = 0).
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

    ipAddress();

    /*
     * Descripción:
     *      Constructor de la clase ipAddress que recibe una dirección IP en formato de cadena _ip
     *      y un índice idx. Crea un objeto ipAddress con los miembros inicializados según la dirección
     *      IP proporcionada. Además, este constructor realiza una conversión de la dirección IP de
     *      formato de cadena a formato entero sin signo (ipValue) para facilitar las comparaciones y
     *      cálculos de ordenamiento.
     *
     * Parámetros de entrada:
     *      @_ip: Una cadena que representa la dirección IP en formato "A.B.C.D", donde A, B, C, y D
     *      son números enteros en el rango de 0 a 255 que representan los octetos de la dirección IP.
     *
     *      @idx: Un entero que representa el índice asociado a la dirección IP.ura.
     *
     * Valor de retorno:
     *      No retorna ningún valor.
     *
     * Complejidad Temporal:
     *      O(n) donde n es el número de octetos en la dirección IP
     */

    ipAddress(std::string _ip, int idx);

    /*
     * Descripción: getIp()
     *      Método que devuelve la dirección IP almacenada en formato de cadena.
     *
     * Parámetros de entrada:
     *       No posee parámetros, no recibe argumentos.
     *
     * Valor de retorno:
     *      El método devuelve la dirección IP almacenada en el objeto IpAdress como una cadena
     *      de caracteres (std::string).
     *
     * Complejidad Temporal:
     *      O(1)
     */

    std::string getIp();

    /*
     * Descripción: getIpValue()
     *       Método que devuelve el valor entero sin signo correspondiente a la dirección IP.
     *       El valor entero sin signo ipValue es calculado previamente en el constructor
     *       ipAddress(std::string _ip, int idx), representando la dirección IP en formato numérico.
     *
     * Parámetros de entrada:
     *       No posee parámetros, no recibe argumentos.
     *
     * Valor de retorno:
     *      Retorna un valor de tipo unsigned int, que representa la dirección IP en formato numérico.
     *
     * Complejidad Temporal:
     *      O(1)
     */

    unsigned int getIpValue();

    /*
     * Descripción: getIpIndex()
     *      Método que devuelve el índice de la dirección IP. El índice ipIndex se establece en el
     *      constructor ipAddress(std::string _ip, int idx) y representa la posición de la dirección IP
     *      en la lista de direcciones IP almacenadas en el grafo.
     *
     * Parámetros de entrada:
     *       No posee parámetros, no recibe argumentos.
     *
     * Valor de retorno:
     *      Retorna un valor entero que representa el índice de la dirección IP.
     *
     * Complejidad Temporal:
     *      O(1)
     */

    int getIpIndex();

    /*
     * Descripción: setDegreeIn()
     *      Método que establece el valor del atributo degreeIn, que representa la cantidad de
     *      direcciones IP que han intentado acceder a la dirección IP representada por el objeto
     *      ipAddress.
     *
     * Parámetros de entrada:
     *       @g: entrada de tipo int llamado g, que representa el valor que se desea establecer
     *      para el atributo degreeIn.
     *
     * Valor de retorno:
     *      No retorna ningún valor.
     *
     * Complejidad Temporal:
     *      O(1)
     */

    void setDegreeIn(int g);

    /*
     * Descripción: addToDegreeIn()
     *      Método que incrementa en uno la cantidad de direcciones IP que han intentado acceder
     *      a la dirección IP representada por el objeto ipAddress.
     *
     * Parámetros de entrada:
     *       No posee parámetros, no recibe argumentos.
     *
     * Valor de retorno:
     *      No retorna ningún valor.
     *
     * Complejidad Temporal:
     *      O(1)
     */

    void addToDegreeIn();

    /*
     * Descripción: getDegreeIn()
     *      Método utilizado para obtener el valor del atributo degreeIn, que representa la cantidad
     *      de direcciones IP que han intentado acceder a la dirección IP representada por el objeto
     *      ipAddress.
     *
     * Parámetros de entrada:
     *       No posee parámetros, no recibe argumentos.
     *
     * Valor de retorno:
     *      Devuelve un valor entero (int) que representa la cantidad de direcciones que han intentado     
     *      acceder a la dirección IP representada por el objeto ipAddress.
     *
     * Complejidad Temporal:
     *      O(1)
     */

    int getDegreeIn();

    /*
     * Descripción: setDegreeOut()
     *      Método que establece el grado de salida g para una dirección IP. El grado de salida representa
     *      la cantidad de aristas salientes desde el nodo asociado a la dirección IP.
     *
     * Parámetros de entrada:
     *       @g: Un entero que representa el grado de salida que se desea establecer para la dirección IP.
     *
     * Valor de retorno:
     *      No retorna ningún valor.
     *
     * Complejidad Temporal:
     *      O(1)
     */

    void setDegreeOut(int g);

    /*
     * Descripción: addToDegreeOut()
     *      Método que incrementa en uno el grado de salida de una dirección IP. El grado de salida representa
     *      la cantidad de aristas salientes desde el nodo asociado a la dirección IP.
     * 
     * Parámetros de entrada:
     *        No posee parámetros, no recibe argumentos.
     *
     * Valor de retorno:
     *      No retorna ningún valor.
     *
     * Complejidad Temporal:
     *      O(1)
     */

    void addToDegreeOut();

    /*
     * Descripción: getDegreeOut()
     *       Método que devuelve el grado de salida de una dirección IP. El grado de salida representa la cantidad
     *       de aristas salientes desde el nodo asociado a la dirección IP.
     *
     * Parámetros de entrada:
     *       No posee parámetros, no recibe argumentos.
     *
     * Valor de retorno:
     *       Retorna un valor entero que representa el grado de salida de la dirección
     *
     * Complejidad Temporal:
     *      O(1)
     */

    int getDegreeOut();

    /*
     * Descripción: toString()
     *       Método que devuelve una representación en cadena del objeto ipAddress. Actualmente,
     *       el método siempre devuelve la cadena que representa el valor entero 0.
     *
     * Parámetros de entrada:
     *       No posee parámetros, no recibe argumentos.
     *
     * Valor de retorno:
     *       Devuelve un objeto de tipo std::string, que representa la representación en forma de 
     *       cadena del valor entero value.
     *
     * Complejidad Temporal:
     *      O(1)
     */

    std::string toString();

    bool showAccessedIp;

    /*
     * Descripción:
     *      Implementación de una función amiga (friend) llamada operator<< en la clase ipAddress.
     *      Esta función sobrecarga el operador de inserción (<<) de flujo de salida (std::ostream)
     *      para permitir la impresión formateada de objetos de tipo ipAddress. El bloque if y
     *      else en la función proporciona una opción de impresión condicional que permite
     *      mostrar diferentes niveles de información según el valor de showAccessedIp. Esto
     *      aumenta la flexibilidad y utilidad al imprimir objetos ipAddress en diferentes
     *      situaciones.
     *
     * Parámetros de entrada:
     *      @std::ostream &os: Una referencia a un objeto de flujo de salida (ostream).
     *      Es el flujo de salida donde se escribirá la representación del objeto ipAddress.
     *
     *      @const ipAddress &object: Una referencia constante al objeto ipAddress que se va a imprimir.
     *
     * Valor de retorno:
     *       Devuelve una referencia al flujo de salida (ostream) pasado como parámetro (os).
     *       Esto permite encadenar múltiples llamadas a operator<< para imprimir varios objetos
     *       en el mismo flujo de salida.
     *
     * Complejidad Temporal:
     *      O(1)
     */

    friend std::ostream &operator<<(std::ostream &os, const ipAddress &object);

    /*
     * Descripción: sobrecarga de operadores
     *      Implementación de varios operadores de comparación (==, !=, >, >=, < y <=) en la
     *      clase ipAddress. Estos operadores se utilizan para comparar dos objetos de tipo
     *      ipAddress en función de su valor de dirección IP decimal (ipValue).
     *
     * Parámetros de entrada:
     *       Todos los operadores de comparación toman un parámetro de entrada de tipo const
     *       ipAddress &other, que representa el otro objeto ipAddress con el que se desea realizar
     *       la comparación.
     *
     * Valor de retorno:
     *       Cada operador de comparación devuelve un valor booleano (bool):
     *
     *       - true: Si la comparación es verdadera (la condición se cumple).
     *
     *       - false: Si la comparación es falsa (la condición no se cumple).
     *
     * Complejidad Temporal:
     *      O(1)
     */

    bool operator==(const ipAddress &) const;
    bool operator!=(const ipAddress &) const;
    bool operator>(const ipAddress &) const;
    bool operator>=(const ipAddress &) const;
    bool operator<(const ipAddress &) const;
    bool operator<=(const ipAddress &) const;
};

#endif //_IPADDRESS_H_
