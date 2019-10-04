#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char getChar(char mensaje[]){
    char valor;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&valor);

return valor;
}
int getInt(char mensaje[]){
int valor;

printf("%s",mensaje);
fflush(stdin);
scanf("%d",&valor);

return valor;
}
float getFloat(char mensaje[]){
float valor;

printf("%s",mensaje);
fflush(stdin);
scanf("%f",&valor);

return valor;
}
void miFgets(char nombre[], int cantidad,char mensaje[]){
    printf("%s",mensaje);
    fflush(stdin);
    fgets(nombre, cantidad-2, stdin);
nombre=strtok(nombre,"\n");
    nombre[cantidad-1] = '\0';
}
