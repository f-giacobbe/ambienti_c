/* Scrivere un programma in C per la gestione di matrici di interi, che contenga i seguenti metodi:
Un metodo verifica_vet_matrice, a cui viene passato fra gli altri parametri anche un vettore V di interi, un intero K e che restituisce (in maniera opportuna usando i puntatori) 2 interi, colVerifica e rigVerifica:
il primo (colVerifica) corrisponde al numero di colonne che verifichino la seguente proprietà: ci sono almeno K elementi della colonna maggiori della media della colonna stessa. 
il secondo (rigVerifica) sono il numero di righe che verificano la seguente proprietà: tutti gli elementi della riga sono contenuti nel vettore e tutti gli elementi del vettore sono contenuti nella riga (anche in posizione diversa).
Il metodo main che dichiara e alloca la matrice (chiamando il metodo create) e invoca opportunamente i metodi precedenti.
Facoltativi, se rimane tempo i seguenti 3 metodi:
Una funzione create, che riceve due interi (dimensione di righe e colonne), crea una matrice delle dimensioni indicate, e restituisce il suo puntatore.
Un metodo read per la lettura di una matrice da tastiera.
Un metodo print per la stampa della matrice su output. */

#include <stdio.h>
#include <stdlib.h>
typedef enum {false, true} bool;

void verifica_vet_matrice(int** M, int n, int m, int* V, int dimV, int K, int* colVerifica, int* rigVerifica);
int** create(int n, int m);
void read(int** M, int n, int m);
void print(int** M, int n, int m);

int main() {
    int n, m, dimV, K, colVerifica, rigVerifica, i;
    colVerifica = 0;
    rigVerifica = 0;
    int* V;
    int** M;

    printf("Inserisci valore di K:");
    scanf("%d", &K);

    /* Istanziazione e popolamento vettore */
    printf("Inserisci dimensione vettore:");
    scanf("%d", &dimV);
    V = (int *) malloc(dimV * sizeof(int));
    if (V == NULL) {
        printf("Errore allocazione memoria");
        exit(1);
    }
    for (i = 0; i < dimV; i++) {
        printf("Inserisci V[%d]", i);
        scanf("%d", &V[i]);
    }

    /* Istanziazione e popolamento matrice */
    printf("Inserisci n:");
    scanf("%d", &n);
    printf("Inserisci m:");
    scanf("%d", &m);
    M = create(n, m);
    read(M, n, m);
    print(M, n, m);

    /* Chiamata al metodo e terminazione programma */
    verifica_vet_matrice(M, n, m, V, dimV, K, &colVerifica, &rigVerifica);
    printf("colVerifica = %d\n", colVerifica);
    printf("rigVerifica = %d\n", rigVerifica);

    /* Libero memoria allocata col malloc */
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

void verifica_vet_matrice(int** M, int n, int m, int* V, int dimV, int K, int* colVerifica, int* rigVerifica) {
    int i, j, k, somma, elemOK;
    float media;
    bool rigaOK, elemInV, elemInRiga;

    /* Calcolo colVerifica */
    for (j = 0; j < m; j++) {
        somma = 0;

        /* Calcolo media */
        for (i = 0; i < n; i++) {
            somma += M[i][j];
        }
        media = (float)somma / n;

        elemOK = 0;
        for (i = 0; i < n; i++) {
            if (M[i][j] > media) {
                elemOK++;
            }

            if (elemOK >= K) {
                break;
            }
        }

        if (elemOK >= K) {
            *colVerifica = *colVerifica + 1;
        }
    }

    /* Calcolo rigVerifica */
    for (i = 0; i < n; i++) {
        rigaOK = true;

        /* Verifico se tutti gli elementi della riga sono contenuti nel vettore */
        for (j = 0; j < m; j++) {
            elemInV = false;
            for (k = 0; k < dimV; k++) {
                if (M[i][j] == V[k]) {
                    elemInV = true;
                    break;
                }
            }

            if (!elemInV) {
                rigaOK = false;
                break;
            }
        }

        if (!rigaOK) {
            continue;
        }

        /* Verifico se ogni elemento del vettore è contenuto nella riga */
        for (k = 0; k < dimV; k++) {
            elemInRiga = false;
            for (j = 0; j < m; j++) {
                if (V[k] == M[i][j]) {
                    elemInRiga = true;
                    break;
                }
            }

            if (!elemInRiga) {
                rigaOK = false;
                break;
            }
        }

        if (rigaOK) {
            *rigVerifica = *rigVerifica + 1;
        }
    }
}

int** create(int n, int m) {
    int i;
    int** M;

    M = (int**) malloc(n * sizeof(int*));
    if (M == NULL) {
        printf("Errore allocazione memoria");
        exit(1);
    }
    for (i = 0; i < n; i++) {
        M[i] = (int*) malloc(m * sizeof(int));
        if (M[i] == NULL) {
            printf("Errore allocazione memoria");
            exit(1);
        }
    }

    return M;
}

void read(int** M, int n, int m) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("Inserisci M[%d][%d]", i, j);
            scanf("%d", &M[i][j]);
        }
    }
}

void print(int** M, int n, int m) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("M[%d][%d] = %d", i, j, M[i][j]);
        }
    }
}