#ifndef _AdministradorRegistros_H_
#define _AdministradorRegistros_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <limits>
#include "Registro.h"

class AdministradorRegistros{
    private:
        std::vector<Registro> listaRegistros;

    public:
        AdministradorRegistros();

        /*
         * Lee un archivo línea por línea, extrae los diferentes campos de datos
         * separados por ciertos delimitadores y los almacena en objetos de tipo
         * Registro que se agrega a un vector. Finalmente devuelve ese vector con
         * los registros obtenidos del archivo.
         *
         * @direccionArch, String que indica el nombre del archivo de donde se
         * extraerán datos.
         *
         * @listaRegistros, vector que almacena objetos de tipo Registro en
         * donde se almacenan los distintos campos de datos del archivo.
         *
         * Complejidad temporal: O(n)
         */

        std::vector<Registro> obtenerLinea(std::string direccionArch);

        /*
         * Solicita al usuario que ingrese una fecha en un formato específico, de
         * acuerdo con un intervalo, después extrae los componentes de la fecha
         * y hora de forma separada, y posteriormente crea un objeto de la clase
         * Registro con los valores anteriormente recabados.
         *
         * @intervalo, variable entera que indica el intervalo de fecha que se está
         * solicitado, ya sea la primera o la segunda.
         *
         * @fechaRegistrada, objeto de la clase Registro que recibe como atributos la
         * fecha proporcionada por el usuario dividida en el mes, el día, la hora, los
         * minutos, y los segundos.
         *
         * Complejidad temporal: O(1) - tiempo constante
         */

        Registro ingresarDatos (int intervalo);

        /*
         * Realiza un ordenamiento de un vector de objetos de la clase Registros
         * utilizando el método seleccionado por el usuario (Burbuja o Merge Sort).
         * El ordenamiento lo hace con base en las fechas.
         * Finalmente, muestra información sobre el número de comparaciones e
         * intercambios realizados durante el proceso de ordenamiento.
         *
         * @vectorFechas, vector de objetos de la clase Registros donde cada objeto
         * posee los datos de cada línea del archivo bitacora.txt
         *
         * @vectorFecha, el mismo vector tras haber sido ordenado.
         *
         * Complejidad temporal: es dominada por el algoritmo de ordenamiento que
         * el usuario seleccione. Si se elige ordenamiento Burbuja ---> O(n^2)
         * Si se elige el ordenamiento Merge Sort ---> O(n log n)
         */
        
        std::vector<Registro> ordenaVector(std::vector<Registro> &vectorFechas);
};

#endif // _AdministradorRegistros_H_

