#ifndef _REGISTRO_H_
#define _REGISTRO_H_

#include <iostream>
#include <stdexcept>
#include <filesystem>
#include <ctime>
#include <vector>
#include <fstream>

class Registro{

    private:
        std::string mes, dia, horas, minutos, segundos, direccionIp, puerto, error;
        std::vector<std::string> meses{"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        struct tm estructuraFecha;
        time_t tiempoTranscurrido;

    public:

      /*
       * Constructor predeterminado o por defecto de la clase Registro.
       * No realiza ninguna acción en particular.
       * 
       * Parámetros: No recibe ningún parámetro.
       * 
       * Valor de retorno: Al ser constructor no retorna ningún valor.
       * 
       * Complejidad temporal: O(1)
       */

        Registro();

       /*
        * Constructor con parámetros de la clase Registro. Realiza la inicialización de 
        * un objeto de la clase Registro, asignando valores a sus variables miembro, 
        * convirtiendo ciertos camposs a formatos numéricos y calculando el tiempo 
        * transcurrido correspndiente a la fecha y hora proporcionados.
        *
        * Parámetros:
        * 
        * @pMes, variable de tipo String, representa el mes en una fecha.
        * 
        * @pDia, variable de tipo String, representa el día en una fecha.
        * 
        * @pHoras, variable de tipo String, representan las horas en una fecha.
        * 
        * @pMinutos, variable de tipo String, representan los minutos en una fecha.
        * 
        * @pSegundos, variable de tipo String, representan los segundos en una fecha.
        * 
        * @pDireccionIp, variable de tipo String, representa la dirección IP.
        * 
        * @pPuerto, variable de tipo String, representa el puerto.
        * 
        * pError, variable de tipo String, representa el error de acceso a un sitio.
        * 
        * Valor de retorno: Al ser constructor no retorna ningún valor.
        *
        * Complejidad temporal: O(1)
        */
       
        Registro(std::string pMes, std::string pDia, std::string pHoras, std::string pMinutos, std::string pSegundos, std::string pDireccionIp, std::string pPuerto, std::string pError);

        /*
         * obtenerTiempo() Regresa una variable de tipo time_t el cual almacena valores 
         * de tiempo transcurrido medidos en segundo desde una fecha y hora específica.
         *
         * Parámetros: el método no posee ningún parámetro.
         *
         * Valor de retorno: variable de tipo time_t la cual forma parte de los
         * atributos de la clase Registro.
         *
         * Complejidad temporal: O(1)
         */

        time_t obtenerTiempo();

        /*
         * imprimirDatos(): devuelve una cadena de caracteres que representa
         * los datos del registro en un formato determinado.
         * 
         * Parámetros: no recibe ningún parámetros.
         * 
         * Valor de retorno: valor de tipo string que es la cadena generada
         * que representa los datos del registro en un formato específico.
         *
         * Complejidad temporal: O(1)
         */

        std::string imprimirDatos();

        /*
         * Sobrecarga de diversos operadores que permite comparar dos objetos 
         * de la clase Registro basándose en el atributo tiempoTranscurrido.
         * 
         * Parámetros: @other, su único parámetro es una referencia constante a 
         * otro objeto de la clase Registro, y se utiliza para comparar el atributo 
         * tiempoTranscurrrido del objeto actual con el del objeto pasado como argumento 
         * other.
         * 
         * Valor de retorno: variable de tipo bool que representa el resultado de la
         * comparación entre dos objetos de la clase Registro.
         * 
         * Complejidad temporal de cada uno: O(1)
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
    direccionIp = "";
    puerto = "";
    error = "";
    tiempoTranscurrido = 0;
}

Registro::Registro(std::string pMes, std::string pDia, std::string pHoras, std::string pMinutos, std::string pSegundos, std::string pDireccionIp, std::string pPuerto, std::string pError){
    mes = pMes;
    dia = pDia;
    horas = pHoras;
    minutos = pMinutos;
    segundos = pSegundos;
    direccionIp = pDireccionIp;
    puerto = pPuerto;
    error = pError;

    estructuraFecha.tm_hour = std::stoi(horas);
    estructuraFecha.tm_min = std::stoi(minutos);
    estructuraFecha.tm_sec = std::stoi(segundos);
    estructuraFecha.tm_mday = std::stoi(dia);
    estructuraFecha.tm_isdst = 0;

    for (int i = 0; i < (int)meses.size(); i++){

        if (meses[i] == mes)
            estructuraFecha.tm_mon = i;
    }

    estructuraFecha.tm_year = 2023 - 1900;
    tiempoTranscurrido = mktime(&estructuraFecha);
}

time_t Registro::obtenerTiempo(){
    return tiempoTranscurrido;
}

std::string Registro::imprimirDatos(){
    return mes + " " + dia + " " + horas + ":" + minutos + ":" + segundos + " " + direccionIp + ":" + puerto + " " + error;
}

bool Registro::operator==(const Registro &other) const{
    return this->tiempoTranscurrido == other.tiempoTranscurrido;
}

bool Registro::operator!=(const Registro &other) const{
    return this->tiempoTranscurrido != other.tiempoTranscurrido;
}

bool Registro::operator>(const Registro &other) const{
    return this->tiempoTranscurrido > other.tiempoTranscurrido;
}

bool Registro::operator<(const Registro &other) const{
    return this->tiempoTranscurrido < other.tiempoTranscurrido;
}

bool Registro::operator>=(const Registro &other) const{
    return this->tiempoTranscurrido >= other.tiempoTranscurrido;
}

bool Registro::operator<=(const Registro &other) const{
    return this->tiempoTranscurrido <= other.tiempoTranscurrido;
}

#endif //_REGISTRO_H_
