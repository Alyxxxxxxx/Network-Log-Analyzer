#include "Registro.h"

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
void Registro::imprimirDatos(const std::vector<Registro> &vectorRegistros){
    for (const Registro &registro : vectorRegistros){
        std::cout << registro.mes << " " << registro.dia << " " << registro.horas << ":" << registro.minutos << ":" << registro.segundos << " " << registro.direccionIp << ":" << registro.puerto << " " << registro.error << std::endl;
    }
}

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
time_t Registro::obtenerTiempo(){
    return tiempoTranscurrido;
}

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

void Registro::ordenaBurbuja(std::vector<Registro> &vectorRegistros, unsigned int &comparacion, unsigned int &intercambio){
    comparacion = 0;
    intercambio = 0;

    int n = (int)vectorRegistros.size();

    for (int i = 0; i < n - 1; i++){

        for (int j = 0; j < n - i - 1; j++){
            comparacion++;

            if (vectorRegistros[j] > vectorRegistros[j + 1]){
                std::swap(vectorRegistros[j], vectorRegistros[j + 1]);
                intercambio++;
            }
        }
    }
}

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

void Registro::ordenaMerge(std::vector<Registro> &vectorRegistros, int inicioVector, int finalVector, unsigned int &comparacion, unsigned int &intercambio){

    if (inicioVector < finalVector){
        int puntoMedio = inicioVector + (finalVector - inicioVector) / 2;

        ordenaMerge(vectorRegistros, inicioVector, puntoMedio, comparacion, intercambio);
        ordenaMerge(vectorRegistros, puntoMedio + 1, finalVector, comparacion, intercambio);
        merge(vectorRegistros, inicioVector, puntoMedio, finalVector, comparacion, intercambio);
    }
}

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
 * Su complejidad forma parte de ordenaMerge.
 */

void Registro::merge(std::vector<Registro> &vectorRegistros, int inicioVector, int puntoMedio, int finalVector, unsigned int &comparacion, unsigned int &intercambio){
    int i, j, k;
    int dimensionSubarreglo1 = puntoMedio - inicioVector + 1;
    int dimensionSubarreglo2 = finalVector - puntoMedio;
    std::vector<Registro> vectorIzquierda(dimensionSubarreglo1);
    std::vector<Registro> vectorDerecha(dimensionSubarreglo2);

    for (i = 0; i < dimensionSubarreglo1; i++){
        vectorIzquierda[i] = vectorRegistros[inicioVector + i];
    }

    for (j = 0; j < dimensionSubarreglo2; j++){
        vectorDerecha[j] = vectorRegistros[puntoMedio + 1 + j];
    }

    i = 0;
    j = 0;
    k = inicioVector;

    while (i < dimensionSubarreglo1 && j < dimensionSubarreglo2){
        comparacion++;

        if (vectorIzquierda[i] <= vectorDerecha[j]){
            vectorRegistros[k] = vectorIzquierda[i];
            i++;
        }

        else{
            vectorRegistros[k] = vectorDerecha[j];
            j++;
        }

        k++;
    }

    while (i < dimensionSubarreglo1){
        vectorRegistros[k] = vectorIzquierda[i];
        i++;
        k++;
    }

    while (j < dimensionSubarreglo2){
        vectorRegistros[k] = vectorDerecha[j];
        j++;
        k++;
    }
}

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

int Registro::busquedaBinaria(std::vector<Registro> &vectorRegistrosOrd, Registro fechaBuscada, unsigned int &comparacion){
    int limInferior = 0;
    int limSuperior = (int)vectorRegistrosOrd.size() - 1;
    int limIntermedio = 0;
    comparacion = 0;

    while (limInferior <= limSuperior){
        limIntermedio = (limInferior + limSuperior) / 2;
        comparacion++;

        if (fechaBuscada == vectorRegistrosOrd[limIntermedio]){
            return limIntermedio;
        }

        else if (fechaBuscada < vectorRegistrosOrd[limIntermedio]){
            limSuperior = limIntermedio - 1;
        }

        else{
            limInferior = limIntermedio + 1;
        }
    }
    return -1;
}
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
std::vector<Registro> Registro::buscarFechas(std::vector<Registro> &vectorRegistrosOrd, Registro fechaInicio, Registro fechaFin){
    int registros = 0;
    std::vector<Registro> registroPersonalizado;
    for (int i = 0; i < (int)vectorRegistrosOrd.size(); i++){
        if (vectorRegistrosOrd[i] >= fechaInicio && vectorRegistrosOrd[i] <= fechaFin){
            registroPersonalizado.push_back(vectorRegistrosOrd[i]);
            registros++;
        }
    }
    std::cout << "* Los " << registros << " registros correspondientes al rango de fechas proporcionado son: *\n" << std::endl;
    return registroPersonalizado;
}
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
void Registro::guardarBitacoraOrd(std::vector<Registro> vectorOrdenado, std::string nombreArch){
    std::ofstream archivo(nombreArch);

    if (!archivo.is_open()){
        throw std::invalid_argument("No fue posible acceder al archivo.");
    }
    else{
        for (const Registro &registro : vectorOrdenado){
            archivo << registro.mes << " " << registro.dia << " " << registro.horas << ":" << registro.minutos << ":" << registro.segundos << " " << registro.direccionIp << ":" << registro.puerto << " " << registro.error << std::endl;
        }
        archivo.close();
        std::cout << "La bitácora ordenada ha sido guardada con éxito en el archivo bitacora_ordenada.txt" << std::endl;
    }
}
/*
 * Sobrecarga de diversos operadores que permite comparar dos objetos 
 de la clase Registro basándose en el atributo tiempoTranscurrido.
 * 
 * @other, sú único parámetro es una referencia constante a otro objeto de la
 * clase Registro, y se utiliza para comparar el atributo tiempoTranscurrrido
 * del objeto actual con el del objeto pasado como argumento other.
 * 
 * Complejidad temporal: O(1)
 */

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