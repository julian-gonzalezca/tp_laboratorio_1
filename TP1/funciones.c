//Gonzalez Cardona, Julian. DIV 1f
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>
static int getInt(int* pResultado);
static int esNumerica(char* candena);
static int myGets(char* cadena, int longitud);

int CalcularSuma(int primerNumero, int segundoNumero)
{
   int suma;

   suma = primerNumero + segundoNumero;

   return suma;
}
int CalcularResta(int primerNumero, int segundoNumero)
{
    int resta;

    resta = primerNumero - segundoNumero;

    return resta;
}
int CalcularMultiplicacion(int primerNumero, int segundoNumero)
{
    int multiplicacion;

    multiplicacion = primerNumero * segundoNumero;

    return multiplicacion;
}
float CalcularDivision(int primerNumero, int segundoNumero)
{
    float division;

    if(segundoNumero != 0)
    {
        division = (float)primerNumero / segundoNumero;
    }

    return division;
}
int Factorial(int numero)
{
    double factorial;
    int i;
    factorial = 1;

    if(numero>=0)
    {

    for(i=numero; i > 1; i--)
    {
       factorial = factorial * i;
    }
    }

        return factorial;

}
int ValidarNumeros(const char* fMascara, void* variable)
{
    int caracter;
    if(!scanf(fMascara, variable))
    {
        while((caracter = getchar()) != '\n' && caracter != EOF);
        printf("\n¡Lo que ingreso no es un numero!\n");
        return 1;
    }
    if(getchar() != '\n')
    {
        while((caracter = getchar()) != '\n' && caracter != EOF);
        printf("\n¡Lo que ingreso no es un numero!\n");
        return 1;
    }
    return 0;
}

    // funcion para obtener datos por teclado
static int getInt(int* pResultado)
{
    int retorno = -1;
    char buffer[4096];
    //__fpurge(stdin);
    //scanf("%d", buffer);
    if(myGets(buffer, sizeof(buffer))==0 && esNumerica(buffer))
    {
        retorno = 0;
        *pResultado = atoi(buffer);
    }
    return retorno;
}
//funcion para verificar si en la cadena de caracteres hay numeros
static int esNumerica(char* cadena)
{
    int retorno = 1; // verdadero
    int i = 0;

    if(cadena[0] == '-')
    {
        i = 1;
    }

    for( ; cadena[i] != '\0';i++)
    {
        if(cadena[i] > '9' || cadena[i] < '0')
        {
            retorno = 0;
            break;
        }
    }
     return retorno;
}
static int myGets(char* cadena, int longitud)
{
    __fpurge(stdin);
    fgets(cadena, longitud, longitud);
    cadena[strlen(cadena)-1] == '\0';

    return 0;
}
