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

void Registro::imprimirDatos(const std::vector<Registro> &vectorRegistros){
    for (const Registro &registro : vectorRegistros){
        std::cout << registro.mes << " " << registro.dia << " " << registro.horas << ":" << registro.minutos << ":" << registro.segundos << " " << registro.direccionIp << ":" << registro.puerto << " " << registro.error << std::endl;
    }
}

time_t Registro::obtenerTiempo(){
    return tiempoTranscurrido;
}

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

void Registro::ordenaMerge(std::vector<Registro> &vectorRegistros, int inicioVector, int finalVector, unsigned int &comparacion, unsigned int &intercambio){

    if (inicioVector < finalVector){
        int puntoMedio = inicioVector + (finalVector - inicioVector) / 2;

        ordenaMerge(vectorRegistros, inicioVector, puntoMedio, comparacion, intercambio);
        ordenaMerge(vectorRegistros, puntoMedio + 1, finalVector, comparacion, intercambio);
        merge(vectorRegistros, inicioVector, puntoMedio, finalVector, comparacion, intercambio);
    }
}

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

std::vector<Registro> Registro::buscarFechas(std::vector<Registro> &vectorRegistrosOrd, Registro fechaInicio, Registro fechaFin){
    int registros = 0;
    std::vector<Registro> registroPersonalizado;

    for (int i = 0; i < (int)vectorRegistrosOrd.size(); i++){

        if (vectorRegistrosOrd[i] >= fechaInicio && vectorRegistrosOrd[i] <= fechaFin){
            registroPersonalizado.push_back(vectorRegistrosOrd[i]);
            registros++;
        }
    }

    std::cout << "\n* Los " << registros << " registros correspondientes al rango de fechas proporcionado son: *\n" << std::endl;
    return registroPersonalizado;
}

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
        std::cout << "La bitacora ordenada ha sido guardada con éxito en el archivo bitacora_ordenada.txt" << std::endl;
    }
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