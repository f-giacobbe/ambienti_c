/* Scrivere un programma in C per la gestione di matrici di interi, che contenga i seguenti metodi:
Un metodo verifica_vet_matrice, a cui viene passato fra gli altri parametri anche un vettore V di interi, un intero K e che restituisce (in maniera opportuna usando i puntatori) 2 interi, colKappa e rig100:
il primo (colKappa) corrisponde al numero di colonne che verifichino la seguente proprietà: il numero di elementi pari è maggiore di K (esempio: se K=3, la colonna [10, 5, 7, 8, 6, 13, 12] rispetta la proprietà perché ha 4 elementi pari ). 
il secondo (rig100) è il numero di righe della matrice in cui la somma degli elementi è maggiore di 100 e in cui ci sono almeno tre elementi con valore maggiore di 10. 
Il metodo main che dichiara e alloca la matrice (chiamando il metodo create) e invoca opportunamente i metodi precedenti.
Facoltativi, se rimane tempo i seguenti 3 metodi:
Una funzione create, che riceve due interi (dimensione di righe e colonne), crea una matrice delle dimensioni indicate, e restituisce il suo puntatore.
Un metodo read per la lettura di una matrice da tastiera.
Un metodo print per la stampa della matrice su output. */

#include <stdio.h>
#include <stdlib.h>

void verifica_vet_matrice(int** M, int n, int m, int* V, int dimV, int K, int* colKappa, int* rig100);
int** create(int n, int m);
void read(int** M, int n, int m);
void print(int** M, int n, int m);

int main(void) {
    int i, n, m, dimV, K, colKappa, rig100;
    int* V;
    int** M;

    colKappa = 0;
    rig100 = 0;

    /* Definizione K */
    printf("Inserisci K:");
    scanf("%d", &K);

    /* Definizione vettore V (anche se non lo si utilizza) */
    printf("Inserisci dimensione V:");
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
    printf("Inserisci numero colonne matrice:");
    scanf("%d", &m);
    M = create(n, m);
    read(M, n, m);
    print(M, n, m);

    /* Chiamata al metodo verifica_vet_matrice */
    verifica_vet_matrice(M, n, m, V, dimV, K, &colKappa, &rig100);
    printf("colKappa = %d\nrig100 = %d\n", colKappa, rig100);

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

void verifica_vet_matrice(int** M, int n, int m, int* V, int dimV, int K, int* colKappa, int* rig100) {
    int i, j, numPari, somma, elemMaggiori10;

    /* Calcolo colKappa */
    for (j = 0; j < m; j++) {
        numPari = 0;

        for (i = 0; i < n; i++) {
            if (M[i][j] % 2 == 0) {
                numPari++;
            }
        }

        if (numPari > K) {
            (*colKappa)++;
        }
    }

    /* Calcolo rig100 */
    for (i = 0; i < n; i++) {
        somma = 0;
        elemMaggiori10 = 0;

        for (j = 0; j < m; j++) {
            somma += M[i][j];

            if (M[i][j] > 10) {
                elemMaggiori10++;
            }
        }

        if (somma > 100 && elemMaggiori10 >= 3) {
            (*rig100)++;
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
