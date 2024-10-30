#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DigitosMax 4 //Nuestro programa permitira datos de hasta 3 cifras
void EscribirDatos(int n, char Datos[n][DigitosMax]) { //Mostrar antes de cambiar
    for (int i = 0; i < n; i++) {
        printf("Introduce el dato número %d del arreglo (máximo %d cifras): ", i + 1, DigitosMax - 1);
        scanf("%s", Datos[i]);
    }
}
void InsertSort(int n,char Datos[n][DigitosMax]) {//funcion principal
    for (int i=1;i<n;i++) {
        int j=i;
        while (j>0 && atoi(Datos[j-1]) > atoi(Datos[j])) {//error sk no hay and, con otro whiñe los hace 1 por 1
            char ComparaLuma[DigitosMax];
            strcpy(ComparaLuma,Datos[j]);
            strcpy(Datos[j],Datos[j-1]);
            strcpy(Datos[j-1], ComparaLuma);//lo mismo de intercambio que en Quic Sort
            j=j-1;
        }
    }
}
int main() {
    int n;
    printf("Programa 12: Insert Sort por Emiliano Ruiz y Moreno Vigueras Arturo Tadeo\n");
    printf("Introduce la cantidad de datos a comparar: ");
    scanf("%d", &n);
    char Datos[n][DigitosMax];
    EscribirDatos(n, Datos); //Se ponen los datos como estaban antes
    printf("Los datos ingresados son: ");
    for (int i=0;i< n;i++) {
        printf("%s",Datos[i]);
    }
    printf("\n");
    // Ahora se hace InsertSort
    InsertSort(n,Datos);
    printf("Los datos ordenados son: ");
    for (int i=0; i<n;i++) {
        printf("%s ",Datos[i]);
    }
    printf("\n");
    return 0;
}
