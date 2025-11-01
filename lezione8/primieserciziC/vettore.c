#include <stdlib.h>
#include <stdio.h>

#define N 5		/* Definizione di una costante */

int main(void)
{
int x,i;

int vett[N];	/* Rispetta le convenzioni ANSI C perché ha come lunghezza una costante */
for (i=0;i<N;i++){
	printf ("Inserisci eleme %d >",(i+1));
	scanf ("%d",&vett[i]);
}

for (i=0;i<N;i++)
   printf ("%d\t",vett[i]);
printf("\n");


return 0;
}
