#include <stdio.h>
#include <stdlib.h>
int main (void)
{
int *punt;
punt=(int *)52300;
*punt=35; //attenzione, possibile segmentation fault
return 0;
}
