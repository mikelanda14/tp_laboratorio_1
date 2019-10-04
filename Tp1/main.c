#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"
int main()
{
    int x=0,y=0,opcion=0,flagA=0,flagB=0,flagC=0;
    int resS,resR,resM,resFx,resFy;
    float resD;


    while(opcion!=5)
    {

        system("cls");
        printf("=====================MENU===============\n1. Ingresar 1er operando A=%d\n2. Ingresar 2do operando B=%d\n3. Calcular todas las operaciones\n4. Informar resultados\n5. Salir\n",x,y);

        if(opcion==3&&flagC==1&&flagA==1&&flagB==1)
        {
            printf("\nCalculos Completados.");

        }
        if(opcion==3&&(flagA==0||flagB==0))
        {
            printf("\nERROR Los  calculos Requieren operandos A y B  :\n");
        }
        if(opcion==4&&(flagA==0||flagB==0))
        {
            printf("\nERROR Los calculos Requieren operandos A , B \n");
        }
        if(opcion==4&&flagC==0)
        {
            printf("\nERROR Es nesesario realizar los calculos antes.\n");
        }
        if(opcion<0 || opcion>5)
        {
            printf("\nERROR Opcion no disponible\n");
        }
        printf("\nIngrese opcion:");
        scanf("%d",&opcion);
        switch (opcion)
        {
        case 1:
            printf("\nintrodusca el primer operando :");
            scanf("%d",&x);
            flagA=1;
            break;
        case 2:
            printf("\nintrodusca el segundo operando :");
            scanf("%d",&y);
            flagB=1;
            break;
        case 3:
            if(flagA==1&&flagB==1)
            {
                resS=suma(x,y);
                resR=resta(x,y);
                resM=multiplica(x,y);
                if(y!=0)
                {
                    resD=division(x,y);
                }
                resFx=facto(x);
                resFy=facto(y);
                flagC=1;
            }
            break;
        case 4:
            if(flagA==1&&flagB==1&&flagC==1)
            {
                system("cls");
                printf("El 1er operando (A=%d)\nEl 2do operando (B=%d)\n======================================",x,y);
                printf("\nEl resultado de A+B es:  %d",resS);
                printf("\nEl resultado de A-B es:  %d",resR);
                printf("\nEl resultado de A*B es:  %d",resM);
                if(y==0)
                {
                    printf("\nNo es posible dividir por cero");
                }
                else
                {
                    printf("\nEl resultado de A/B es: %.2f",resD);
                }
                printf("\nEl factorial de A es: %d y El factorial de B es: %d\n",resFx,resFy);
                flagA=0,flagB=0,x=0,y=0,resS=0,resR=0,resM=0,resFx=0,resFy=0,resD=0;
                printf("\n\nPresione   numero 1 para volver al inicio.\n\nPresione 5 para Salir :");
                scanf("%d",&opcion);
                if(opcion==5){
                    break;
                }
            }

            break;
        }

    }
    system("cls");
    return 0;
}
