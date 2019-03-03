#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int** pideMatriz(int filas, int columnas);
void imprimeMatriz(int** matriz, int filas, int columnas);
int** checador(int **matriz, int **matriz2, int filas, int columnas);
int VVivas(int **matriz, int filas, int columnas,int i,int j);
int muerenTodas(int **matriz,int filas,int columnas);

int main()
{
    int filas , columnas,dias;
	printf("Numero de filas de la matriz\n");
	scanf("%d",&filas);
	printf("Numero de columnas de la matriz\n");
	scanf("%d",&columnas);
	printf("Numero de días:\n");
	scanf("%d",&dias);
	int **matriz = pideMatriz(filas, columnas);
	int **matriz2= pideMatriz(filas,columnas);
	system("clear");
	for (int i = 0; i < dias; ++i)
	{
		printf("---DIA %d---\n",i+1 );
		imprimeMatriz(matriz, filas, columnas);

		if(muerenTodas(matriz, filas, columnas)){
			i=dias;
			printf("\nYa murieron todas las celulas  :( :(\n");
			exit(-1);
		}	
		printf("\n");
		printf("___________________________________\n");
		matriz=checador(matriz,matriz2,filas,columnas);
		matriz2=pideMatriz(filas,columnas);
		printf("___________________________________\n");	
		
		sleep(2);
	}
	printf("\nYa pasaron %d dias :(\n",dias );
	free(matriz);
	free(matriz2);
	return 0;
}

int muerenTodas(int **matriz,int filas,int columnas)
{
	int i,j;
	int muertas=0;
	for(i=0; i<filas; i++)
	{
		for(j=0; j<columnas; j++)
		{
			if(matriz[i][j]==0){
				muertas++;
			}
		}
	}
	if(muertas==filas*columnas){
		return 1;
	}
	else{
		return 0;
	}
}

int** pideMatriz(int filas, int columnas)
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

int** checador(int **matriz, int **matriz2, int filas, int columnas)
{	
	int i,j;
    for(i = 0; i <filas; i++)
    {
        for(j = 0; j <columnas; j++) 
        {
			matriz2[i][j] = 2;
			if(matriz[i][j]==1 )
			{
				if (VVivas(matriz,filas,columnas,i, j)==2 || VVivas(matriz,filas,columnas,i, j)==3)
				{
					matriz2[i][j]=1;
				}
				else
				{
					matriz2[i][j]=0;
				}
			}   
			else
			{
				if(VVivas(matriz,filas,columnas,i, j)==3)
				{
					matriz2[i][j]=1;
				}
				else 
					matriz2[i][j]=0;
			}  
        }
    }
    return matriz2;
}

int VVivas(int **matriz, int filas, int columnas,int i,int j)
{
    int total = 0;
	int izq,cenx,ceny,der,arr,aba;
	cenx=j;
	ceny=i;
	izq=j-1;
	der=j+1;
	arr=i-1;
	aba=i+1;
	if(i==0 || i==filas-1 || j==0 || j==columnas-1)
	{
		if(i==0)
		{
			arr=0;	
		}
		if(i==filas-1)
		{
			aba=filas-1;
		}
		if(j==0)
		{
			izq=0;
		}
		if(j==columnas-1)
		{
			der=columnas-1;
		}

	}
    for(i = arr; i <= aba; i++)
    {
    	for(j = izq; j <= der; j++)
        {
            	if(cenx==j && ceny ==i){
            						//no suma si esta en la casilla de la casilla que checa
            	}else{
            		total =  total + matriz[i][j];
            	}
        }
    }
	return total;
}

