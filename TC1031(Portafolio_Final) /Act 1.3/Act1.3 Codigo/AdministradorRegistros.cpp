#include "AdministradorRegistros.h"

AdministradorRegistros::AdministradorRegistros(){
}

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

        std::cout << "Conversion exitosa. " << "Dia: " << dia << ", Horas: " << horas << ", Minutos: " << minutos << ", Segundos: " << segundos << std::endl;

        Registro fechaRegistrada(mesIn, diaIn, horasIn, minutosIn, segundosIn, "", "", "");
        return fechaRegistrada;
    }
    
    catch (const std::invalid_argument &e){
        std::cout << "No se puede convertir a entero. Error: " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
}

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

