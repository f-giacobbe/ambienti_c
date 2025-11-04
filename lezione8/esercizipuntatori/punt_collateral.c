#include <stdio.h>
#include <stdlib.h>
int main (void)
{
int vett[5];
int x,y,z;
for (int i=0;i<5;i++)
	vett[i]=10;
x=15;y=25;z=35;
printf("Prima x=%d y=%d z=%d\n",x,y,z);
vett[5]=18;
vett[6]=19;
vett[7]=20;
printf("Dopo x=%d y=%d z=%d\n",x,y,z);


return 0;
}
