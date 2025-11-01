#include <stdlib.h>
#include <stdio.h>

int main(void)
{
int x=18;
short sx=22;
long lx=35;
float y=10.1567;
printf ("Ciao a tutti\n");
printf("X vale %d, Y vale %f\n",x,y);
printf("X vale %d, Y vale %.2f\n",x,y);

printf ("Size: int %d short %d long %d\n",sizeof(x), sizeof(sx),sizeof(lx) );       // Credo restituisca la dimensione in byte


return 0;
}
