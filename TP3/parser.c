#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include <string.h>

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
int p;

char var[4][62];

    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", var[0],var[1],var[2],var[3]);
    do
    {
    p = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", var[0],var[1],var[2],var[3]);
    if(p==4){

            Employee* newEmployee = employee_new();
if(newEmployee!=NULL){
            ll_add(pArrayListEmployee,newEmployee);
            newEmployee=employee_newParametros(var[0],var[1],var[2],var[3]);

}

   /* if(newEmployee!=NULL){
          newEmployee->id=atoi(var[0]);
          strcpy(newEmployee->nombre,var[1]);
          newEmployee->horasTrabajadas=atoi(var[2]);
          newEmployee->sueldo=atoi(var[3]);
    }*/
    }
   else{
    break;
        }}
    while(!feof(pFile));

    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
