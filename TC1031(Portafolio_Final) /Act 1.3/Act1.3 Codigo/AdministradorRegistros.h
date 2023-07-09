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
        std::vector<Registro> obtenerLinea(std::string direccionArch);
        Registro ingresarDatos (int intervalo);
        std::vector<Registro> ordenaVector(std::vector<Registro> &vectorFechas);
};

#endif // _AdministradorRegistros_H_

