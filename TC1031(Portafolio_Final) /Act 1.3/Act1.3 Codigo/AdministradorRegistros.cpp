#include "AdministradorRegistros.h"

AdministradorRegistros::AdministradorRegistros(){
}

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
std::vector<Registro> AdministradorRegistros::obtenerLinea(std::string direccionArch){
    std::string mes, dia, horas, minutos, segundos, direccionIp, puerto, error;
    std::ifstream archivo(direccionArch);

    if (!archivo.is_open()){
        throw std::invalid_argument("No fue posible acceder al archivo.");
    }

    else{
        while (std::getline(archivo, mes, ' ') &&
               std::getline(archivo, dia, ' ') &&
               std::getline(archivo, horas, ':') &&
               std::getline(archivo, minutos, ':') &&
               std::getline(archivo, segundos, ' ') &&
               std::getline(archivo, direccionIp, ':') &&
               std::getline(archivo, puerto, ' ') &&
               std::getline(archivo, error))
        {
            Registro registroTemp(mes, dia, horas, minutos, segundos, direccionIp, puerto, error);
            listaRegistros.push_back(registroTemp);
        }

        archivo.close();
        return listaRegistros;
    }
}
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

Registro AdministradorRegistros::ingresarDatos(int intervalo){
    std::string fechaIn, mesIn, diaIn, horasIn, minutosIn, segundosIn;

    if (intervalo == 1){
        std::cout << "******************************************************" << std::endl;
        std::cout << "* BUSQUEDA DE INFORMACION POR INTERVALO DE TIEMPO *" << std::endl;
        std::cout << "******************************************************" << std::endl;
        std::cout << "Instrucciones: ingrese la primera fecha como el siguiente ejemplo ---> (Jun 01 00:22:36) ---> (mes dia hora:min:seg)" << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    else{
        std::cout << "\nIngrese la segunda fecha exactamente como se observa en el siguiente ejemplo ---> (Jun 01 00:22:36) ---> (mes dia hora:min:seg)" << std::endl;
    }

    try{
        std::cout << "Fecha: ";
        std::getline(std::cin, fechaIn);
        std::cout << std::endl;
        std::istringstream iss(fechaIn);

        std::getline(iss, mesIn, ' ');
        std::getline(iss, diaIn, ' ');
        std::getline(iss, horasIn, ':');
        std::getline(iss, minutosIn, ':');
        std::getline(iss, segundosIn);

        int dia = std::stoi(diaIn);
        int horas = std::stoi(horasIn);
        int minutos = std::stoi(minutosIn);
        int segundos = std::stoi(segundosIn);

        std::cout << "Conversion exitosa. " << "Día: " << dia << ", Horas: " << horas << ", Minutos: " << minutos << ", Segundos: " << segundos << std::endl;

        Registro fechaRegistrada(mesIn, diaIn, horasIn, minutosIn, segundosIn, "", "", "");
        return fechaRegistrada;
    }
    
    catch (const std::invalid_argument &e){
        std::cout << "No se puede convertir a entero. Error: " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
}

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

std::vector<Registro> AdministradorRegistros::ordenaVector(std::vector<Registro> &vectorFechas){
    int eleccionOrd;
    unsigned int comparaciones = 0;
    unsigned int intercambios = 0;
    std::vector<Registro> vectorFechasOrd;
    Registro ordenar;
    std::cout<<"Ingrese el tipo de ordenamiento que desee: 1 = Burbuja. 2 = Merge Sort" << "----> ";
    std::cin >> eleccionOrd;
    std::cout << std::endl;

    if (eleccionOrd == 1){
        ordenar.ordenaBurbuja(vectorFechas, comparaciones, intercambios);
        std::cout << "* Informacion Relativa al ordenamiento *" << std::endl;
        std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
        std::cout << "El numero de comparaciones en el ordenamiento Burbuja fue de: ";
        std::cout << comparaciones << std::endl;
        std::cout << "El numero de intercambios en el ordenamiento Burbuja fue de: ";
        std::cout << intercambios << std::endl;
        std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n" << std::endl;
        return vectorFechas;
    }

    else if (eleccionOrd == 2){
        ordenar.ordenaMerge(vectorFechas, 0, (int)vectorFechas.size() - 1, comparaciones, intercambios);
        std::cout << "* Informacion Relativa al ordenamiento *" << std::endl;
        std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
        std::cout << "El numero de comparaciones en el ordenamiento Merge Sort fue de: ";
        std::cout << comparaciones << std::endl;
        std::cout << "Merge sort no tiene intercambios, por lo tanto, el numero de intercambios en el ordenamiento fue de: ";
        std::cout << intercambios << std::endl;
        std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n" << std::endl;
        return vectorFechas;
    }

    else{
        throw std::invalid_argument("Tipo de ordenamiento no existente.");
    }

}

