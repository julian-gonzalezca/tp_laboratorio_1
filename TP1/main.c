//Gonzalez Cardona, Julian. DIV 1f
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int opcion;
    int primerNumero;
    int segundoNumero;
    int suma;
    int resta;
    int multiplicacion;
    float division;
    double factorialA;
    double factorialB;
    int flagCalcularResultados;
    int flagInformarResultados;

    primerNumero = 0;
    segundoNumero = 0;
    flagCalcularResultados = 0;
    flagInformarResultados = 0;

    do
    {

        printf("\n\n     [_____CALCULADORA____]\n\n\n");

        printf("\n[1] Ingrese 1er operando (A=%d)\n", primerNumero);
        printf("[2] Ingrese 2do operando (B=%d)\n", segundoNumero);
        printf("[3] Calcular todas las operaciones:\n\n");
        printf(" a) Calcular la suma (%d+%d)\n", primerNumero, segundoNumero);
        printf(" b) Calcular la resta (%d-%d)\n", primerNumero, segundoNumero);
        printf(" c) Calcular la division (%d/%d)\n", primerNumero, segundoNumero);
        printf(" d) Calcular la multiplicacion (%d*%d)\n", primerNumero, segundoNumero);
        printf(" e) Calcular el factorial (%d!) y (%d!)\n\n",primerNumero, segundoNumero);
        printf("[4] Informar resultados: \n");
        printf("[5] SALIR\n");
        printf("\n    →Elija una opcion: ");
        scanf("\n%d", &opcion);
        getchar();

    switch(opcion)
        {
        case 1:
         do
         {
            printf("\n[1] Ingrese el 1er operando: ");
            flagCalcularResultados = 1;
         }
         while(ValidarNumeros("%d", &primerNumero));
         break;
        case 2:
         do
         {
            printf("\n[2] Ingrese el 2do operando: ");
            flagCalcularResultados = 1;
         }
         while(ValidarNumeros("%d", &segundoNumero));
         break;
        case 3:
            if(flagCalcularResultados==1)
            {
                printf("\n[3]Se estan calculando las operaciones, precione [4] para informar los resultados...\n");
                flagInformarResultados = 1;
            }
            else
            {
                printf("\n¡No ha ingresado ningun operando!");
            }
            break;

        case 4:
            if(flagCalcularResultados == 1 && flagInformarResultados == 1)
            {


            printf("\n");
            printf("[4] Informe de resultados:\n\n");
            suma = CalcularSuma(primerNumero, segundoNumero);
            printf(" a) El resultado de %d+%d es: %d\n", primerNumero, segundoNumero, suma);
            resta = CalcularResta(primerNumero, segundoNumero);
            printf(" b) El resultado de %d-%d es: %d\n", primerNumero, segundoNumero, resta);
            multiplicacion = CalcularMultiplicacion(primerNumero, segundoNumero);
            printf(" c) El resultado de %d*%d es: %d\n", primerNumero, segundoNumero, multiplicacion);
            division = CalcularDivision(primerNumero,segundoNumero);
            if (segundoNumero != 0)
            {
                printf(" d) El resultado de %d/%d es: %.1f\n", primerNumero, segundoNumero, division);
            }
            else
                {
                    printf(" d) ¡No se puede dividir por cero!\n");
                }
            factorialA = Factorial(primerNumero);
            if (primerNumero >= 0)
            {
                printf(" e) EL factorial de %d es: %1.f y", primerNumero, factorialA);
            }
            else
            {
                printf(" e) No se puede calcular el factorial de %d, porque es un numero negativo y", primerNumero);
            }
            factorialB = Factorial(segundoNumero);
            if (segundoNumero >= 0)
            {
                printf(" el factorial de %d es: %1.f", segundoNumero, factorialB);
            }
            else
            {
                printf(" no se puede calcular el factorial de %d, porque es un numero negativo.", segundoNumero);
            }
            return main();
            }
            else
            {
                printf("\n¡No se realizaron operaciones!\n→Si ya ingreso los operandos debe primero 'Calcular todas las operaciones [3]'");
            }
            break;
        case 5:
            printf("HASTA PRONTO!");
            break;
        default:
            printf("\n¡No es una opcion valida!");
        }

   }while(opcion!=5);

    return 0;
}

