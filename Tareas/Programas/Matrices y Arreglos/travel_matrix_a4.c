#include<stdio.h>
#include<stdlib.h>
#define f 3
#define c 4

int Imprimirmatriz(int matriz[f][c],int i,int j)
{
	system("cls");
	int x;
	int y;
	for (x=0;x<f;x++) 
	{
        for (y=0;y<c;y++) 
		{
            if (x<i||(x==i&&y>=j)) 
			{
                printf("%2d ", matriz[x][y]);
            } 
			else 
			{
                printf("   "); 
            }
        }
        printf("\n");
    }
    return 0;
}
int main() 
{
    int matriz[f][c] = 
    {
        {10, 11, 12, 13},
        {20, 21, 22, 23},
        {30, 31, 32, 33}
    };
	int i;
	int j;
    for (i=0;i<f;i++) {
        for (j=c-1;j>=0;j--) {
            Imprimirmatriz(matriz, i, j);
            getchar();
        }
    }
    return 0;
}
