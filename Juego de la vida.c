#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int** pideMatriz(int filas, int columnas);
void imprimeMatriz(int** matriz, int filas, int columnas);
void checador(int **matriz, int **matriz2, int filas, int columnas);
int vecinasVivas(int** matriz, int, int);


int main()
{
    int filas , columnas;
	printf("Numero de filas de la matriz\n");
	scanf("%d",&filas);
	printf("Numero de columnas de la matriz\n");
	scanf("%d",&columnas);
	int **matriz = pideMatriz(filas, columnas);
	int **matriz2= pideMatriz(filas,columnas);
	imprimeMatriz(matriz, filas, columnas);
	free(matriz);
	return 0;
}

int** pideMatriz(filas, columnas)
{
	int i, j;
	int **matriz;

	srand(time(NULL));
	//regresa un arreglo de n elementos, cada elemento es un apuntador
	matriz = (int **)malloc(filas*sizeof(int*)); 
	//crea la matriz, hace un arreglo para cada elemento del arreglo inicial
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
void checador(int **matriz, int **matriz2, int filas, int columnas)
{	
	int i,j;
    for(i = 0; i <filas; i++)
    {
        for(j = 0; j <columnas; j++)
        {
            if(matriz[i][j] == ". " && VVivas(matriz,i, j) == 3)
            {
                matriz2[i][j] = "@ ";
            }
            else if(matriz[i][j] == "@ " && (VVivas(matriz,i, j) == 3 || VVivas(** matriz,i,j)==2))
            {
                matriz2[i][j] = "@ ";
            }
            else
            {
                matriz2[i][j] = ". ";
            }
        }
    }
}

int VVivas(int **matriz, int filas, int columnas)
{
    int total = 0;
	int i,j;
    for(i = filas - 1; i <= filas + 1; i++)
    {
    	for(j = columnas - 1; j <= columnas + 1; j++)
        {
        	if (i >= 0 && j >= 0 && i < filas && j < columnas)
            {
            	total += matriz[i][j];
            }
        }
    }
	return total - matriz[filas][columnas];
}
