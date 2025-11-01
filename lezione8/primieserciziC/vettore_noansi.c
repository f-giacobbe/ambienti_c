#include <stdlib.h>
#include <stdio.h>

int main(void)
{
int x,i;
int n;
printf ("Inserisci n>");
scanf ("%d",&n);


int vett[n];   /* NON rispetta la convenzione ANSI C89 (da C99 in poi si) perché la sua lunghezza è data da una variabile */
for (i=0;i<n;i++)
	vett[i]=i;

for (i=0;i<n;i++)
   printf ("%d\t",vett[i]);
printf("\n");

printf("%p\n", &n);

return 0;
}
