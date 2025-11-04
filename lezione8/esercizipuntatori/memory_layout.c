#include <stdio.h>
#include <stdlib.h>

// Global variable
int gvar = 66;

// Constant global variable
const int cgvar = 1010;

// uninitialized global variable
int ugvar;

void foo() {
    
    // Local variable
    int lvar = 1;
    printf("Address of function lvar:\t%p\n", (void*)&lvar);    /* Il casting a void* serve per rispettare lo standard di C, altrimenti si rischiano warning (nulla di che) */
}

int main() {
    
    // Heap variable
    int *hvar = (int*)malloc(sizeof(int));      /* Il casting a int* serve a rendere il codice compatibile con C++ perché malloc restituisce un void* */
    int mainvar=18;    
    
    // Checking and comparing address of different
    // elements of program that should be stored in
    // different segements of the memory
    printf("Address of code  foo:\t\t%p\n", (void*)&foo);
    printf("Address of code main:\t\t%p\n", (void*)&main);
    printf("Address of const. cgvar:\t%p\n", (void*)&cgvar);
    printf("Address of global  gvar:\t%p\n", (void*)&gvar);
    printf("Address of not init. ugvar:\t%p\n", (void*)&ugvar);
    printf("Address of mainvar:\t\t%p\n", (void*)&mainvar);
    printf("Address of stack hvar:\t%p\n", (void*)hvar);
    foo();
    
        return 0;
}
