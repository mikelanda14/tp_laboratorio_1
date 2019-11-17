#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{

FILE *pFile;
int r=0;

pFile = fopen(path,"r");
    if(pFile != NULL)
    {
parser_EmployeeFromText(pFile ,pArrayListEmployee);
    fclose(pFile);
    r=1;
    }
    else{
            printf("El archivo no existe");

    r=-1;
    }

return r;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE *pFile;
int r=0;

pFile = fopen(path,"rb");
    if(pFile != NULL)
    {
        parser_EmployeeFromBinary(pFile ,pArrayListEmployee);

    fclose(pFile);
    r=1;
    }
    else{
            printf("El archivo no existe");

    r=-1;
    }return r;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorn=0;
    Employee* addNewEmployee=employee_new();
    int idAuto;
    idAuto=controller_AutoId(pArrayListEmployee);
    char nombre[62];
    int r=1;
    int salarioEmpleado;
    int horasTrabajadas;
    r=getString(nombre,"\nnombre del empleado : ","\nError el nombre Debe tener almenos 3 caracteres",3,100);
    r=getInt(&salarioEmpleado,"\nel Sueldo del empleado : ","el rango es [1]-[2000000]",0,2000000);
    r=getInt(&horasTrabajadas,"\nCantidad de horas trabajadas : ","\nError rango [1]-[744]",1,744);
    if(r==0){
    employee_setId(addNewEmployee,idAuto);

    employee_setSueldo(addNewEmployee,salarioEmpleado);

    employee_setHorasTrabajadas(addNewEmployee,horasTrabajadas);

    employee_setNombre(addNewEmployee,nombre);
    ll_add(pArrayListEmployee,addNewEmployee);
    retorn=1;
    }
    return retorn;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
      int retorn=0;
    int i,r,modificar=0;
    char nombre[62];
    int horasTrabajadas;
    int salarioEmpleado;
    int employeeID;
    int idMod;
    int len;
    int hiLimit=controller_AutoId(pArrayListEmployee);
    Employee* employeeMod=employee_new();
    getInt(&idMod,"\nintrodusca el Id del empleado a Modificar:","\nID Fuera de rango\n",0,hiLimit);
    len=ll_len(pArrayListEmployee);

    for(i=0;i<len;i++){
     employeeMod=ll_get(pArrayListEmployee,i);
     employeeID=employeeMod->id;
        if(employeeID==idMod){
        while(modificar!=4){
                system("cls");
        printf("\n                             ID    Nombre              Horas             Sueldo\n\n");
        printf("\nEl empleado a modificar es: %5d %15s %13d %20d\n\n",employeeMod->id,employeeMod->nombre,employeeMod->horasTrabajadas,employeeMod->sueldo);

        getInt(&modificar,"\n1)Nombre\n2)HorasTrabajadas\n3)Salario\n4))Salir\nDigite la opcion","\Error Fuera de rango\nDigite su opcion nuevamente",1,4);

           switch(modificar){
       case 1:
            r=getString(nombre,"\nnombre del empleado : ","\nError el nombre Debe tener almenos 3 caracteres",3,100);

        if(r==0){
                employee_setNombre(employeeMod,nombre);

        }

        break;
       case 2:

        r=getInt(&horasTrabajadas,"\nCantidad de horas trabajadas : ","\nError rango [1]-[744]",1,744);
    if(r==0){
        employee_setHorasTrabajadas(employeeMod,horasTrabajadas);

    }

        break;
       case 3:
           r=getInt(&salarioEmpleado,"\nel Sueldo del empleado : ","el rango es [1]-[2000000]",0,2000000);


    if(r==0){
    employee_setSueldo(employeeMod,salarioEmpleado);

    }
        break;

           }

     }

    }retorn=1;}
    return retorn;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorn=0;
    int i,r,eliminar;
    int employeeID;
    int idRemove;
    int len;
    int hiLimit=controller_AutoId(pArrayListEmployee);
    Employee* employeeBaja=employee_new();
    getInt(&idRemove,"\nintrodusca el Id del empleado a dar de baja :","\nID Fuera de rango\n",0,hiLimit);
    len=ll_len(pArrayListEmployee);

    for(i=0;i<len;i++){
     employeeBaja=ll_get(pArrayListEmployee,i);
     employeeID=employeeBaja->id;
        if(employeeID==idRemove){
        printf("\nEl empleado a dar de baja es: %d %s %d %d\n\n",employeeBaja->id,employeeBaja->nombre,employeeBaja->horasTrabajadas,employeeBaja->sueldo);
        getInt(&eliminar,"\npresione 1 eliminar\n0 para cancelar","",0,1);
            if(eliminar==1){
                r=ll_remove(pArrayListEmployee,i);
                if(r==0){
                printf("\nBaja exitosa\n");
                retorn=1;
                break;
            }else if(eliminar==0){
                retorn=1;
            break;
            }
        }
     }

    }
    return retorn;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{

    Employee* listEmployee;
    int len=ll_len(pArrayListEmployee);
    int employeeId;
    char employeeNombre[62];
    int employeeHoras;
    int employeeSueldo;
    int cont=0;
    int r=0;
    int i;


    for(i=0;i<len;i++){
        listEmployee=ll_get(pArrayListEmployee,i);


        employee_getId(listEmployee,&employeeId);;
        employee_getHorasTrabajadas(listEmployee,&employeeHoras);
        employee_getNombre(listEmployee,employeeNombre);
        employee_getSueldo(listEmployee,&employeeSueldo);

        printf("\n%5d     %10s    %15d     %20d",employeeId,employeeNombre,employeeHoras,employeeSueldo);
        cont++;

    }
if(cont==ll_len(pArrayListEmployee)){
    r=1;
}
printf("\n\n");
system("pause");
system("cls");
    return r;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion=0;
    LinkedList* cloneListaEmple;
    cloneListaEmple=ll_clone(pArrayListEmployee);
    while(opcion!=7){

    system("cls");

    printf("\n1)Ordenar por nombre de A a Z\n2)Ordenar por nombre de Z a A");
    printf("\n3)Ordenar por Sueldos de menor a mayor\n4)Ordenar por Sueldos de mayor a menor");
    printf("\n5)Ordenar por Horas trabajadas de menor a mayor\n6)Ordenar por Horas trabajadas de mayor a menor\n7)Salir");
    getInt(&opcion,"\nDigite la Opcion deseada: ","\nNo es una opcion valida",1,7);
    switch(opcion){
    case 1:
        printf("\n\nPROCESANDO POR FAVOR ESPERE......\n\n");
        ll_sort(cloneListaEmple, employee_comparacionPorNombre, 1);
    controller_ListEmployee(cloneListaEmple);
    system("pause");

    break;
    case 2:
         printf("\n\nPROCESANDO POR FAVOR ESPERE......\n\n");
        ll_sort(cloneListaEmple, employee_comparacionPorNombre, 0);
    controller_ListEmployee(cloneListaEmple);
   system("pause");
        break;
    case 3:
        printf("\n\nPROCESANDO POR FAVOR ESPERE......\n\n");
        ll_sort(cloneListaEmple, employee_comparacionPorHoras, 1);
    controller_ListEmployee(cloneListaEmple);
    system("pause");
        break;
    case 4:
        printf("\n\nPROCESANDO POR FAVOR ESPERE......\n\n");
        ll_sort(cloneListaEmple, employee_comparacionPorHoras, 0);
    controller_ListEmployee(cloneListaEmple);
    system("pause");
        break;
    case 5:
        printf("\n\nPROCESANDO POR FAVOR ESPERE......\n\n");
        ll_sort(cloneListaEmple, employee_comparacionPorSueldo, 1);
    controller_ListEmployee(cloneListaEmple);
    system("pause");
        break;
    case 6:
        printf("\n\nPROCESANDO POR FAVOR ESPERE......\n\n");
        ll_sort(cloneListaEmple, employee_comparacionPorSueldo, 0);
    controller_ListEmployee(cloneListaEmple);
    system("pause");
        break;

    }

    }
    ll_deleteLinkedList(cloneListaEmple);
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int i,r=0;
    int employeeId,employeeHoras,employeeSueldo;
    char employeeNombre[62];
    Employee* listEmployee=employee_new();
    FILE* pFile;
    pFile = fopen(path,"w");
      if(pFile != NULL)
    {
        for(i=0;i<ll_len(pArrayListEmployee);i++){

        listEmployee=ll_get(pArrayListEmployee,i);
        employeeId=listEmployee->id;
        strcpy(employeeNombre,listEmployee->nombre);
        employeeHoras=listEmployee->horasTrabajadas;
        employeeSueldo=listEmployee->sueldo;

        fprintf(pFile,"\n%d,%s,%d,%d",employeeId,employeeNombre,employeeSueldo,employeeHoras);

    } fclose(pFile);
    r=1;
    }else{
            printf("El archivo no existe");

    r=-1;

    }return r;
}



/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{

    FILE* pFile;
    pFile = fopen64(path,"wb");
    int i,r=0;
    Employee* employeeAux=employee_new();

      if(pFile != NULL)
    {
        for(i=0;i<ll_len(pArrayListEmployee);i++){

        employeeAux=ll_get(pArrayListEmployee,i);


         fwrite(employeeAux,sizeof(Employee),1,pFile); // escribo una struct al final

    } fclose(pFile);
    r=1;
    }else{
            printf("El archivo no existe");

    r=-1;

    }return r;
}
/** \brief crea un id no repetido y auto incrementado
 *
 * \param
 * \param
 * \return
 *
 */

int controller_AutoId(LinkedList* pArrayListEmployee){
int i;
int IdMax=0;
int len=ll_len(pArrayListEmployee);
Employee* AutoId=employee_new();
for(i=0;i<len;i++){
    AutoId=ll_get(pArrayListEmployee,i);
    if(IdMax<AutoId->id){
        IdMax=AutoId->id;
    }

}
return IdMax+1;
}
