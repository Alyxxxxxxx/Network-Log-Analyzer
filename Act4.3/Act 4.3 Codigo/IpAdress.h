#ifndef _IPADDRESS_H_
#define _IPADDRESS_H_

#include <cmath>
#include <iostream>
#include <vector>

class ipAddress{
private:
    std::string ipString;
    int ipIndex;
    int value;
    unsigned int ipValue;
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

    * Parámetros de entrada:
    *       No posee parámetros, no recibe argumentos.
    *
    * Valor de retorno:
    *       Retorna un valor entero que representa el grado de salida de la direcció
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
     *       Retorna un valor entero que representa el grado de salida de la direcció
     *
     * Complejidad Temporal:
     *      O(1)
     */

    std::string toString();

    bool operator==(const ipAddress &) const;
    bool operator!=(const ipAddress &) const;
    bool operator>(const ipAddress &) const;
    bool operator>=(const ipAddress &) const;
    bool operator<(const ipAddress &) const;
    bool operator<=(const ipAddress &) const;
};

ipAddress::ipAddress(){
    ipString = "0.0.0.0";
    ipIndex = 0;
    degreeOut = 0;
    ipValue = 0;
}

ipAddress::ipAddress(std::string _ip, int idx){
    ipString = _ip;
    ipIndex = idx;
    degreeOut = 0;

    int posInit = 0;
    int posFound = 0;
    std::string splitted;
    std::vector<std::string> results;
    
    while (posFound >= 0){
        posFound = ipString.find(".", posInit);
        splitted = ipString.substr(posInit, posFound - posInit);
        posInit = posFound + 1;
        results.push_back(splitted);
    }

    int partA = std::stoi(results[0]);
    int partB = std::stoi(results[1]);
    int partC = std::stoi(results[2]);
    int partD = std::stoi(results[3]);
    ipValue = partA * (pow(256, 3)) + partB * (pow(256, 2)) + partC * (pow(256, 1)) + partD;
}

std::string ipAddress::getIp(){
    return ipString;
}

unsigned int ipAddress::getIpValue(){
    return ipValue;
}

int ipAddress::getIpIndex(){
    return ipIndex;
}

bool ipAddress::operator==(const ipAddress &other) const{
    return this->ipValue == other.ipValue;
}

bool ipAddress::operator!=(const ipAddress &other) const{
    return this->ipValue != other.ipValue;
}

bool ipAddress::operator>(const ipAddress &other) const{
    return this->ipValue > other.ipValue;
}

bool ipAddress::operator>=(const ipAddress &other) const{
    return this->ipValue >= other.ipValue;
}

bool ipAddress::operator<(const ipAddress &other) const{
    return this->ipValue < other.ipValue;
}

bool ipAddress::operator<=(const ipAddress &other) const{
    return this->ipValue <= other.ipValue;
}

void ipAddress::setDegreeOut(int g){
    degreeOut = g;
}

void ipAddress::addToDegreeOut(){
    degreeOut++;
}

int ipAddress::getDegreeOut(){
    return degreeOut;
}

std::string toString(){
    int value = 0;
    return std::to_string(value);
};

#endif //_IPADDRESS_H_
