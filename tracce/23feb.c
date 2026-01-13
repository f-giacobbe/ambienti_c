/* Scrivere un programma in C per la gestione di matrici di interi, che contenga i seguenti metodi:
Un metodo verifica_vet_matrice, a cui viene passato fra gli altri parametri anche un vettore V di interi, un intero K e che restituisce (in maniera opportuna usando i puntatori) 2 interi, colVerifica e rigVerifica:
il primo (colVerifica) corrisponde al numero di colonne che verifichino la seguente proprietà: tutti gli elementi in posizione dispari nella colonna sono contenuti vettore V.
il secondo (rigVerifica) è il numero di righe della matrice in cui la somma degli elementi minori di 100 è minore del massimo di tutta la matrice. 
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

int main(void) {
    int i, n, m, dimV, K, colVerifica, rigVerifica;
    int* V;
    int** M;

    colVerifica = 0;
    rigVerifica = 0;

    /* Definizione K (anche se non viene utilizzato) */
    printf("Inserisci K:");
    scanf("%d", &K);

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
    printf("Inserisci numero righe matrice:");
    scanf("%d", &n);
    printf("Inserisic numero colonne matrice:");
    scanf("%d", &m);
    M = create(n, m);
    read(M, n, m);
    print(M, n, m);

    /* Chiamata al metodo verifica_vet_matrice */
    verifica_vet_matrice(M, n, m, V, dimV, K, &colVerifica, &rigVerifica);
    printf("colVerifica = %d\nrigVerifica = %d\n", colVerifica, rigVerifica);

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

void verifica_vet_matrice(int** M, int n, int m, int* V, int dimV, int K, int* colVerifica, int* rigVerifica) {
    int i, j, k, sommaElemMin100, maxMatrice;
    boolean colOK, elemContenuto;

    /* Calcolo maxMatrice (serve per rigVerifica) */
    maxMatrice = M[0][0];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (M[i][j] > maxMatrice) {
                maxMatrice = M[i][j];
            }
        }
    }

    /* Calcolo colVerifica */
    for (j = 0; j < m; j++) {
        colOK = true;

        /* Si presume che con "posizione dispari", si intenda con indice dispari (i = 1, 3, ...) */
        for (i = 1; i < n; i += 2) {
            elemContenuto = false;

            for (k = 0; k < dimV; k++) {
                if (V[k] == M[i][j]) {
                    elemContenuto = true;
                    break;
                }
            }

            if (!elemContenuto) {
                colOK = false;
                break;
            }
        }

        if (colOK) {
            (*colVerifica)++;
        }
    }

    /* Calcolo rigVerifica */
    for (i = 0; i < n; i++) {
        sommaElemMin100 = 0;

        for (j = 0; j < m; j++) {
            if (M[i][j] < 100) {
                sommaElemMin100 += M[i][j];
            }
        }

        if (sommaElemMin100 < maxMatrice) {
            (*rigVerifica)++;
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
