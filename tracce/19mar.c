/* Scrivere un programma in C per la gestione di matrici di interi, che contenga i seguenti metodi:
Una funzione create, che riceve due interi (dimensione di righe e colonne), crea una matrice delle dimensioni indicate, e restituisce il suo puntatore.
Un metodo read per la lettura di una matrice da tastiera.
Un metodo print per la stampa della matrice su output.
Un metodo piccolo_vett che riceve una matrice, un vettore e le opportune variabili e restituisce (in maniera opportuna usando i puntatori) 
1) il numero di righe in cui tutti gli elementi sono maggiori di 3 volte i corrispondenti elementi del vettore (si suppone che la dimensione della riga sia uguale a quella del vettore),
2) il numero di colonne in cui la somma della prima metà degli elementi sia maggiore della somma della seconda metà.
Il metodo main che dichiara e alloca la matrice  e invoca opportunamente i metodi precedenti.
NOTA: QUALSIASI SOLUZIONE ALTERNATIVA CHE NON USI I PUNTATORI SARA’ CONSIDERATA ERRATA. */

#include <stdio.h>
#include <stdlib.h>
typedef enum {false, true} boolean;

void piccolo_vett(int** M, int n, int m, int* V, int dimV, int* numRighe, int*numColonne);
int** create(int n, int m);
void read(int** M, int n, int m);
void print(int**M, int n, int m);

int main(void) {
    int i, n, m, dimV, numRighe, numColonne;
    int* V;
    int** M;

    numRighe = 0;
    numColonne = 0;

    /* Definizione vettore */
    printf("Inserisci dimensione vettore:");
    scanf("%d", &dimV);
    V = (int*) malloc(dimV * sizeof(int));
    if (V == NULL) {
        printf("Errore allocazione memoria\n");
        exit(1);
    }
    for (i = 0; i < dimV; i++) {
        printf("Inserisci V[%d]:", i);
        scanf("%d", &V[i]);
    }

    /* Definizione matrice */
    printf("Inserisci numero di righe:");
    scanf("%d", &n);
    printf("Inserisci numero di colonne:");
    scanf("%d", &m);
    M = create(n, m);
    read(M, n, m);
    print(M, n, m);

    /* Chiamata al metodo principale */
    piccolo_vett(M, n, m, V, dimV, &numRighe, &numColonne);
    printf("numRighe = %d\nnumColonne = %d\n", numRighe, numColonne);

    /* Liberazione memoria e terminazione programma */
    free(V);
    V = NULL;
    for (i = 0; i < n; i++) {
        free(M[i]);
        M[i] = NULL;
    }
    free(M);
    M = NULL;

    return 0;
}

void piccolo_vett(int** M, int n, int m, int* V, int dimV, int* numRighe, int*numColonne) {
    int i, j, sommaPrima, sommaSeconda;
    boolean rigaOK;

    /* Controllo se la dimensione della riga è uguale alla dimensione del vettore */
    if (m != dimV) {
        printf("Errore, m diverso da dimV\n");
        exit(2);
    }

    /* Calcolo numRighe */
    for (i = 0; i < n; i++) {
        rigaOK = true;

        for (j = 0; j < m; j++) {
            if (M[i][j] < 3 * V[j]) {
                rigaOK = false;
                break;
            }
        }

        if (rigaOK) {
            (*numRighe)++;
        }
    }

    /* Calcolo numColonne */
    for (j = 0; j < m; j++) {
        sommaPrima = 0;
        sommaSeconda = 0;

        for (i = 0; i < n; i++) {
            if (i < n/2) {
                sommaPrima += M[i][j];
            } else {
                sommaSeconda += M[i][j];
            }
        }

        if (sommaPrima > sommaSeconda) {
            (*numColonne)++;
        }
    }
}

int** create(int n, int m) {
    int i;
    int** M;

    M = (int**) malloc(n * sizeof(int*));
    if (M == NULL) {
        printf("Errore allocazione memoria\n");
        exit(1);
    }
    for (i = 0; i < n; i++) {
        M[i] = (int*) malloc(m * sizeof(int));
        if (M[i] == NULL) {
            printf("Errore allocazione memoria\n");
            exit(1);
        }
    }

    return M;
}

void read(int** M, int n, int m) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("Inserisci M[%d][%d]:", i, j);
            scanf("%d", &M[i][j]);
        }
    }
}

void print(int**M, int n, int m) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("M[%d][%d] = %d\n", i, j, M[i][j]);
        }
    }
}
