//Gonzalez Cardona, Julian. DIV 1f
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

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
