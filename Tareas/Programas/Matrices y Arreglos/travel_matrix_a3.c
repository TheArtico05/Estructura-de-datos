
#include <stdio.h>
#include <stdlib.h>
#define filas 6
#define columnas 4 
int contadorh;
int contadorv;
int opcion;
void EmiMatriz(int EmiMat[filas][columnas], int fila, int columna){
  for(contadorh=0;contadorh<fila;contadorh++){
    if (contadorh%2==0){
      //Izquierda a derecha
      for (contadorv=0; contadorv<columna;contadorv++){
        printf("%d ", EmiMat[contadorh][contadorv]);
      }
    }
		//derecha a izquierda
    else{
      for (contadorv = columna - 1; contadorv >=0; contadorv--){
      printf("%d ", EmiMat[contadorh][contadorv]);
    }
  }
  printf("\n");
  }
}

int main(){
  int Emimat1[filas][columnas]= {
    	{1, 2, 3, 4},
    	{5, 6, 7, 8},
    	{9, 10, 11, 12},
    	{13, 14, 15, 16}, 
    	{17, 18, 19, 20},
   		{21,22, 23, 24},
    };
  printf("Tarea 3 Recorrido de Matrices, por Ruiz Garcia Emiliano y Moreno Vigueras Arturo Tadeo");
  printf("Escribe 1 para iniciar el programa\n");
  scanf("%d", &opcion);
  if (opcion == 1){
       
    EmiMatriz(Emimat1, filas, columnas);  
    printf("Espero haya salido bien ;))");   
  }

  return 0;
}
