#include <stdlib.h>
#include <stdio.h>


// Un modo di definire i booleani in C
#define FALSE 0
#define TRUE 1
#define boolean int



//massimo_negativi che restituisce (in maniera opportuna usando i puntatori), due interi, 
//a)	il massimo di tutta la matrice
//b)	il numero di righe composte tutte da elementi negativi in posizione pari (0,2,4..)


int ** create (int n, int m);
void read (int **mat, int n, int m);
void print (int **mat, int n, int m);
void  massimo_negativi (int **mat, int n, int m, int *max, int *num_neg);

int main(void)
{
	int i,j;
	int n,m;
	int **mat;
	int max, num_neg;
	n=4; m=3;
	mat=create (n,m);
	read (mat,n,m);
	print (mat, n,m);

	massimo_negativi(mat, n, m, &max,&num_neg);
	printf ("Massimo=%d numero righe negative %d\n",max, num_neg);


	return 0;
}
int ** create (int n,int m)
{
	int i;
	int **mat;
	mat =(int **) malloc (n*sizeof(int*));
	if (mat==NULL)
		{printf ("Errore allocazione matrice\n");exit(1);}
	for (i=0;i<n;i++){
		mat[i]=(int *)malloc (m*sizeof(int));
		if (mat[i]==NULL)
			{printf ("Errore allocazione mat[%d]\n",i);exit(1);}
	}
	return mat;
}

void read (int **mat,int n, int m)
{
	int i,j;
	for (i=0;i<n;i++)
		for (j=0;j<m;j++)
		{
		printf ("Inserisci mat[%d][%d]>",i,j);
		scanf ("%d", &mat[i][j]);
		}
		
}
void print (int **mat, int n, int m)
{
	int i,j;
	for (i=0;i<n;i++){
		for (j=0;j<m;j++)
			printf ("%d\t",mat[i][j]);
		printf("\n");
	}
}

void  massimo_negativi (int **mat, int n, int m, int *max, int *num_neg)
{
	int num,i,j;
	boolean tutti_neg;
	*max=mat[0][0];
	for (i=0;i<n;i++)
		for (j=0;j<m;j++)
			if (mat[i][j]>*max)
				*max=mat[i][j];
	// trovare le righe tutte negative
	num=0;
	for (i=0;i<n;i++){
	// per ogni riga verifico i   numeri in posizione pari siano tutti negativi
		tutti_neg=TRUE;
		for (j=0;j<m && tutti_neg;j=j+2)
			if (mat[i][j]>=0)
				tutti_neg=FALSE;
		if (tutti_neg)
			num++;	
	}
	*num_neg=num;
}


