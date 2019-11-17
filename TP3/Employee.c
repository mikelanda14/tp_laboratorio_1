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
        newEmployee->id=0;
        strcpy(newEmployee->nombre," ");
        newEmployee->horasTrabajadas=0;
        newEmployee->sueldo=0;
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


    }
    return newEmployee;
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


int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=0;

    if(this!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;

        retorno=1;
    }

    return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int retorno =0;

    if(this != NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);

        retorno=1;
    }

    return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int retorno =0;

    if(this!=NULL && id!=NULL)
    {
        *id=this->id;

        retorno=1;
    }

    return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno =0;

    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo=this->sueldo;

        retorno=1;
    }

    return retorno;
}

int employee_comparacionPorNombre(void* personaA, void* personaB)
{
    Employee* auxA =( Employee*)personaA;
    Employee* auxB =(Employee*)personaB;
    int aux;

    aux=strcmp(auxA->nombre,auxB->nombre);

    return aux;
}
int employee_comparacionPorHoras(void* personaA, void* personaB)
{
    int aux=0;
    Employee* auxA=(Employee*)personaA;
    Employee* auxB=(Employee*)personaB;
    if(auxA->horasTrabajadas>auxB->horasTrabajadas)
    {
        aux=1;
    }
    else if(auxA->horasTrabajadas<auxB->horasTrabajadas)
    {

        aux=-1;
    }
    else
    {
        aux=0;
    }

    return aux;
}

int employee_comparacionPorSueldo(void* personaA, void* personaB)
{
    int aux=0;
    Employee* auxA=(Employee*)personaA;
    Employee* auxB=(Employee*)personaB;
    if(auxA->sueldo>auxB->sueldo)
    {

        aux=1;
    }
    else if(auxA->sueldo<auxB->sueldo)
    {

        aux=-1;
    }
    else
    {
        aux=0;
    }

    return aux;
}
