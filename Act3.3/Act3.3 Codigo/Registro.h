#ifndef _REGISTRO_H_
#define _REGISTRO_H_

#include <string>
#include <vector>
#include <iostream>
#include <cmath>

class Registro{
    private:
        unsigned int ipDecimal;
        std::string mes, dia, horas, minutos, segundos, ip, puerto, falla;
    
    public:
        /*
         * Descripción:
         *  Constructor por defecto de la clase Registro, que inicializa todos los miembros 
         *  de la clase a valores por defecto.
         * 
         * Parámetros de entrada:
         *  No posee parámetros de entrada.
         * 
         * Valor de retorno:
         *  No retorna ningún valor.
         * 
         * Complejidad temporal:
         *  O(1)
         */

        Registro();

        /*
         * Descripción:
         *  Constructor crea un objeto Registro con los valores proporcionados para sus
         *  miembros. Asimismo, el constructor procesa la dirección IP y convertirla a su 
         *  equivalente decimal utilizando la función find y operaciones de conversión de 
         *  cadenas.
         *
         * Parámetros de entrada:
         *  @_mes: Valor para el miembro mes.
         *
         *  @_dia: Valor para el miembro dia.
         *
         *  @_horas: Valor para el miembro horas.
         *
         *  @_minutos: Valor para el miembro minutos.
         *
         *  @_segundos: Valor para el miembro segundos.
         *
         *  @_ip: Valor para el miembro ip.
         *
         *  @_puerto: Valor para el miembro puerto.
         *
         *  @_falla: Valor para el miembro falla.
         *
         * Valor de retorno:
         *  No retorna ningún valor.
         *
         * Complejidad temporal:
         *  O(n) donde 'n' es la longitud de la cadena ip
         */

        Registro(std::string _mes, std::string _dia, std::string _horas, std::string _minutos, std::string _segundos, std::string _ip, std::string _puerto, std::string _falla);

        /*
         * Descripción: getAll()
         *  Método que devuelve una cadena que contiene todos los miembros del objeto
         *  Registro concatenados.
         *
         * Parámetros de entrada:
         *  No posee parámetros de entrada.
         *
         * Valor de retorno:
         *  Retorna una cadena que contiene todos los miembros del objeto Registro 
         *  concatenados en un formato específico.
         * 
         * Complejidad temporal:
         *  O(1)
         */

        std::string getAll() const;

        /*
         * Descripción: geIp()
         *  Método que devuelve la dirección IP del objeto Registro.
         *
         * Parámetros de entrada:
         *  No posee parámetros de entrada.
         *
         * Valor de retorno:
         *  Retorna una cadena que representa la dirección IP almacenada en el miembro 
         *  ip del objeto Registro.
         * 
         * Complejidad temporal:
         *  O(1)
         */

        std::string getIp() const;

        /*
         * Descripción:
         *  Sobrecargas de operadores ==, !=, >, <, >= y <=  los cuales comparan los
         *  objetos Registro en función del valor numérico de su dirección IP en formato
         *  decimal (ipDecimal).
         *
         * Parámetros de entrada:
         *  @other: Referencia constante a otro objeto Registro. Es el objeto con el que 
         *  se comparará el objeto actual utilizando el operador específico
         *
         * Valor de retorno:
         *  Variable de tipo bool que representa el resultado de la comparación entre dos
         *  objetos de la clase Registro.
         *
         * Complejidad temporal:
         *  O(1) cada uno.
         */

        bool operator==(const Registro &other) const;
        bool operator!=(const Registro &other) const;
        bool operator>(const Registro &other) const;
        bool operator<(const Registro &other) const;
        bool operator>=(const Registro &other) const;
        bool operator<=(const Registro &other) const;
};

Registro::Registro(){
    mes = "";
    dia = "";
    horas = "";
    minutos = "";
    segundos = "";
    ip = "";
    puerto = "";
    falla = "";
    ipDecimal = 0;
}

Registro::Registro(std::string _mes, std::string _dia, std::string _horas, std::string _minutos, std::string _segundos, std::string _ip, std::string _puerto, std::string _falla){
    mes = _mes;
    dia = _dia;
    horas = _horas;
    minutos = _minutos;
    segundos = _segundos;
    ip = _ip;
    puerto = _puerto;
    falla = _falla;
    
    int posInit = 0;
    int posFound = 0;
    std::string splitted;
    std::vector<std::string> results;

    while (posFound >= 0){
        posFound = ip.find(".", posInit);
        splitted = ip.substr(posInit, posFound - posInit);
        posInit = posFound + 1;
        results.push_back(splitted);
    }

    int oct3 = std::stoi(results[0]);
    int oct2 = std::stoi(results[1]);
    int oct1 = std::stoi(results[2]);
    int oct0 = std::stoi(results[3]);
    ipDecimal = (oct3 * std::pow(256, 3)) + (oct2 * std::pow(256, 2)) + (oct1 * 256) + oct0;
}

std::string Registro::getAll() const{
    return mes + " " + dia + " " + horas + ":" + minutos + ":" + segundos + " " + ip + ":" + puerto + " " + falla;
}

std::string Registro::getIp() const{
    return ip;
}

bool Registro::operator==(const Registro &other) const{
    return this->ipDecimal == other.ipDecimal;
}

bool Registro::operator!=(const Registro &other) const{
    return this->ipDecimal != other.ipDecimal;
}

bool Registro::operator>(const Registro &other) const{
    return this->ipDecimal > other.ipDecimal;
}

bool Registro::operator<(const Registro &other) const{
    return this->ipDecimal < other.ipDecimal;
}

bool Registro::operator>=(const Registro &other) const{
    return this->ipDecimal >= other.ipDecimal;
}

bool Registro::operator<=(const Registro &other) const{
    return this->ipDecimal <= other.ipDecimal;
}

#endif // _REGISTRO_H_
