#include <stdlib.h>
#include <stdio.h>
#define N 5
/*Scrivere un metodo che restituisca tramite i puntatori il massimo
 di un vettore e il numero di elementi in posizione pari
 maggiori di 50*/

void rest_max_num (int vett[],int n,int *punt_max,int *punt_num); 


int main(void)
{
	//const int N=5;
	int vett[N];
	int i,max, num_ris;
	int *punt_max;
	int *punt_num;
	int*punt;
	punt_max=&max;
	punt_num=&num_ris;

	i=0;
	//            100          105
	for (punt=&vett[0];punt<&vett[N];punt++){
		printf ("Inserisci vett[%d]>",i);
		scanf ("%d",punt);
		i=i+1;
	}
	rest_max_num (vett,N,punt_max,punt_num); 
	//void rest_max_num (vett,N,&max, &num_ris );
	printf(" Max=%d Num elem=%d\n", max, num_ris); 
	return 0;
}

void rest_max_num (int vett[],int n,int *punt_max,int *punt_num){
	int i,num_pari=0;
	*punt_max=vett[0];
	for (i=1;i<n;i++)
		if (vett[i]>*punt_max)
			*punt_max=vett[i];
	for (i=0;i<n;i=i+2)
		if (vett[i]>50)
			num_pari++;
	*punt_num=num_pari;
}
