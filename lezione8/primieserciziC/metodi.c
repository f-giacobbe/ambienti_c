#include <stdlib.h>
#include <stdio.h>

int massimo  (int , int);		// I metodi in C vanno dichiarati a priori! (PROTOTIPO del metodo)


int main(void)
{
int x;
int y;
int mymax;
printf("Inserisci x >");
scanf ("%d",&x);
printf("Inserisci  y >");
scanf ("%d",&y);
mymax=massimo(x,y);
printf("Massimo=%d\n",mymax);
return 0;
}


int massimo (int x, int y)
{
if (x>y)
	return x;
else
	return y;
}

