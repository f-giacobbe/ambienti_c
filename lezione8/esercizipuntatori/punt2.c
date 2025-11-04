#include <stdio.h>
#include <stdlib.h>
int main (void)
{
int x=10;
int *punt1;
int *punt2;
punt1=&x;

int y,z;
printf ("X vale %d, il suo puntatore vale: %p\n",x,punt1);
punt2=punt1;
printf("indirizzo punt1 %p, ind. punt2 %p\n", punt1, punt2);
*punt2=35;
printf ("Dopo X vale %d, il suo puntatore vale: %p\n",x,punt1);


return 0;
}
