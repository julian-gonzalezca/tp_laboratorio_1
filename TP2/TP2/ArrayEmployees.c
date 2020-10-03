#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#define VACIO 0
#define LLENO 1
sEmployee AddOneEmployee()
{
    int validName;
    int validLastName;
    int validNum;
    char auxSalary[21];
    sEmployee localEmployee;
    printf("\n::::INGRESO DE EMPLEADOS::::\n\n");
    localEmployee.id = idAleatory(1000,2000);
    printf("ID nuevo empleado: %d\n", localEmployee.id);
    do
    {
    printf("Ingrese nombre de empleado: ");
    __fpurge(stdin);
    scanf("%s", localEmployee.name);
    validName = validcadena(localEmployee.name);
    }while(validName==0);
    initialMayus(localEmployee.name);
    do
    {
    printf("Ingrese apellido de empleado: ");
    __fpurge(stdin);
    scanf("%s", localEmployee.lastname);
    validLastName = validcadena(localEmployee.lastname);
    }while(validLastName==0);
    initialMayus(localEmployee.lastname);
    do
    {
    printf("Ingrese salario: ");
    scanf("%s", auxSalary);
    validNum = validCadenaNum(auxSalary);
    }while(validNum==0);
    localEmployee.salary = atoi(auxSalary);
    printf("Ingrese sector 1/2/3: ");
    scanf("%d", &localEmployee.sector);
    getchar();
    while(!(localEmployee.sector == 1 || localEmployee.sector == 2 || localEmployee.sector == 3))
    {
       printf("No es un sector valido, Ingrese sector 1/2/3: ");
       scanf("%d", &localEmployee.sector);
       getchar();
    }
    return localEmployee;
}
void menuEmployees(int *option)
{
    printf("\n:::::::GESTION DE EMPLEADOS:::::::\n\n");
    printf("    |[1] Alta de empleados |\n");
    printf("    |[2] Modificar Empledos|\n");
    printf("    |[3] Bajas de empleados|\n");
    printf("    |[4] listar Empleados  |\n");
    printf("    |[5] Salir             |\n\n");
    printf("__________________________________\n");
    printf("     >>>Elija una opcion: ");
    scanf("%d", option);
    getchar();
}
void initEmployees(sEmployee arrayEmployees[], int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        arrayEmployees[i].isEmpty = VACIO;
    }
}
int addEmployees(sEmployee arrayEmployees[], int len)
{
    int i;
    char follow;
    int state;
    i = returnSpaceFree(arrayEmployees, len);
    if(i==-1)
    {
        state = -1;
    }
    else
    {
        for(;i<len;i++)
        {
            arrayEmployees[i]=AddOneEmployee();
            arrayEmployees[i].isEmpty=LLENO;

            if(returnSpaceFree(arrayEmployees, len)==-1)
            {
                state = 1;
                break;
            }
            printf("\n¿Desea ingresar un nuevo empleado? S/N: ");
            __fpurge(stdin);
            scanf("%c", &follow);
            if(!(follow == 'S' || follow == 's'))
            {
                state = 0;
                break;
            }
        }
    }
  return state;
}
int returnSpaceFree(sEmployee arrayEmployees[], int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        if(arrayEmployees[i].isEmpty==VACIO)
        {
           break;
        }
        if(i==len)
        {
            i=-1;
        }
    }
    return i;
}
int idAleatory(int min, int max)
{
  int id;
  srand(time(NULL));
  id = min + (rand()%(max+1-min));

  return id;
}
void printEmployee(sEmployee localParameter)
{
    printf("%d %10s %10s %12.2f %8d\n", localParameter.id, localParameter.lastname, localParameter.name, localParameter.salary, localParameter.sector);
}
void printListEmployees(sEmployee arrayEmployees[], int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        if(arrayEmployees[i].isEmpty==LLENO)
        {
           printEmployee(arrayEmployees[i]);
        }
    }
}
void removeEmployee(sEmployee arrayEmployees[], int len)
{
    int id;
    int i;
    printf("Ingrese el ID del empleado que desea eliminar: ");
    scanf("%d", &id);
    for(i=0;i<len;i++)
    {
        if(arrayEmployees[i].id == id)
        {
            arrayEmployees[i].isEmpty = VACIO;
        }
    }
}
void modifyEmployees(sEmployee arrayEmployees[], int len)
{
    int id;
    int i;
    int option;
    char follow;
    int validName;
    int validLastName;
    printf("\n\nIngrese ID del empleado que desea modificar: ");
    scanf("%d", &id);
    for(i=0;i<len;i++)
    {

        if(arrayEmployees[i].id == id)
        {
            do
            {
            printf("    ¿Que desea modificar?\n");
            printf("    [1] Nombre\n");
            printf("    [2] Apellido\n");
            printf("    [3] Salario\n");
            printf("    [4] Sector\n");
            printf("__________________________________\n");
            printf("    >>> Elija una opcion: ");
            __fpurge(stdin);
            scanf("%d", &option);
            switch(option)
                {
                case 1:
                    do
                    {
                    printf("Reingrese nombre de empleado: ");
                    __fpurge(stdin);
                    scanf("%s", arrayEmployees[i].name);
                    validName = validcadena(arrayEmployees[i].name);
                    }while(validName==0);
                    initialMayus(arrayEmployees[i].name);
                    break;
                case 2:
                    do
                    {
                    printf("Reingrese apellido de empleado: ");
                    __fpurge(stdin);
                    scanf("%s", arrayEmployees[i].lastname);
                    validLastName = validcadena(arrayEmployees[i].lastname);
                    }while(validLastName==0);
                    initialMayus(arrayEmployees[i].lastname);
                    break;
                case 3:
                    printf("\nReingrese salario: ");
                    scanf("%f", &arrayEmployees[i].salary);
                    break;
                case 4:
                    printf("Reingrese sector 1/2/3: ");
                    scanf("%d", &arrayEmployees[i].sector);
                    getchar();
                    while(!(arrayEmployees[i].sector == 1 || arrayEmployees[i].sector == 2 || arrayEmployees[i].sector == 3))
                    {
                    printf("No es un sector valido, Ingrese sector 1/2/3: ");
                    scanf("%d", &arrayEmployees[i].sector);
                    getchar();
                    }
                    break;
                default:
                    printf("No es una opcion!!\n");
                }printf("¿Desea Modificar otro dato del mismo empleado? S/N: ");
                __fpurge(stdin);
                scanf("%c", &follow);
            }while(follow == 's' || follow == 'S');
        }
    }

}
void initialMayus(char cadena[])
{
    int i;
    for(i=0;cadena[i]!='\0'; i++)
    {
        cadena[i] = tolower(cadena[i]);
    }
    cadena[0] = toupper(cadena[0]);
}
void sortEmployees(sEmployee arrayEmployees[], int len)
{
    int i;
    int j;
    sEmployee auxEmployee;
    sEmployee auxSector;
    for(i=0;i<len;i++)
    {
        for(j=i+1;j<len; j++)
        {
            if(strcmp(arrayEmployees[i].lastname, arrayEmployees[j].lastname)>0)
            {
                auxEmployee = arrayEmployees[i];
                arrayEmployees[i] = arrayEmployees[j];
                arrayEmployees[j] = auxEmployee;
            }
            if((strcmp(arrayEmployees[i].lastname, arrayEmployees[j].lastname)==0) && (arrayEmployees[i].sector>arrayEmployees[j].sector))
            {
                auxSector = arrayEmployees[i];
                arrayEmployees[i] = arrayEmployees[j];
                arrayEmployees[j] = auxSector;
            }
        }
    }
}
float averageSalary(sEmployee arrayEmployees[], int len)
{
    float average;
    int i;
    int count;
    count = 0;
    for(i=0;i<len;i++)
    {
        if(arrayEmployees[i].isEmpty==LLENO)
        {
            count++;
        }
    }
    for(i=0;i<len;i++)
    {
        if(arrayEmployees[i].isEmpty==LLENO)
        {
          average = average + arrayEmployees[i].salary/count;
        }

    }
    return average;
}
int employeesMaxAverage(sEmployee arrayEmployees[], int len, float average)
{
    int i;
    int count;
    count = 0;
    for(i=0;i<len;i++)
    {
        if(arrayEmployees[i].salary > average)
        {
            count++;
        }
    }
    return count;
}
int validcadena(char cadena[])
{
    int i;
    for(i=0;i<strlen(cadena);i++)
    {
        if(!((cadena[i]>=65 && cadena[i]<=90) || (cadena[i]>=97 && cadena[i]<=122)))
        {
           printf("Lo que ingreso no corresponde a un nombre/apellido!\n");
           return 0;
        }
    }
    return 1;
}
int validCadenaNum(char cadena[])
{
    int i;
    for(i=0;i<strlen(cadena);i++)
    {
        if(!(cadena[i]>=48 && cadena[i]<=57))
        {
           printf("Lo que ingreso no corresponde a un valor numerico!\n");
           return 0;
        }
    }
    return 1;
}


