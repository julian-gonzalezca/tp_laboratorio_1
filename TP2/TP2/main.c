//Gonzalez Cardona, Julian. DIV 1f
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#define T 1000
#define VACIO 0
#define LLENO 1


int main()
{
    int option;
    float average;
    int maxAverage;
    int flagEmployees;
    sEmployee arrayEmployees[T];
    initEmployees(arrayEmployees,T);

    flagEmployees = 0;

    do
    {
        menuEmployees(&option);
        switch(option)
        {
        case 1:
            addEmployees(arrayEmployees, T);
            flagEmployees = 1;
            break;
        case 2:
            if(flagEmployees == 1)
            {
              modifyEmployees(arrayEmployees, T);
            }
            else
            {
                printf("\nNo puede realizar modificaciones sin antes haber dado alta de empleados\n");
            }
            break;
        case 3:
            if(flagEmployees == 1)
            {
              removeEmployee(arrayEmployees, T);

            }
            else
            {
               printf("\nNo puede realizar bajas sin antes haber dado alta de empleados\n");
            }
            break;
        case 4:
            if(flagEmployees == 1)
            {
               sortEmployees(arrayEmployees, T);
               printf("\n::::::::::::::::DATOS DE EMPLEADOS::::::::::::::::\n\n");
               printf(":ID ::: APELLIDO ::: NOMBRE ::: SALARIO ::: SECTOR\n\n");
               printListEmployees(arrayEmployees, T);
               average = averageSalary(arrayEmployees, T);
               printf("\nEl salario promedio es: %.2f\n", average);
               maxAverage = employeesMaxAverage(arrayEmployees, T, average);
               printf("%d Empleado/s percibe/n salario por encima del promedio\n", maxAverage);
            }
            else
            {
               printf("\nNo se puede mostrar informe sin antes haber dado alta de empleados\n");
            }
            break;
        case 5:
            printf("\n         ¡¡HASTA PRONTO!!\n");
            break;
        default:
            printf("     No es una opcion!\n");
            break;
        }
    }while(option != 5);

    return 0;
}
