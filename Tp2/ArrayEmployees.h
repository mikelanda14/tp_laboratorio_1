typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}Employee;

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 *\param len int Array length
 *\param Employe[] paso por valor
 *
 */
int initEmployees(Employee Employe[], int len);
/** \brief Imprime en pantalla los nombres de funciones y espera a la entrada por el usuario, para luego ejecutar la funcion deseada
 * in the first empty position
 * \param employee[]
 * \param len int
 *
 */
void menuOpciones(Employee Employee[],int len);
/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee[]
 * \param len int
 *
 */
int addEmployee(Employee Employe[], int len);
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param Employe[]
 * \param len int
 *
 */


int removeEmployee(Employee Employee[],int len);
/** \brief print the content of employees array
*
* \param Employe[]
* \param len int
* \return int
*
*/
int printEmployees(Employee Employe[], int len);
/** \brief Modifica content of employees array
*
* \param Employe[]
* \param len int
* \return int
*
*/
int modEmployees(Employee Employe[],int len);

/** \brief Genera Automaticamente el ID en autoincremento a partir de content of employees array
*
* \param Employe[]
* \param len int
* \return int
*
*/
int generarId(Employee Employe[],int len);
/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param  Employe[]
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int
*
*/
int sortEmployees(Employee Employe[], int len);
/** \brief busca si existe alguna casilla ocupada en el Array Employee[]
*
* \param Employee[]
* \param len int
* \param
* \return int Return (1) si existe contenido - (0) si no existe registro
*
*/
int ifAllEmpty(Employee Employe[],int len);

