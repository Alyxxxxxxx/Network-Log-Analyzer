#ifndef _ACCESSTRACKER_H_
#define _ACCESSTRACKER_H_

#include "Registro.h"
#include "MaxHeap.h"

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <unordered_map>

class AccessTracker{
    private:
        std::string ipAccess;
        unsigned int numeroAccesos;
        
    public:
        /*
         * Descripción:
         *  Este constructor crea un objeto AccessTracker con los valores proporcionados
         *  para sus miembros ipAccess y numeroAccesos.
         *
         * Parámetros de entrada:
         *  @_ipAccess: Valor para el miembro ipAccess.
         * 
         *  @_numeroAccesos: Valor para el miembro numeroAccesos.
         * 
         * Valor de retorno:
         *  No retorna ningún valor.
         * 
         * Complejidad temporal:
         *  O(1)
         */

        AccessTracker(std::string _ipAccess, unsigned int _numeroAccesos);

        /*
         * Descripción:
         *  Constructor por defecto de la clase AccessTracker, que inicializa
         *  todos sus miembros por defecto.
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

        AccessTracker();

        /*
         * Descripción: cuentaAccesos()
         *  Método que realiza un recuento eficiente del número de accesos para cada
         *  dirección IP almacenada en el vector de objetos Registro. Esto se logra
         *  a través de una estructura de datos unordered_map para almacenar las
         *  direcciones IP como claves y el número de accesos correspondiente como
         *  valores.
         *
         *  Posteriormente, se crea un Max Heap con objetos AccessTracker creados a
         *  partir de los pares (dirección IP, número de accesos) almacenados en el
         *  unordered_map. Se guarda el MaxHeap en un archivo.
         *
         *  Finalmente, llama al método obtieneMayorIp para obtener las 10 direcciones
         *  IP con mayor número de accesos.
         *
         *  Se utiliza un unordered map debido a su implementación por medio de una
         *  tabla hash y su capacidad para almacenar pares clave- valor, donde cada
         *  clave es única y se mapea a un valor correspondiente.
         *
         * Parámetros de entrada:
         *  @_vectorReg: Una referencia constante a un vector de objetos Registro.
         * 
         * Valor de retorno:
         *  No retorna ningún valor.
         * 
         * Complejidad temporal:
         *  O(n log n)
         */

        void cuentaAccesos(const std::vector<Registro>& _vectorReg);

        /*
         * Descripción: obtieneMayorIp()
         *  Obtiene las 10 direcciones IP con mayor número de accesos a partir de un
         *  Max Heap de objetos AccessTracker, y las guarda en un archivo.
         *
         * Parámetros de entrada:
         *  @heapIp: Un Max Heap de objetos AccessTracker.
         *
         *  @direccionArch: Una cadena que representa la dirección del archivo donde se
         *  guardarán las direcciones IP con mayor número de accesos.
         *
         * Valor de retorno:
         *  No retorna ningún valor.
         *
         * Complejidad temporal:
         *  O(10 log n). Cada operación de extracción tiene una complejidad de O(log n)
         *  y se repite 10 veces.
         */

        void obtieneMayorIp(MaxHeap<AccessTracker> heapIp, std::string direccionArch);

        /*
         * Descripción:
         *  Sobrecarga de operador permite imprimir un objeto AccessTracker en una
         *  corriente de salida.
         *
         * Parámetros de entrada:
         *  @os: Una referencia a una corriente de salida.
         *
         *  @object: Una referencia constante al objeto AccessTracker que se imprimirá.
         *
         * Valor de retorno:
         *  Retorna una referencia a la corriente de salida os.
         * 
         * Complejidad temporal:
         *  O(1)
         */

        friend std::ostream& operator<<(std::ostream& os, const AccessTracker& object);

