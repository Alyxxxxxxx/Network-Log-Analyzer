#ifndef _IPDEGREEOUT_H_
#define _IPDEGREEOUT_H_

#include <iostream>
#include <vector>

class IpDegreeOut{
    private:
        int degreeOut;
        int ipIndex;
        std::string ipAccess;

    public:
        /*
         * Descripción:
         *      Constructor utilizado para crear un objeto ipAddress sin proporcionar ningún
         *      argumento. Al utilizar este constructor, el objeto ipAddress se inicializa con los
         *      valores predeterminados para sus atributos: ipString se establece como "0.0.0.0",
         *      ipIndex se establece como 0, degreeOut se establece como 0 y ipValue se establece
         *      como 0. Esto permite crear un objeto ipAddress con valores iniciales predeterminados
         *      cuando no se proporcionan valores específicos.
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

        IpDegreeOut();

        /*
         * Descripción:
         *      Constructor utilizado para crear un objeto IpDegreeOut con valores específicos para
         *      la dirección IP (ipAccess), el grado de salida (degreeOut) y el índice de IP (ipIndex).
         *
         * Parámetros de entrada:
         *      @ipAccess: cadena de caracteres que representa la dirección IP.
         *
         *      @_degreeOut:entero que representa el grado de salida.
         *
         *      @idx: entero que representa el índice de la dirección IP en una estructura.
         *
         * Valor de retorno:
         *      No retorna ningún valor.
         *
         * Complejidad Temporal:
         *      O(1)
         */

        IpDegreeOut(std::string _ipAccess, int _degreeOut, int idx);

        /*
         * Descripción: getIpAccess()
         *    Método utilizado para obtener la dirección IP almacenada en el objeto IpDegreeOut.
         *    El método devuelve la dirección IP como una cadena de caracteres (std::string), lo
         *    que permite acceder y utilizar la dirección IP almacenada en otros lugares del programa.
         *
         *
         * Parámetros de entrada:
         *      No posee parámetros, no recibe argumentos.
         *
         * Valor de retorno:
         *      El método devuelve la dirección IP almacenada en el objeto IpDegreeOut como una cadena
         *      de caracteres (std::string).
         *
         * Complejidad Temporal:
         *      O(1)
         */

        std::string getIpAccess();

        /*
         * Descripción: getIpIndex()
         *    Método utilizado para obtener el índice de la dirección IP almacenada en el objeto
         *    IpDegreeOut. El índice representa la posición de la dirección IP en la estructura de datos
         *    en la que se almacena la dirección IP en el grafo.
         *
         *
         * Parámetros de entrada:
         *      No posee parámetros, no recibe argumentos.
         *
         * Valor de retorno:
         *      El método devuelve el índice de la dirección IP almacenada en el objeto IpDegreeOut como 
         *      un entero.
         *
         * Complejidad Temporal:
         *      O(1)
         */

        int getIpIndex();

        /*
         * Descripción: getDegreeOut()
         *    Metodo utilizaddo para obtener el grado de salida almacenado en el objeto IpDegreeOut.
         *    El grado de salida representa la cantidad de conexiones de salida que tiene la dirección
         *    IP en el grafo.
         *
         *
         * Parámetros de entrada:
         *      No posee parámetros, no recibe argumentos.
         *
         * Valor de retorno:
         *      El método devuelve el grado de salida almacenado en el objeto IpDegreeOut como un 
         *      entero.
         *
         * Complejidad Temporal:
         *      O(1)
         */

        int getDegreeOut();

        /*
         * Descripción: sobrecarga de operadores.
         *     Estos métodos sobrecargan los operadores de comparación en la clase IpDegreeOut para
         *     permitir la comparación de objetos IpDegreeOut en función de su atributo degreeOut.
         *     Estos operadores permiten comparar dos objetos  IpDegreeOut  y determinar si son
         *     iguales, diferentes, mayores, menores, mayores o iguales, o menores o iguales, según el
         *     valor de degreeOut que contienen.
         *
         * Parámetros de entrada:
         *      @&other: Es una referencia constante al objeto  IpDegreeOut con el que se va a comparar el
         *      objeto actual.
         *
         * Valor de retorno:
         *      Cada método de comparación devuelve un valor booleano (true o false) que representa el
         *      resultado de la comparación.
         *
         * Complejidad Temporal:
         *      O(1) cada uno
         */

        bool operator==(const IpDegreeOut &) const;
        bool operator!=(const IpDegreeOut &) const;
        bool operator>(const IpDegreeOut &) const;
        bool operator>=(const IpDegreeOut &) const;
        bool operator<(const IpDegreeOut &) const;
        bool operator<=(const IpDegreeOut &) const;

        /*
         * Descripción: sobrecarga de la impresión en un flujo de salida
         *    Esta función friend sobrecarga el operador << para permitir la impresión de objetos
         *    IpDegreeOut en un flujo de salida, como la consola o un archivo. La función se utiliza
         *    para imprimir los objetos IpDegreeOut de una manera personalizada, lo que proporciona una
         *    visualización más legible.
         *
         *
         * Parámetros de entrada:
         *      @&os: Es una referencia al flujo de salida (ostream) donde se imprimirá el objeto
         *      Distance.
         *
         *      @&object: Es una referencia constante al objeto IpDegreeOut que se imprimirá en el
         *      flujo de salida.
         *
         * Valor de retorno:
         *      La función devuelve una referencia al flujo de salida (ostream) para permitir la encadenación
         *      de impresiones en el mismo flujo.
         *
         * Complejidad Temporal:
         *      O(1)
         */

        friend std::ostream &operator<<(std::ostream &os, const IpDegreeOut &object);
};

IpDegreeOut::IpDegreeOut(){
    ipAccess = "";
    degreeOut = 0;
    ipIndex = 0;
}

IpDegreeOut::IpDegreeOut(std::string _ipAccess, int _degreeOut, int idx){
    ipAccess =_ipAccess;
    degreeOut = _degreeOut;
    ipIndex = idx;
}

std::string IpDegreeOut::getIpAccess(){
    return ipAccess;
}

int IpDegreeOut::getDegreeOut(){
    return degreeOut;
}

int IpDegreeOut::getIpIndex(){
    return ipIndex;
}

bool IpDegreeOut::operator==(const IpDegreeOut &other) const{
    return this->degreeOut == other.degreeOut;
}

bool IpDegreeOut::operator!=(const IpDegreeOut &other) const{
    return this->degreeOut != other.degreeOut;
}

bool IpDegreeOut::operator>(const IpDegreeOut &other) const{
    return this->degreeOut > other.degreeOut;
}

bool IpDegreeOut::operator>=(const IpDegreeOut &other) const{
    return this->degreeOut >= other.degreeOut;
}

bool IpDegreeOut::operator<(const IpDegreeOut &other) const{
    return this->degreeOut < other.degreeOut;
}

bool IpDegreeOut::operator<=(const IpDegreeOut &other) const{
    return this->degreeOut <= other.degreeOut;
}

std::ostream &operator<<(std::ostream &os, const IpDegreeOut &object){
    os << "IP: " << object.ipAccess << "   ------>   " << "Grado de salida: " << object.degreeOut;
    return os;
}

#endif //_IPDEGREEOUT_H_