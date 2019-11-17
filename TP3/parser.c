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

            newEmployee=employee_newParametros(var[0],var[1],var[2],var[3]);
             ll_add(pArrayListEmployee,newEmployee);
}
}
   else{
    break;
        }

        }
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
    Employee* employeeReadB;
int r;
while(!feof(pFile)){
    employeeReadB=employee_new();
r=fread(employeeReadB,sizeof(Employee),1,pFile);
if(r==1){

    ll_add(pArrayListEmployee,employeeReadB);
}
}
    return 1;
}
