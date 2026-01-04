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
typedef enum {false, true} boolean;

void verifica_vet_matrice(int** M, int n, int m, int* V, int dimV, int K, int* colVerifica, int* rigVerifica);
int** create(int n, int m);
void read(int** M, int n, int m);
void print(int** M, int n, int m);

int main() {
    int i, n, m, dimV, K, colVerifica, rigVerifica;
    int* V;
    int** M;
    
    rigVerifica = 0;
    colVerifica = 0;

    /* Popolamento vettore */
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

    printf("Inserisci K:");
    scanf("%d", &K);

    /* Popolamento matrice */
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

    /* Liberazione memoria */
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
    int i, j, k, somma, elemMaggiori;
    float media;
    boolean trovato, tuttiOK;

    for (j = 0; j < m; j++) {
        somma = 0;
        for (i = 0; i < n; i++) {
            somma += M[i][j];
        }
        media = (float)somma/n;

        elemMaggiori = 0;
        for (i = 0; i < n; i++) {
            if (M[i][j] > media) {
                elemMaggiori++;
            }
        }

        if (elemMaggiori >= K) {
            *colVerifica = (*colVerifica) + 1;
        }
    }

    for (i = 0; i < n; i++) {
        tuttiOK = true;

        for (j = 0; j < m; j++) {
            trovato = false;
            for (k = 0; k < dimV; k++) {
                if (M[i][j] == V[k]) {
                    trovato = true;
                    break;
                }
            }

            if (!trovato) {
                tuttiOK = false;
                break;
            }
        }

        if (!tuttiOK) {
            continue;
        }

        for (k = 0; k < dimV; k++) {
            trovato = false;
            for (j = 0; j < m; j++) {
                if (M[i][j] == V[k]) {
                    trovato = true;
                    break;
                }
            }

            if (!trovato) {
                tuttiOK = false;
                break;
            }
        }

        if (tuttiOK) {
            *rigVerifica = (*rigVerifica) + 1;
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

void print(int** M, int n, int m) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("M[%d][%d] = %d\n", i, j, M[i][j]);
        }
    }
}
