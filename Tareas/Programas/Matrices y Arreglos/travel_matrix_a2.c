#include <stdio.h>
#include <stdlib.h>
#define f 6
#define c 6

void imprimirMatriz(int matriz[f][c], int i, int j) 
{
	int x;
	int y;
    for (x=0;x<f;x++) 
	{
        for (y=0;y<c;y++) {
            if (x==0||x==f-1||y==c-x-1) 
			{
                if (x<i||(x==i&&y<=j)) 
				{
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
	int j;
	int i;
    int matriz[f][c] = 
    {
        {1, 2, 3, 4, 5, 6},
        {7, 8, 9, 10, 11, 12},
        {13, 14, 15, 16, 17, 18},
        {19, 20, 21, 22, 23, 24},
        {25, 26, 27, 28, 29, 30},
        {31, 32, 33, 34, 35, 36}
    };


    for (j=0;j<c;j++) 
	{
		system("cls");
        imprimirMatriz(matriz,0,j); 
        getchar();
    }

    for (i=1;i<f-1;i++) 
	{
		system("cls");
        imprimirMatriz(matriz,i,c-i-1);
        getchar(); 
    }
    for (j=0;j<c;j++) 
	{
		system("cls");
        imprimirMatriz(matriz,f-1,j); 
        getchar(); 
    }
    printf("Presiona Enter para salir...");
    getchar();
    return 0;
}

