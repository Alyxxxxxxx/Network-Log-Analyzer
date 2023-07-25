#ifndef _DISTANCE_H_
#define _DISTANCE_H_

#include <iostream>
#include <vector>

class Distance{
    private:
        std::string ipAccess;
        int distanceBoot;

    public:
        /*
         * Descripción:
         *      Este constructor se utiliza para crear un objeto Distance sin proporcionar
         *      ningún argumento. Al utilizar este constructor, el objeto Distance se inicializa
         *      con una dirección IP vacía ("") y una distancia de 0. Esto permite crear un objeto
         *      Distance con valores iniciales predeterminados cuando no se proporcionan valores
         *      específicos.
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

        Distance();

        /*
         * Descripción:
         *      Este constructor se utiliza para crear un objeto Distance con valores específicos
         *      para la dirección IP (ipAccess) y la distancia desde el nodo de inicio (distanceBoot).
         *
         * Parámetros de entrada:
         *      @_ipAccess: cadena de caracteres que representa la dirección IP
         *
         *      @_distanceBoot: entero que representa la distancia desde el nodo de inicio.
         *
         * Valor de retorno:
         *      No retorna ningún valor.
         *
         * Complejidad Temporal:
         *      O(1)
         */

        Distance(std::string _ipAccess, int distanceBoot);

        /*
         * Descripción: getIpAccess()
         *      Este método se utiliza para obtener la dirección IP almacenada en el objeto Distance.
         *      El método devuelve la dirección IP como una cadena de caracteres (std::string), lo que
         *      permite acceder y utilizar la dirección IP almacenada en otros lugares del programa.
         *
         *
         * Parámetros de entrada:
         *      No posee parámetros, no recibe argumentos.
         *
         * Valor de retorno:
         *      El método devuelve la dirección IP almacenada en el objeto Distance como una cadena de
         *      caracteres (std::string).
         *
         * Complejidad Temporal:
         *      O(1)
         */

        std::string getIpAccess();

        /*
         * Descripción: getDistance()
         *     Este método se utiliza para obtener la distancia desde el nodo de inicio hasta la dirección
         *     IP almacenada en el objeto Distance.La distancia se representa como un entero, lo que permite
         *     acceder y utilizar la distancia almacenada en otros lugares del programa.
         *
         *
         * Parámetros de entrada:
         *      No posee parámetros, no recibe argumentos.
         *
         * Valor de retorno:
         *      El método devuelve la distancia almacenada en el objeto Distance como un entero.
         *
         * Complejidad Temporal:
         *      O(1)
         */

        int getDistance();

        /*
         * Descripción: sobrecarga de operadores.
         *     Estos métodos sobrecargan los operadores de comparación en la clase Distance para permitir la
         *     comparación de objetos Distance en función de su atributo distanceBoot. Estos operadores permiten
         *     comparar dos objetos Distance y determinar si son iguales, diferentes, mayores, menores, mayores o
         *     iguales, o menores o iguales, según el valor de distanceBoot que contienen.
         *
         *
         * Parámetros de entrada:
         *      @&other: Es una referencia constante al objeto Distance con el que se va a comparar el
         *      objeto actual.
         *
         * Valor de retorno:
         *      Cada método de comparación devuelve un valor booleano (true o false) que representa el 
         *      resultado de la comparación.
         *
         * Complejidad Temporal:
         *      O(1) cada uno
         */

        bool operator==(const Distance &) const;
        bool operator!=(const Distance &) const;
        bool operator>(const Distance &) const;
        bool operator>=(const Distance &) const;
        bool operator<(const Distance &) const;
        bool operator<=(const Distance &) const;

        /*
         * Descripción: sobrecarga de la impresión en un flujo de salida
         *    Esta función friend sobrecarga el operador << para permitir la impresión de objetos Distance
         *    en un flujo de salida, como la consola o un archivo. La función se utiliza para imprimir los
         *    objetos Distance de una manera personalizada, lo que proporciona una visualización más legible.
         *
         *
         * Parámetros de entrada:
         *      @&os: Es una referencia al flujo de salida (ostream) donde se imprimirá el objeto
         *      Distance.
         *
         *      @&object: Es una referencia constante al objeto Distance que se imprimirá en el
         *      flujo de salida.
         *
         * Valor de retorno:
         *      La función devuelve una referencia al flujo de salida (ostream) para permitir la encadenación 
         *      de impresiones en el mismo flujo.
         *
         * Complejidad Temporal:
         *      O(1)
         */

        friend std::ostream &operator<<(std::ostream &os, const Distance &object);
};
Distance::Distance(){
    ipAccess = "";
    distanceBoot = 0;
}

Distance::Distance(std::string _ipAccess,int _distanceBoot){
    ipAccess = _ipAccess;
    distanceBoot = _distanceBoot;
}

std::string Distance::getIpAccess(){
    return ipAccess;
}

int Distance::getDistance(){
    return distanceBoot;
}

bool Distance::operator==(const Distance &other) const{
    return this->distanceBoot == other.distanceBoot;
}

bool Distance::operator!=(const Distance &other) const{
    return this->distanceBoot != other.distanceBoot;
}

bool Distance::operator>(const Distance &other) const{
    return this->distanceBoot > other.distanceBoot;
}

bool Distance::operator>=(const Distance &other) const{
    return this->distanceBoot >= other.distanceBoot;
}

bool Distance::operator<(const Distance &other) const{
    return this->distanceBoot < other.distanceBoot;
}

bool Distance::operator<=(const Distance &other) const{
    return this->distanceBoot <= other.distanceBoot;
}

std::ostream &operator<<(std::ostream &os, const Distance &object){
    os << "IP: " << object.ipAccess << "   ------>   " << "Distancia: " << object.distanceBoot;
    return os;
}

#endif // _DISTANCE_H_