#ifndef _NUMBERS_H_
#define _NUMBERS_H_

#include <iostream>
#include <vector>

class Numbers{
    private:
        std::vector<int> sizesHashT;

        /*
         * Descripción: isPrime()
         *      Verifica si un número dado es primo utilizando el algoritmo básico de
         *      determinación de primos. El método utiliza una estrategia de optimización 
         *      para comprobar la primalidad del número. En lugar de probar divisibilidad 
         *      con todos los números menores que el número dado, el bucle while se ejecuta 
         *      hasta la raíz cuadrada del número. Esto se debe a una propiedad matemática: 
         *      si el número tiene un divisor más grande que su raíz cuadrada, también tendría 
         *      un divisor más pequeño que su raíz cuadrada. Dado que ya hemos comprobado todos 
         *      los posibles divisores más pequeños, no necesitamos comprobar los divisores más 
         *      grandes, lo que ahorra tiempo y mejora la eficiencia.
         *
         * Parámetros de entrada:
         *      @number: Un número entero el cual se desea comprobar si es o no es primo.
         *
         * Valor de retorno:
         *        Devuelve un valor booleano (true o false) que indica si el número dado
         *        es primo o no.
         *
         * Complejidad temporal:
         *      O(sqrt(number))
         */

        bool isPrime(int number);

    public:

        /*
         * Descripción:
         *      Constructor de la clase Numbers que se encarga de inicializar un objeto de la clase
         *      al vaciar su atributo sizesHashT
         *
         * Parámetros de entrada:
         *      No posee parámetros de entrada.
         *
         * Valor de retorno:
         *       No retorma ningún valor.
         *
         * Complejidad temporal:
         *       O(n)
         */

        Numbers();

        /*
         * Descripción:
         *      Destructor de la  clase Numbers que se encarga de liberar los recursos y limpiar 
         *      cualquier memoria asignada durante el ciclo de vida del objeto.
         *
         * Parámetros de entrada:
         *      No posee parámetros de entrada.
         *
         * Valor de retorno:
         *       No retorma ningún valor.
         *
         * Complejidad temporal:
         *       O(n)
         */

        ~Numbers();

        /*
         * Descripción: findClosePrime()
         *      Encuentra los primeros cinco números primos más cercanos (mayores) que
         *      un número dado y los devuelve en un vector.
         *
         * Parámetros de entrada:
         *      @number: Un número entero que se utilizará para encontrar los números
         *      primos más cercanos mayores que este valor.
         *
         * Valor de retorno:
         *       Devuelve un vector de enteros que contiene los cinco números primos más
         *       cercanos mayores que el número dado.
         *
         * Complejidad temporal:
         *       O(k * sqrt(n)), donde k es la cantidad de números primos cercanos a encontrar 
         *       (en este caso, k = 5) y n es el número dado.
         */

        std::vector<int> findClosePrime(int number);
};

#endif // _NUMBERS_H_
