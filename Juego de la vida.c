#include <stdio.h>
#include <time.h>


void pideMatriz(int filas, int columnas);
void imprimeMatriz(int** matriz, int filas, int columnas);


int main(){
	int **matriz = generarMatrizAleatoria(5, 5);
	
	mostrarMatriz(matriz, 5, 5);
	
	return 0;
		
}

void pideMatriz(filas, columnas){
	int i, j;
	int **matriz;
	
	matriz = (int **)malloc(filas*sizeof(int*));
	
	for(i = 0; i < filas; i++){
		matriz[i] = (int *)malloc(columnas*sizeof(int));
	}
	
	for(i = 0; i < filas; i++){
		for(j = 0; j < columnas; j++){
			matriz[i][j] = rand() % 2;
		}
	}
	
	return matriz;
}

void imprimeMatriz(int** matriz, int filas, int columnas){
	int i, j;
	
	for(i = 0; i < filas; i++) {
		for(j = 0; j < columnas; j++) {
			if(matriz[i][j] == 1)
				printf("@ ");
			else
				printf(". ");
		}
		printf("\n");
	}
}

