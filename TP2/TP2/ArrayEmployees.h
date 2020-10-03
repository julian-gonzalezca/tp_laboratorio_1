typedef struct

{
    int id;
    char name[51];
    char lastname[51];
    float salary;
    int sector;
    int isEmpty;

}sEmployee;
/**< Realiza la carga de cada empleado */
sEmployee AddOneEmployee();
/** \brief Muestra el menu principal
 * \return Devuelve la opcion seleccionada
 */
void menuEmployees(int *option);
/**< Recorre el array de empleados y lo inicializa con valor 0 en todas sus posiciones */
void initEmployees(sEmployee arrayEmployees[], int len);
/** \brief realiza la carga de los empleados en la posicion que este vacia.
 * \param recibe el array de empleados
 * \param el tamaño del array
 */
int addEmployees(sEmployee arrayEmployees[], int len);
/** \brief recorre el array de empleados en busca de posicion vacia
 * \param recibe el array de empleados
 * \param el tamaño del array
 * \return el primer lugar libre que encuentre
 */
int returnSpaceFree(sEmployee arrayEmployees[], int len);
/** \brief genera el id aleatorio
 * \param el numero minimo a partir de donde generara el id
 * \param el numero maximo hasta donde generara el id
 * \return id
 */
int idAleatory(int min, int max);
/**< imprime un empleado */
void printEmployee(sEmployee localParameter);
/** \brief imprime lista de empleados haciendo uso de la funcion anterior
 * \param recibe el array de empleados
 * \param el tamaño del array
 */
void printListEmployees(sEmployee arrayEmployees[], int len);
/** \brief remueve un empleado
 * \param recibe el array de empleados
 * \param el tamaño del array
 */
void removeEmployee(sEmployee arrayEmployees[], int len);
/** \brief modifica un empleado
 * \param recibe el array de empleados
 * \param el tamaño del array
 */
void modifyEmployees(sEmployee arrayEmployees[], int len);
/**< recibe una cadena de caracteres, convierte todas los caracteres en minuscula y posterior el caracter ubicado en la posicion 0 lo convierte en mayuscula */
void initialMayus(char cadena[]);
/** \brief ordena los empleados segun apellido y sector
 * \param recibe el array de empleados
 * \param el tamaño del array
 */
void sortEmployees(sEmployee arrayEmployees[], int len);
/** \brief realiza el promedio de los salarios
 * \param recibe el array de empleados
 * \param el tamaño del array
 * \return el promedio
 */
float averageSalary(sEmployee arrayEmployees[], int len);
/** \brief busca cuantos empleados perciben salario por encima del promedio
 * \param recibe el array de empleados
 * \param el tamaño del array
 * \return la cantidad de empleados que perciben salario por encima del promedio
 */
int employeesMaxAverage(sEmployee arrayEmployees[], int len, float average);
/** \brief valida que una cadena de caracteres sea alfabetica y numerica
 * \param cadena de caracteres
 * \return 1 en caso de ser alfabetica o 0 en caso de ser numerica
 */
int validcadena(char cadena[]);
/** \brief valida que una cadena de caracteres sea numerica y no alfabetica
 * \param cadena de caracteres
 * \return 1 en caso de ser numerica o 0 en caso de ser alfabetica
 */
int validCadenaNum(char cadena[]);


