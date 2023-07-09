#ifndef _REGISTRO_H_
#define _REGISTRO_H_

#include <string>
#include <vector>
#include <ctime>
#include <fstream>
#include <iostream>
#include <stdexcept>

class Registro{
    private:
        std::string mes, dia, horas, minutos, segundos, direccionIp, puerto, error;
        std::vector<std::string> meses{"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        struct tm estructuraFecha; 
        time_t tiempoTranscurrido; 
    
    public:
        Registro();

        /*
         * Constructor con parámetros de la clase. Realiza la inicialización de un objeto
         * de la clase Registro, asignando valores a sus variables miembro, convirtiendo
         * ciertos camposs a formatos numéricos y calculando el tiempo transcurrido
         * correspndiente a la fecha y hora proporcionados.
         *
         * @pMes, variable de tipo String, representa el mes en una fecha.
         * @pDia, variable de tipo String, representa el día en una fecha.
         * @pHoras, variable de tipo String, representan las horas en una fecha.
         * @pMinutos, variable de tipo String, representan los minutos en una fecha.
         * @pSegundos, variable de tipo String, representan los segundos en una fecha.
         * @pDireccionIp, variable de tipo String, representa la dirección IP.
         * @pPuerto, variable de tipo String, representa el puerto.
         * pError, variable de tipo String, representa el error de acceso a un sitio.
         *
         * Complejidad temporal: O(1)
         */

        Registro(std::string pMes, std::string pDia, std::string pHoras, std::string pMinutos, std::string pSegundos, std::string pDireccionIp, std::string pPuerto, std::string pError);

        /*
         * Recorre un vector de objetos de la clase Registros e imprime
         * los campos de entrada de cada registro en la consola, proporcionando
         * una representación legible.
         *
         * @vectorRegistros, vector que almacena objetos de la clase Registros.
         *
         * El método no regresa nada.
         *
         * Complejidad temporal: O(n)
         */

        void imprimirDatos(const std::vector<Registro> &vectorRegistros);

        /*
         * Regresa una variable de tipo time_t el cual almacena valores de tiempo
         * transcurrido medidos en segundo desde una fecha y hora específica.
         *
         * El método no posee ningún parámetro.
         *
         * @tiempoTranscurrido, variable de tipo time_t la cual forma parte de los
         * atributos de la clase Registro.
         *
         * Complejidad temporal: O(1)
         */

        time_t obtenerTiempo();

        /* Ordena ascendentemente un vector de objetos de la clase Registro mediante
         * el algoritmo de ordenamiento de burbuja.
         *
         * @vectorRegistros [parámetro por referencia] vector de objetos de la clase
         * Registro el cual se desea ordenar de manera ascendente.
         *
         * @comparacion, [parámetro por referencia] variable entera positiva la
         * cual almacena el número de veces que el algoritmo realice una comparación
         * entre elementos del vector.
         *
         * @intercambio, [parámetro por referencia] variable entera positiva la cual
         * almacena el número de veces que el algoritmo realice un intercambio entre
         * elementos del vector.
         *
         * No es necesario que el método devuelva el vector ordenado puesto que este
         * se pasó por referencia.
         *
         * Complejidad temporal: Mejor --> O(n). Promedio --> O(n^2). Peor -->O(n^2)
         */

        void ordenaBurbuja(std::vector<Registro> &vectorRegistros, unsigned int &comparacion, unsigned int &intercambio);

        /*
         * Método que ordena de forma ascendente un vector de objetos de la clase Registro
         * a través del algoritmo de de ordenamiento Merge recursivo.
         *
         * @inicioVector, variable de tipo entero la cual representa el índice más bajo del
         * vector que define el rango de elementos a ordenar en cada llamada recursiva.
         *
         * @finalVector, variable de tipo entero la cual representa el índice más alto del
         * vector que define el rango de elementos a ordenar en cada llamada recursiva.
         *
         * @vectorRegistros [parámetro por referencia] vector de objetos de la clase Registro
         * el cual se desea ordenar de manera ascendente.
         *
         * @comparacion, [parámetro por referencia] variable entera positiva la
         * cual almacena el número de veces que el algoritmo realice una comparación
         * entre elementos del vector.
         *
         * @intercambio, [parámetro por referencia] variable entera positiva la cual
         * almacena el número de veces que el algoritmo realice un intercambio entre
         * elementos del vector.
         *
         * No es necesario que el método devuelva el vector ordenado puesto que este
         * se pasó por referencia.
         *
         * Complejidad temporal: Mejor --> O(n log n). Promedio --> O(n log n). Peor -->O(n log n)
         */

        void ordenaMerge(std::vector<Registro> &vectorRegistros, int inicioVector, int finalVector, unsigned int &comparacion, unsigned int &intercambio);

        /*
         * Método auxiliar a ordenaMerge. Su función es combinar dos subvectores
         * ordenados en uno solo, asegurando que los elementos estén en orden ascendente.
         *
         * @inicioVector, variable de tipo entero la cual representa el índice más bajo
         * de un subvector a combinar.
         *
         * @puntoMedio, variable de tipo entero que representa el índice medio que divide
         * el subvector a combinar en dos partes.
         *
         * @finalVector, variable de tipo entero la cual representa el índice más alto del
         * subvector a combinar.
         *
         * @vectorRegistros [parámetro por referencia] vector de objetos de la clase Registro
         * el cual se desea ordenar de manera ascendente.
         *
         * @comparacion, [parámetro por referencia] variable entera positiva la
         * cual almacena el número de veces que el algoritmo realice una comparación
         * entre elementos del vector.
         *
         * @intercambio, [parámetro por referencia] variable entera positiva la cual
         * almacena el número de veces que el algoritmo realice un intercambio entre
         * elementos del vector.
         *
         * No devuelve ningún valor de salida directamente. En cambio, su objetivo es
         * combinar dos subvectores ordenados en uno solo, modificando el arreglo original.
         *
         * Complejidad temporal: O(n)
         */

        void merge(std::vector<Registro> &vectorRegistros, int inicioVector, int puntoMedio, int finalVector, unsigned int &comparacion, unsigned int &intercambio);

        /*
         * Busca un determinado elemento de un vector ordenado de objetos de la clase
         * Registro mediante un algoritmo de busqueda binaria.
         *
         * @vectorRegistrosOrd, [parámetro por referencia] vector de objetos de la clase
         * Registro el cual ha sido previamente ordenado de manera ascendente.
         *
         * @fechaBuscada, objeto de la clase Registro en la cual se almacena la fecha
         * que se desea buscar dentro del vector de objetos ordenado.
         *
         * @comparacion, [parámetro por referencia] variable entera positiva en la cual
         * se almacena el número de comparaciones que el algoritmo realiza para llegar a
         * la posición del elemento buscado.
         *
         * Si no se encuentra el elemento buscado dentro del vector ordenado se retorna un -1.
         * Si se logra encontrar el elemento buscado, el método retorna la posición en la cual
         * este fue encontrado.
         *
         * Complejidad temporal: Mejor --> O(1). Promedio --> O(log₂ n). Peor --> O(log n)
         */

        int busquedaBinaria(std::vector<Registro> &vectorRegistrosOrd, Registro fechaBuscada, unsigned int &comparacion);

        /*
         * Recorre el vector de registros ordenados y encuentra los registros que se
         * encuentran dentro de un rango de fechas específicos. Posteriormente, almacena
         * en un vector de objetos de la clase Registro dichos registros, y contabiliza
         * cuántos se encontraron.
         *
         * @vectorRegistrosOrd, [parámetro por referencia] vector de objetos de la clase
         * Registro el cual ha sido previamente ordenado de manera ascendente.
         *
         * @fechaInicio, objeto de la case Registro el cual representa el indíce menor del rango
         * de fechas buscado.
         *
         * @fechaFin,objeto de la case Registro el cual representa el indíce mayor del rango
         * de fechas buscado.
         *
         * @registroPersonalizado, vector de objetos de la clase Registro en el cual se
         * almacenan los registros que cumplen con el rango de fechas indicado por el
         * usuario.
         *
         * Complejidad temporal: O(n)
         */

        std::vector<Registro> buscarFechas(std::vector<Registro> &vectorRegistrosOrd, Registro fechaInicio, Registro fechaFin);

        /*
         * Guarda registros almacenados en un vector de objetos de la clase Registro
         * en un archivo de texto. Asimismo, proporciona retroalimentación al usuario
         * sobre el resultado de la operación.
         *
         * @vectorOrdenado, vector de objetos de la clase Registros.
         *
         * @nombreArch, nombre del archivo en el cual se desean guardar los datos
         * extraidos del vector.
         *
         * El método no regresa nada.
         *
         * Complejidad temporal: O(n)
         */

        void guardarBitacoraOrd(std::vector<Registro> vectorOrdenado, std::string nombreArch);

        /*
         * Sobrecarga de diversos operadores que permite comparar dos objetos 
         * de la clase Registro basándose en el atributo tiempoTranscurrido.
         * 
         * @other, su único parámetro es una referencia constante a otro objeto de la
         * clase Registro, y se utiliza para comparar el atributo tiempoTranscurrrido
         * del objeto actual con el del objeto pasado como argumento other.
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

#endif //_REGISTRO_H_