        /*
         * Descripción:
         *  Sobrecargas de operadores que permiten comparar dos objetos AccessTracker en
         *  función del número de accesos (numeroAccesos).
         *
         * Parámetros de entrada:
         *  @other: Una referencia constante a otro objeto AccessTracker con el que se
         *  realizará la comparación.
         *
         * Valor de retorno:
         *  Valor booleano que indica el resultado de la comparación entre dos objetos de
         *  la classe AccessTracker.
         *
         * Complejidad temporal:
         *  O(1) cada uno.
         */

        bool operator==(const AccessTracker &other) const;
        bool operator!=(const AccessTracker &other) const;
        bool operator>(const AccessTracker &other) const;
        bool operator<(const AccessTracker &other) const;
        bool operator>=(const AccessTracker &other) const;
        bool operator<=(const AccessTracker &other) const;
};

AccessTracker::AccessTracker(std::string _ipAccess, unsigned int _numeroAccesos){
    ipAccess = _ipAccess;
    numeroAccesos = _numeroAccesos;
}

AccessTracker::AccessTracker(){
    numeroAccesos = 0;
    ipAccess = "";
}


void AccessTracker::cuentaAccesos(const std::vector<Registro>& _vectorReg){
    std::unordered_map<std::string, int> contador;
    unsigned int comparacion, intercambio;

    for (const Registro& registro : _vectorReg){
        contador[registro.getIp()]++;
    }

    MaxHeap<AccessTracker> heapIp(contador.size());

    for (const auto& par : contador){
        heapIp.push(AccessTracker(par.first, par.second));
    }

    heapIp.saveHeap("contabilizacion_Ips_heap.txt");

    std::cout << "Se almaceno correctamente en un Heap Tree los IPs junto con su numero de apariciones en la bitacora." << std::endl;
    std::cout << "Consulte en el archivo 'contabilizacion_Ips_heap.txt'." << std::endl;

    obtieneMayorIp(heapIp, "ips_con_mayor_acceso.txt");
}

void AccessTracker::obtieneMayorIp(MaxHeap<AccessTracker> heapIp, std::string direccionArch){
    std::ofstream archivo(direccionArch);
    
    if (!archivo.is_open()){
        archivo.close();
        throw std::invalid_argument("No fue posible acceder al archivo.");
    }

    std::cout << "\nSe encontraron las 10 IPs mas accesos. Presione [ENTER] para visualizarlas. ";
    std::cin.ignore(); 
    std::cout << "\n";

    for (int i = 0; i < 10; i++){
        auto topElement = heapIp.getTop();
        std::cout << topElement << std::endl;
        archivo << topElement << std::endl;
        heapIp.pop();
    }

    archivo.close();
    std::cout << "\nLa bitacora con las 10 IPs han sido guardadas con exito en el archivo " << direccionArch << std::endl;
    std::cout << "\n--------------------------------------FINALIZACION DE BUSQUEDA------------------------------------\n" << std::endl;
}


std::ostream& operator<<(std::ostream& os, const AccessTracker& object){
    os << "IP: " << object.ipAccess << " " <<  "Numero de apariciones: " << object.numeroAccesos;
    return os;
}

bool AccessTracker::operator==(const AccessTracker &other) const{
    return this->numeroAccesos == other.numeroAccesos;
}

bool AccessTracker::operator!=(const AccessTracker &other) const{
    return this->numeroAccesos != other.numeroAccesos;
}

bool AccessTracker::operator>(const AccessTracker &other) const{
    return this->numeroAccesos > other.numeroAccesos;
}

bool AccessTracker::operator<(const AccessTracker &other) const{
    return this->numeroAccesos < other.numeroAccesos;
}

bool AccessTracker::operator>=(const AccessTracker &other) const{
    return this->numeroAccesos >= other.numeroAccesos;
}

bool AccessTracker::operator<=(const AccessTracker &other) const{
    return this->numeroAccesos <= other.numeroAccesos;
}

#endif //_ACCESSTRACKER_H_