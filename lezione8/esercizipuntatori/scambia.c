#include <stdlib.h>
#include <stdio.h>
void scambia1( float, float);
void scambiarif (float *, float *);
int main(void)
{
float x,y;
printf ("Inserisci x>");
scanf ("%f",&x);
printf ("Inserisci y>");
scanf ("%f", &y);
printf ("X=%.3f Y=%.3f\n",x,y);
scambia1 (x,y);
printf ("nel main per val. X=%.3f Y=%.3f\n",x,y);
scambiarif (&x, &y);
printf ("nel main per rif. X=%.3f Y=%.3f\n",x,y);

return 0;
}
void scambia1(float x, float y)
// passaggio per valore
{
float tmp;
tmp=x;
x=y;
y=tmp;
printf ("nel metodo x=%.3f y=%.3f\n",x,y);

}
void scambiarif (float *puntx, float *punty)
//passaggio per riferimento
{
float tmp;
tmp=*puntx;
*puntx=*punty;
*punty=tmp;
}
