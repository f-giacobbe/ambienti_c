#include <stdlib.h>
#include <stdio.h>
int main(void)
{
	int i,j;
	int n,m;
	n=4; m=3;
	int **mat;
	mat =(int **) malloc (sizeof (int *)*n);
	if (mat==NULL){
		printf("errore allocazione mat\n"); exit(1);	}
	for (i=0;i<n;i++){
		mat[i]=(int *) malloc (m*sizeof(int));
		if (mat[i]==NULL){
			printf("errore allocazione mat[%d]\n",i); exit(1);	}
	}
	// legge una matrice
	for (i=0;i<n;i++)
		for (j=0;j<m;j++){
			printf("Leggo elem[%d][%d]>",i,j);
			scanf("%d",&mat[i][j]);
		}
	// stampa la matrice
	for (i=0;i<n;i++){
		for (j=0;j<m;j++)
			printf ("%d\t",mat[i][j]);
		printf("\n");
		}	

	// non serve più e libero la matrice
	for (i=0;i<n;i++)
		free (mat[i]);
	free (mat);


	return 0;
}
