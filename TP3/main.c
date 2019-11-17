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
    int respuesta;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{

        printf("\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)");
        printf("\n2. Cargar los datos de los empleados desde el archivo data.bin (modo binario)");
        printf("\n3. Alta de empleado");
        printf("\n4. Modificar datos de empleado");
        printf("\n5. Baja de empleado");
        printf("\n6. Listar empleados");
        printf("\n7. Ordenar empleados");
        printf("\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto)");
        printf("\n9. Guardar los datos de los empleados en el archivo data.bin (modo binario)");
        printf("\n10. Salir");
         getInt(&option,"\nDigite la opcion : ","Error Opcion invalida",1,10);

    system("cls");
        switch(option)
        {
                case 1:
                if(ll_len(listaEmpleados)==0){
                if(controller_loadFromText("data.csv",listaEmpleados)==1){
                    printf("\ncarga de empleados exitosa modo TEXTO\n\n");

                    }
                    else{
                        printf("\nError en carga\n\n");
                    }}else{printf("\n\nArchivo previamete cargado\n");

                        }
                break;
                case 2:
                    if(ll_len(listaEmpleados)==0){

                if(controller_loadFromBinary("data.bin",listaEmpleados)==1){
                    printf("\ncarga de empleados exitosa Modo BINARIO\n\n");

                    }
                    else{
                        printf("\nError en carga\n\n");
                    }}else{printf("\n\nArchivo previamete cargado\n");
                        }

                break;
                case 3:
                    if(ll_len(listaEmpleados)!=0){
              respuesta=controller_addEmployee(listaEmpleados);
                   if(respuesta==1){
                   printf("\nEmpleado Cargado en lista\n\n");

                    }else{ printf("\nError En carga de datos.\n\n");}
                    }
                    else{
                        printf("\nLLAMADO A LA FUNCION 3\n\n");

                    printf("\n\nArchivo leido");
                        printf("\n%d\n\n",ll_len(listaEmpleados));}

                break;
                case 4:
                      if(ll_len(listaEmpleados)!=0){

                    respuesta=controller_editEmployee(listaEmpleados);

                    }
                    else{
                      printf("\nDEVE CARGAR El Archivo antes\n\n");

                       }

                break;
                case 5:
                    if(ll_len(listaEmpleados)!=0){
                        respuesta=controller_removeEmployee(listaEmpleados);

                        }
                        else{printf("\nDEVE CARGAR El Archivo antes\n\n");}
                break;
                case 6:
                    if(ll_len(listaEmpleados)!=0){
                            respuesta=controller_ListEmployee(listaEmpleados);
                            if(respuesta!=1){
                                printf("\nError Lista cargada incmopleta\n");
                            }
                    }
                    else{
                        printf("\nError No Se an Cargado los datos\n\n");
                    }

                break;
                case 7:
                    if(ll_len(listaEmpleados)!=0){
                        controller_sortEmployee(listaEmpleados);

                        }
                        else{printf("\nDEVE CARGAR El Archivo antes\n\n");}

                break;
                case 8:
                    if(ll_len(listaEmpleados)!=0){
                     respuesta=controller_saveAsText("data.csv" , listaEmpleados);
                        if(respuesta==1){
                            printf("\nLista Guardada Exitosamente en modo TEXTO\n");
                        }
                    }else{
                    printf("No hay datos para escritura");
                    }
                break;
                case 9:
                    if(ll_len(listaEmpleados)!=0){

                        respuesta=controller_saveAsBinary( "data.bin" ,listaEmpleados);
                        if(respuesta==1){
                            printf("\nLista Guardada Exitosamente en modo BINARIO\n");
                        }
                    }else{
                    printf("No hay datos para escritura");
                    }

                break;
                default:
                    if(option!=10){
                        printf("Fuera de rango");
                    }
        }
    }while(option != 10);
    ll_deleteLinkedList(listaEmpleados);
    return 0;
}
