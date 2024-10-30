#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DigitosMax 4//Nuestro programa permitira datos de hasta 3 cifras
void EscribirDatos(int n, char Datos[n][DigitosMax]) {//Mostrar antes de cambiar
    for (int i=0;i<n;i++) {
        printf("Introduce el dato número %d del arreglo (máximo %d cifras): ", i + 1, DigitosMax - 1);
        scanf("%s", Datos[i]);  
    }
}
void intercambiar(char a[],char b[]) {
    char ComparaLuma[DigitosMax];
    strcpy(ComparaLuma, a);
    strcpy(a,b);
    strcpy(b,ComparaLuma);
}
int particionar(char Datos[][DigitosMax], int bajo, int alto) {
    int pivote = atoi(Datos[alto]);//el pivote es el elemento mas "alto"
    int i=(bajo-1); //Usamos la posicion del elemento mas chico
    for (int j=bajo;j<alto; j++) {//pongo el mas bajo para acomodar que va con que
        if (atoi(Datos[j])<=pivote) {//Esto "atoi" cambia el valor de una cadena a un int, nos sirve para que no diga que 100 es menor a 2 por ejemplo
            i++; 
            intercambiar(Datos[i], Datos[j]); //Intercambiar
        }
    }
    intercambiar(Datos[i+1], Datos[alto]); //alto es pivote, se cambia con i{1
    return (i+1); //Este es donde esta el pivote ahora
}
void QuickSort(char Datos[][DigitosMax], int bajo, int alto) {
    if (bajo<alto) {
        int parte = particionar(Datos, bajo, alto);//dividimos en 2 partes nuestro arrglo
        QuickSort(Datos,bajo,parte-1);
        QuickSort(Datos,parte + 1,alto);
    }
}
int main() {
    int n;
    printf("Programa 11 Quick Sort por Emiliano Ruiz y Moreno Vigueras Arturo Tadeo \nIntroduce la cantidad de datos a comparar: ");
    scanf("%d", &n);
    char Datos[n][DigitosMax];
    EscribirDatos(n, Datos);//Se ponen los datos como estaban antes
    printf("Los datos ingresados son: ");
    for (int i=0; i<n;i++) {
        printf("%s ",Datos[i]);
    }
    printf("\n");
    QuickSort(Datos, 0,n-1);// Se hace quicksort
    printf("Los datos ordenados son: ");
    for (int i=0;i<n;i++) {
        printf("%s",Datos[i]);
    }
    printf("\n");
    return 0;
}
