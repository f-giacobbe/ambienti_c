#include <stdlib.h>
#include <stdio.h>
int main(void)
{
	int x,i;
	int n;
	int *vett;
	printf ("Inserisci la dimensione>");
	scanf ("%d",&n);
	vett=(int *) malloc (n*sizeof(int));
	if (vett==NULL){
		printf("Errore nell'allocazione della memoria\n");
		exit(1);
	}

	for (i=0;i<n;i++){
		printf ("Inserisci eleme %d >",(i+1));
		scanf ("%d",&vett[i]);
	}

	for (i=0;i<n;i++)
		printf ("%d\t",vett[i]);
	printf("\n");
	

	//..altre operazioni col vettore
	free (vett);  //libera la memoria del vettore che può essere riutilizzata
	//altro codice in cui non serve il vettore
	//vett[2]=12; pericoloso farlo dopo la free non devo più usare vett
	return 0;
}
