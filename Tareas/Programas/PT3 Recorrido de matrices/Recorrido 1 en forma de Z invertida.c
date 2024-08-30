#include <stdio.h>
#include <stdlib.h> 
#define F 6
#define C 6
int x;
int y;
int j;
int i;
void imprimirMatriz(int matriz[F][C], int fila, int col) 
{
    for (x = 0; x < F; ++x) {
        for (y = 0; y < C; ++y) {
            if (x == 0 || x == F - 1 || y == C - x - 1) {
                if (x > fila || (x == fila && y >= col)) {
                    printf("%2d ", matriz[x][y]); 
                } else {
                    printf("   "); 
                }
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
}

int main() 
{
    int matriz[F][C] = 
    {
        {1, 2, 3, 4, 5, 6},
        {7, 8, 9, 10, 11, 12},
        {13, 14, 15, 16, 17, 18},
        {19, 20, 21, 22, 23, 24},
        {25, 26, 27, 28, 29, 30},
        {31, 32, 33, 34, 35, 36}
    };
//Aqui estaba el problema con que desaparecieran en vez de aparecer
    for (j = C - 1; j >= 0; --j) 
    {
        system("cls");
        imprimirMatriz(matriz, F - 1, j); 
        getchar();
    }

    for (i=F-2;i>0;--i) 
    {
        system("cls");
        imprimirMatriz(matriz, i, C - i - 1);
        getchar(); 
    }
    for (j = C-1;j>=0; --j) 
    {
        system("cls");
        imprimirMatriz(matriz, 0, j); 
        getchar(); 
    }

    printf("Presiona Enter para salir...");
    getchar();
    return 0;
}
