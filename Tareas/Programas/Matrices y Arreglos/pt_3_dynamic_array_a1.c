
#include <stdio.h>
#include <stdlib.h>
int Digitofinal;
int construpar;
int riki;
int Heropon;
int main(){
    printf("Programa de dynamic array por Emiliano Ruiz Garcia y Moreno Vigueras Arturo Tadeo :) \n");
    printf("ARREGLO UNIDIMENSIONAL \n");
    int *punto=(int*)malloc(10*sizeof(int));
    if (punto==NULL){
        printf("Ha ocurrido un error SUPER RARO, asegurate de haber escrito bien los datos\n");
        return -1;
    }
    for(construpar=0; construpar<10; construpar++){
        punto[construpar]=(construpar+1 )*2;
    }
    for (riki=9;riki>=0;riki--){
        printf("%d", punto[riki]);
        printf("|"); //raya para separar la lista
    }
    printf("\nEstos son los numeros antes del cambio.\n");

    printf("Ahora, ingresa tu numero de cuenta por favor (9 digitos)\n");
    printf("Asegurate de ingresar un numero valido, ten cuidado con insertar nnmeros negativos u otros caracteres.\n");
    int NumCuenta;
    if (scanf("%d",&NumCuenta)!=1){
        printf("Ocurrio algo raro, si agregaste un valor que no es un numero posiblememte ocurrio este error.\n");//para evitar letras u otras cosas en el programa
        free(punto);
        return -1;
    }
    Digitofinal = NumCuenta%10;
    if(Digitofinal<0){
        printf("Ha ocurrido un error inesperado, asegurate de haber insertado bien tu número de cuenta.\n");
        free(punto);
        return 2;
    }
    punto[Digitofinal]=-1;
    printf("El numero de cuenta ingresado fue %d, por lo que el ultimo digito va a ser %d \n", NumCuenta, Digitofinal);
    printf("Ahora, la posicion del ultimo digito de tu numero de cuenta debe cambiar :))\n");
    for(Heropon=9;Heropon>=0;Heropon--) {
        printf("%d",punto[Heropon]);
        printf("|");
    }
    printf("\n");
    free(punto);
    return 0;
}
