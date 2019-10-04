#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"


void menuOpciones(Employee Employe[],int len){
    int opcion=0;
    int marcador;
   while(opcion!=6){
        printf("\n============sistema para administrar su nomina de empleados================\n");
        printf("\n1)Alta\n2)BAJA\n3)Modificacion\n4)Lista \n6)Salir");

        opcion=getInt("\n\nIntrodusca el Numero de la opcion :");

        system("cls");
    switch (opcion){
case 1:
    addEmployee(Employe,len);
    break;
case 2:
    marcador=ifAllEmpty(Employe,len);
    if(marcador==1){
    removeEmployee(Employe,len);
    }else{
    printf("\nNo Existe Registro\n");
    }
    break;
case 3:
    marcador=ifAllEmpty(Employe,len);
    if(marcador==1){
    modEmployees(Employe,len);
    }else{
    printf("\nNo Existe Registro\n");
    }

    break;
case 4:
    marcador=ifAllEmpty(Employe,len);
    if(marcador==1){
    sortEmployees(Employe ,len);
    printEmployees(Employe,len);
    }else{
    printf("\nNo Existe Registro\n");
    }


    break;
 default:
     if(opcion!=6){
printf("\nFUERA DE RANGO\n");
     }
break;
    }

   }


}


int initEmployees(Employee Employe[], int len)
{
    int i;
        for(i=0;i<len;i++)
            {
            Employe[i].isEmpty=1;
            }
        return 0;
}


int addEmployee(Employee Employe[], int len)
{
int i;
   for(i=0; i<len; i++)
    {

        if(Employe[i].isEmpty==1){

        miFgets(Employe[i].name,51,"Name :");
        miFgets(Employe[i].lastName,51,"LastName :");
        Employe[i].salary=getFloat("Introdusca El Salario :");
        Employe[i].id=generarId(Employe,len);
        Employe[i].sector=getInt("Digite el sector del empleado :");

         Employe[i].isEmpty=0;
         system("cls");
            break;}
    }
 return 0;
}

int generarId(Employee Employe[],int len){
    int marcador,i;

    marcador=0;
    for(i=0;i<len;i++){
        if((marcador<Employe[i].id) && (Employe[i].isEmpty==0)){
            marcador=Employe[i].id;
        }
        }
    return marcador+1;
}
int  removeEmployee(Employee Employe[],int len){
        int i,auxBaja;
        char check;
        auxBaja=getInt("Introdusza el Id del empleado a dar de Baja :");
        for(i=0;i<len;i++){
            if(auxBaja==Employe[i].id){

                   check=getChar("\nEsta seguro que desea eliminar el registro\nintrodusca \'s\' para continuar, \'n\'para abandonar :");
                    if(check=='s'||check=='S'){
                Employe[i].isEmpty=1;
                printf("\nbaja exitosa\n");
                break;}
            }
        }return 0;
}

int printEmployees(Employee Employe[], int len)
{
    int i;
    float totalSalarios=0;
    int numeroDeEmployee=0;
    int sobrePromedio=0;
    printf("\n======================Listato=============================\n\tID\tName\tLastname\tSalary\t\tSector\n");
    for(i=0;i<len;i++){
        if(Employe[i].isEmpty==0){


            printf("\n\t%d\t%s",Employe[i].id,Employe[i].name);
            printf("\t%s",Employe[i].lastName);
            printf("\t\t%.2f\t\t%d",Employe[i].salary,Employe[i].sector);
        }

        if(Employe[i].isEmpty==0){
        totalSalarios+=Employe[i].salary;
        numeroDeEmployee++;}
    }
    printf("\n\nTotal de Salarios : %.2f",totalSalarios);
    printf("\nPromedio del Salario de Empleados : %.2f",totalSalarios/numeroDeEmployee);
    for(i=0;i<len;i++){
        if(Employe[i].isEmpty==0&&Employe[i].salary>totalSalarios/numeroDeEmployee){
            sobrePromedio++;
        }
    }
    printf("\nNumero de Empleados sobre el Salario Promedio :%d\n",sobrePromedio);
return 0;
}
int modEmployees(Employee Employe[],int len){
    int i,auxMod,opcioMod=0,flag=0;
    auxMod=getInt("introdusca el Id del empleado a modificar");

    for(i=0;i<len;i++){
        if(auxMod==Employe[i].id){
            flag=1;
            while(opcioMod!=5){
                    system("cls");
            printf("Datos del empleado a modificar");
            printf("\n\t%d\t%s\t%s\t%.2f\t%d\n",Employe[i].id,Employe[i].name,Employe[i].lastName,Employe[i].salary,Employe[i].sector);
            printf("\n1)Name\n2)Lastname\n3)Salary\n4)Sector\n5)Salir de modificar");
              opcioMod=getInt("Digite el dato que Nesecita Modificar");

                switch (opcioMod){
            case 1:
                        miFgets(Employe[i].name,51,"Name :");

                break;
            case 2:
                miFgets(Employe[i].lastName,51,"LastName :");

                break;
            case 3:
                Employe[i].salary=getFloat("Introdusca El Salario :");

            break;
            case 4:

        Employe[i].sector=getInt("Digite el sector del empleado :");
            break;
            default:
                if(opcioMod!=5){
                printf("FUERA DE RANGO");
                }
                break;

                }
            }
        }
        if(flag==0){
        printf("\nno encontro el ID solicitado\n");
    }
    }return 0;
}
int sortEmployees(Employee Employe[], int len)
{
             int i,j,ordeNar;
             Employee aux;
             ordeNar=getInt("Digite \'1\' para ordernar de A-Z o \'0\' para ordenar Z-A");
             if(ordeNar==1){
             for(i=0;i<len-1;i++){
                for(j=i+1;j<len;j++){
                    if(strcmp(Employe[i].lastName,Employe[j].lastName)>0){
                            aux=Employe[i];
                            Employe[i]=Employe[j];
                            Employe[j]=aux;
                        }
                }
             }
             }else if(ordeNar==0){
             for(i=0;i<len-1;i++){
                for(j=i+1;j<len;j++){
                    if(strcmp(Employe[i].lastName,Employe[j].lastName)<0){
                            aux=Employe[i];
                            Employe[i]=Employe[j];
                            Employe[j]=aux;
                        }
                }
             }
             }
return 0;

}
int ifAllEmpty(Employee Employe[],int len){
int i;
int marcador=0;
        for(i=0;i<len;i++){
        if(Employe[i].isEmpty!=1){
            marcador=1;
        break;
        }
    }return marcador;
}
