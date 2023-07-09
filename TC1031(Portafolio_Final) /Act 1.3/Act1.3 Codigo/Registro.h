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
        Registro(std::string pMes, std::string pDia, std::string pHoras, std::string pMinutos, std::string pSegundos, std::string pDireccionIp, std::string pPuerto, std::string pError);
        void imprimirDatos(const std::vector<Registro> &vectorRegistros);
        time_t obtenerTiempo();
        void ordenaBurbuja(std::vector<Registro> &vectorRegistros, unsigned int &comparacion, unsigned int &intercambio);
        void ordenaMerge(std::vector<Registro> &vectorRegistros, int inicioVector, int finalVector, unsigned int &comparacion, unsigned int &intercambio);
        void merge(std::vector<Registro> &vectorRegistros, int inicioVector, int puntoMedio, int finalVector, unsigned int &comparacion, unsigned int &intercambio);
        int busquedaBinaria(std::vector<Registro> &vectorRegistrosOrd, Registro fechaBuscada, unsigned int &comparacion);
        std::vector<Registro> buscarFechas(std::vector<Registro> &vectorRegistrosOrd, Registro fechaInicio, Registro fechaFin);
        void guardarBitacoraOrd(std::vector<Registro> vectorOrdenado, std::string nombreArch);
        bool operator==(const Registro &other) const;
        bool operator!=(const Registro &other) const;
        bool operator>(const Registro &other) const;
        bool operator<(const Registro &other) const;
        bool operator>=(const Registro &other) const;
        bool operator<=(const Registro &other) const;
};

#endif //_REGISTRO_H_