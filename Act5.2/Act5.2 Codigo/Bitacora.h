#ifndef _BITACORA_H_
#define _BITACORA_H_

#include <vector>
#include <fstream>
#include <stdexcept>
#include <string>
#include "Graph.h"

class Bitacora{
private:
    Graph<std::string> graph;
    std::string searchedIp;

public:

    /*
     * Descripión:
     *      Constructor predeterminado de la clase Bitacora. No realiza ninguna operación específica,
     *      ya que está vacío. No requiere que se ingresen parámetros al crear un objeto Bitacora utilizando
     *      este constructor.
     *
     * Parámetros de entrada:
     *      No posee parámetros de entrada.
     *
     * Valor de retorno:
     *      No retorna ningún valor.
     *
     * Complejidad temporal:
     *      O(1)
     */

    Bitacora();

    /*
     * Descripión:
     *      Constructor que recibe un parámetro de tipo std::string llamado fileName el cual
     *      representa el nombre del archivo de bitácora que se leerá para construir la tabla
     *      hash en el objeto graph. El constructor realiza las siguientes operaciones:
     *
     *      - Se solicita al usuario que ingrese un número del 1 al 5 para determinar el tamaño máximo
     *        (MaxSize) de la tabla hash. Estos números representan los 5 números primos mayores más cercanos
     *        al número de direcciones IP presentes en la bitácora.
     *
     *      - Se utiliza el objeto graph para leer el archivo de bitácora como un grafo dirigido y construir
     *      la tabla hash con el tamaño determinado por la opción ingresada.
     *
     *      - Se invoca el método getHashT() para obtener la tabla hash construida.
     *
     *      - Se invoca el método printCollisions() para imprimir las colisiones presentes en la tabla hash.
     *
     *      - Se solicita al usuario que ingrese una dirección IP en formato string para obtener su resumen.
     *
     *      - Se captura cualquier excepción que pueda ocurrir durante la ejecución del código y se imprime un
     *        mensaje de error en caso de que ocurra alguna excepción.
     *
     * Parámetros de entrada:
     *      @fileName: string que representa el nombre del archivo de bitácora que se leerá.
     *
     * Valor de retorno:
     *      No retorna ningún valor.
     *
     * Complejidad temporal:
     *      O(n log n)
     */

    Bitacora(std::string fileName);

    /*
     * Descripión:
     *      Destructor predeterminado de la clase Bitacora. No realiza ninguna operación específica,
     *      ya que está vacío.
     *
     * Parámetros de entrada:
     *      No posee parámetros de entrada.
     *
     * Valor de retorno:
     *      No retorna ningún valor.
     *
     * Complejidad temporal:
     *      O(1)
     */

    ~Bitacora();
};


#endif // _BITACORA_H_