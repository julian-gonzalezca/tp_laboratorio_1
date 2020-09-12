//Gonzalez Cardona, Julian. DIV 1f
#include <stdio.h>

/** \brief Calcula la suma de dos numeros enteros
 * \param int El primer numero
 * \param int El segundo numero
 * \return int El resultado de la operacion
 */
int CalcularSuma(int, int);

/** \brief Calcula la resta de dos numeros enteros
 * \param int El primer numero
 * \param int El segundo numero
 * \return int el resultado de la operacion.
 */
int CalcularResta(int, int);

/** \brief Calcula la multiplicacion de dos numeros enteros
 * \param int El primer numero
 * \param int El segundo numero
 * \return int el resultado de la operacion.
 */
int CalcularMultiplicacion(int, int);

/** \brief Calcula la division de dos numeros enteros si el divisor es distinto de 0
 * \param int El primer numero/dividendo
 * \param int El segundo numero/divisor
 * \return float el resultado de la operacion.
 */
float CalcularDivision(int, int);

/** \brief Calcula el factorial de un numero
 * \param int El numero a ser factorizado
 * \return int El factorial del numero
 */
int Factorial(int);

/** \brief Toma el dato ingresado para validar si es numero
 *
 * \param condiciona el ingreso de caracteres
 * \param verifica el bufer del teclado y lo limpia
 * \return devuelve 0 si no ingreso a la iteracion, validando el dato como numerico.
 *
 */

int ValidarNumeros(const char*, void*);
