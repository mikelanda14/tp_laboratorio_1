#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"



Employee* employee_new()
{
    Employee* newEmployee = (Employee*)malloc(sizeof(Employee));
    if(newEmployee!=NULL)
    {
        return newEmployee;
    }
    return 0;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* newEmployee=employee_new();
    int r=0;

    if(newEmployee!=NULL)
    {
        if(employee_setId(newEmployee,atoi(idStr)))
        {


            if(employee_setNombre(newEmployee,nombreStr))
            {


                if(employee_setHorasTrabajadas(newEmployee,atoi(horasTrabajadasStr)))
                {


                    if(employee_setSueldo(newEmployee,atoi(sueldoStr)))
                    {
                        r=1;
                    }
                }
            }
        }
        if(r == 0)
        {
            free(newEmployee);
            newEmployee = NULL;
        }


    } return newEmployee;
    }


    int employee_setId(Employee* this,int id)
    {
        int r=0;
        if(this!=NULL)
        {
            this->id=id;
            r=1;
        }
        return r;
    }


    int employee_setNombre(Employee* this,char* nombre)
    {

        int r=0;
        if(this!=NULL)
        {
            strcpy(this->nombre,nombre);
            r=1;
        }
        return r;
    }


    int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
    {
        int r=0;
        if(this!=NULL)
        {
            this->horasTrabajadas=horasTrabajadas;
            r=1;
        }
        return r;
    }


    int employee_setSueldo(Employee* this,int sueldo)
    {
        int r=0;
        if(this!=NULL)
        {
            this->sueldo=sueldo;
            r=1;
        }
        return r;

    }
