#include <stdlib.h>
#include <stdio.h>
int main(void)
{
	int i,j;
	int n,m;
	n=4; m=3;
	int *mat;
	mat =(int *) malloc (sizeof (int)*n*m);
	// legge una matrice
	for (i=0;i<n;i++)
		for (j=0;j<m;j++){
			printf("Leggo elem[%d][%d]>",i,j);
			scanf("%d",&mat[i*m+j]);
		}
	// stampa la matrice
	for (i=0;i<n;i++){
		for (j=0;j<m;j++)
			printf ("%d\t",mat[i*m+j]);
		printf("\n");
		}	

	return 0;
}
