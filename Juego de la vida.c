#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int pideMatriz(int filas, int columnas);
void imprimeMatriz(int** matriz, int filas, int columnas);


int main(){
    int filas , columnas;
	printf("Numero de filas de la matriz\n");
	scanf("%d",&filas);
	printf("Numero de columnas de la matriz\n");
	scanf("%d",&columnas);
	int **matriz = pideMatriz(filas, columnas);
	imprimeMatriz(matriz, filas, columnas);
	return 0;
}

int pideMatriz(filas, columnas){
	int i, j;
	int **matriz;
	
	matriz = (int **)malloc(filas*sizeof(int*));
	
	for(i=0; i<filas; i++)
	{
		matriz[i] = (int *)malloc(columnas*sizeof(int));
	}
	
	for(i=0; i<filas; i++)
	{
		for(j=0; j<columnas; j++)
		{
			matriz[i][j] = rand() % 2;
		}
	}
	return matriz;
}

void imprimeMatriz(int** matriz, int filas, int columnas){
	int i, j;
	for(i=0; i < filas; i++)
	{
		for(j=0; j<columnas; j++)
		{
			if(matriz[i][j] == 1)
				printf("@ ");
			else
				printf(". ");
		}
		printf("\n");
	}
}
