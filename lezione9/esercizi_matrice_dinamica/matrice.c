#include <stdlib.h>
#include <stdio.h>
#define N 4
#define M 3
int main(void)
{
	int i,j;
	int mat[N][M];
	// legge una matrice
	for (i=0;i<N;i++)
		for (j=0;j<M;j++){
			printf("Leggo elem[%d][%d]>",i,j);
			scanf("%d",&mat[i][j]);
		}
	// stampa la matrice
	for (i=0;i<N;i++){
		for (j=0;j<M;j++)
			printf ("%d\t",mat[i][j]);
		printf("\n");
		}	

	return 0;
}
