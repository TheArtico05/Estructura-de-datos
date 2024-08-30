#include <stdlib.h>
int Azurill;
int main(){
    printf("Programa de dynamic array por Emiliano Ruiz Garcia y Moreno Vigueras Arturo Tadeo :) \n");
    printf("NUMERO DE CUENTA CON ARREGLOS BIDIMENSIONALES DINAMICOS \n");
    printf("\nPrimero, ingresa tu numero de cuenta por favor (9 dígitos)\n");
    printf("Asegurate de ingresar un numero valido, ten cuidado con insertar numeros negativos u otros caracteres\n");
    int NumCuenta;
    scanf("%d",&NumCuenta);
    int Numerotemporal=NumCuenta;
    int ContaDigitos=0;
    
    while(Numerotemporal>0){
        Numerotemporal/=10;
        ContaDigitos++;
    }
    int **Arreglo2D=(int**)malloc(ContaDigitos*sizeof(int*));
    int Columax=10;
    if(Arreglo2D==NULL){
        printf("Ha ocurrido un error SUPER RARO, asegurate de haber escrito bien los datos\n");
        return -1;
    }
    for (int Azurill=0; Azurill<ContaDigitos;Azurill++){
        Arreglo2D[Azurill]=(int*)malloc(Columax*sizeof(int));//Segundo for para columnas
        for (int Marill=0;Marill<Columax;Marill++) {
            Arreglo2D[Azurill][Marill]=0;
        }
    }
    int filaEmi=0;
    while (NumCuenta>0){
        int Cifrasola=NumCuenta%10;
        if (Cifrasola!=0){
            for(Azurill=0;Azurill<Cifrasola;Azurill++) {//se sacan dígitos con %10
                Arreglo2D[filaEmi][Azurill] = Cifrasola;
            }
            filaEmi++;
        }
        NumCuenta/=10;
    }
    for (Azurill=filaEmi-1;Azurill>=0;Azurill--){
        for (int Marill = 0;Marill<Columax&&Arreglo2D[Azurill][Marill]!=0;Marill++) {//Pongo and para evitar que salgan ceros de la matriz
            printf("{%d}", Arreglo2D[Azurill][Marill]);
        }
        printf("\n");
    }
    for (int Azurill=0;Azurill<ContaDigitos;Azurill++) {
        free(Arreglo2D[Azurill]); // Primero se liberan las columnas para evitar error de memoria (se traba)
    }
    free(Arreglo2D); // Ahora se libera todo
    return 0;
}