#include <stdio.h>
#include <stdlib.h>
int main (void)
{
int x=10;
int *punt;
punt=&x;
int y,z;
printf ("X vale %d, il suo puntatore vale: %p\n",x,punt);
y=*punt;
printf ("y vale %d\n",y);
z=punt; //errore segnalato da un warning (non è detto che la dimensione del puntatore sia int)
printf ("dimensione di un punt %d dim. intero %d\n",sizeof(punt),sizeof(int));
                                                        //8             4
return 0;
}
