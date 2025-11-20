//Un metodo verifica_vet_matrice, a cui viene passato fra gli altri parametri anche un vettore V di interi, un intero K e che restituisce (in maniera opportuna usando i puntatori) 2 interi, rigOrdinate e colVettore:
//il primo (rigOrdinate) corrisponde al numero di righe che verifichino la seguente proprietà: tutti i numeri che fanno parte della riga sono ordinati (esempio: 3 5 8 12 15 15 18) e minori di K. 
//il secondo (colVettore) è il numero di colonne della matrice in cui la somma degli elementi è minore del prodotto di tutti gli elementi del vettore. 



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef enum {false, true} bool;



int ** create (int n, int m);
void erase (int **mat, int n, int m);
void read (int **mat, int n, int m);
void stampa (int **mat, int n, int m);
void verifica_vet_matrice (int **mat, int n, int m, int *vet, int dimV, int k, int *rigOrd, int *colVett);

int main()
{
	int i,j,n,m, rigOrd,colVett;  /* Dichiarazione variabili prima di tutto */
	int **mat;
	int vet[]={10,2,3,5};
	int dimV=4; int k=5;
	printf ("Inserisci n>");
	scanf ("%d",&n);
	printf ("Inserisci m>");
	scanf ("%d",&m);
	mat=create(n,m);
	erase (mat,n,m);
	stampa (mat,n,m);
	read (mat,n,m);
	stampa(mat,n,m);
	verifica_vet_matrice (mat, n, m, vet, dimV, k, &rigOrd, &colVett);


	printf ("Le righe che verificano sono: %d; le colonne sono: %d\n",rigOrd,colVett);
	return 0;
}




void verifica_vet_matrice (int **mat, int n, int m, int *vet, int dimV, int k, int *rigOrd, int *colVett)
{ 
	*rigOrd=0; *colVett=0; int i,j, z; int prodVettore;
	bool bool_righeOrd;
	for (i=0;i<n;i++){
		bool_righeOrd=true;
		for (j=0;j<m-1&& bool_righeOrd;j++)
			if (mat[i][j]>=mat[i][j+1]|| mat[i][j]>=k)
				bool_righeOrd=false;	
		if (mat[i][m-1]>=k)
			bool_righeOrd=false;
		if (bool_righeOrd)
			*rigOrd=*rigOrd+1;
	} // for i

	prodVettore=1;
	for (z=0;z<dimV;z++)
			prodVettore*=vet[z];

	for (j=0;j<m;j++){
		int somma=0;
		for (i=0;i<n;i++)
			somma+=mat[i][j];
		if (somma < prodVettore)
			*colVett=*colVett+1;
	} // fine for j 		
}





int ** create(int n, int m){
	int **matr;int i;
	matr=(int **) malloc(n*sizeof(int *));
	if (matr==NULL){printf("Err. alloc.\n"); exit(1);}
	for (i=0;i<n;i++)
		matr[i]=(int *) malloc(m*sizeof(int));
	return matr;
}





void erase (int **mat,int n,int m)
{
	int i,j;
	for (i=0;i<n;i++)
		for (j=0;j<m;j++)
			mat[i][j]=0;
}




void stampa(int **mat,int n,int m)
{
	int i,j;
	for (i=0;i<n;i++){
		for (j=0;j<m;j++)
			printf("%d\t",mat[i][j]);
		printf("\n");
	}
}




void read( int **mat, int n, int m)
{
	int i,j;
	for (i=0;i<n;i++)
		for (j=0;j<m;j++){
		printf ("Inserisci elem [%d][%d]>",i,j);
		scanf ("%d",&mat[i][j]);
		}

}
