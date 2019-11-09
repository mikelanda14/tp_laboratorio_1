#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{

        printf("\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)");
        printf("\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)");
        printf("\n3. Alta de empleado");
        printf("\n4. Modificar datos de empleado");
        printf("\n5. Baja de empleado");
        printf("\n6. Listar empleados");
        printf("\n7. Ordenar empleados");
        printf("\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto)");
        printf("\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario)");
        printf("\n10. Salir");
        option= getInt("\nDigite la opcion : ");
    system("cls");
        switch(option)
        {
                case 1:
                if(ll_len(listaEmpleados)==0){
                if(controller_loadFromText("data.csv",listaEmpleados)==1){
                    printf("\ncarga de empleados exitosa\n\n");
                    printf("\n%d\n\n",ll_len(listaEmpleados));
                    }
                    else{
                        printf("\nError en carga\n\n");
                    }}else{printf("\n\nArchivo leido");
                        printf("\n%d\n\n",ll_len(listaEmpleados));}
                break;
                case 2:
                    if(ll_len(listaEmpleados)==0){
                if(controller_loadFromText("data.csv",listaEmpleados)==1){
                    printf("\ncarga de empleados exitosa\n\n");
                    printf("\n%d\n\n",ll_len(listaEmpleados));
                    }
                    else{
                        printf("\nError en carga\n\n");
                    }}else{printf("\n\nArchivo leido");
                        printf("\n%d\n\n",ll_len(listaEmpleados));}

                break;
                case 3:
                    if(ll_len(listaEmpleados)==0){
               // if(controller_loadFromText("data.csv",listaEmpleados)==1){
                    printf("\nDEVE CARGAR El Archivo antes\n\n");
                    printf("\n%d\n\n",ll_len(listaEmpleados));
                    }
                    else{
                        printf("\nLLAMADO A LA FUNCION 3\n\n");
                    printf("\n\nArchivo leido");
                        printf("\n%d\n\n",ll_len(listaEmpleados));}

                break;
                case 4:

                break;
                case 5:

                break;
                case 6:
                    if(listaEmpleados!=NULL){
                            controller_ListEmployee(listaEmpleados);


                    }
                    else{
                        printf("\nError en LISTA\n\n");
                    }

                break;
                case 7:

                break;
                case 8:

                break;
                case 9:

                break;
                default:
                    if(option!=10){
                        printf("Fuera de rango");
                    }
        }
    }while(option != 10);
    return 0;
}
