/* Scrivere un programma in C per la gestione di matrici di interi, che contenga i seguenti metodi:
Una funzione create, che riceve due interi (dimensione di righe e colonne), crea una matrice delle dimensioni indicate, e restituisce il suo puntatore.
Un metodo read per la lettura di una matrice da tastiera.
Un metodo print per la stampa della matrice su output.
Un metodo verifica_vet_matrice, a cui viene passato fra gli altri parametri anche un vettore V di interi, e che restituisce (in maniera opportuna usando i puntatori) 2 interi, matVerPos e vetVerNeg:
il primo (matVerPos) corrisponde al numero di colonne che verifichino la seguente proprietà: il numero di elementi positivi in posizione pari della colonna è maggiore del numero di elementi negativi in posizione dispari.
il secondo (vetVerNeg) è il numero di righe della matrice in cui almeno un terzo degli elementi negativi siano  maggiori del corrispondente elemento del vettore V (si suppone che la dimensione di V è pari al numero di colonne della matrice). 
Il metodo main che dichiara e alloca la matrice e invoca opportunamente i metodi precedenti. */

#include <stdio.h>
#include <stdlib.h>

int** create(int n, int m);
void read(int** M, int n, int m);
void print(int** M, int n, int m);
void verifica_vet_matrice(int** M, int n, int m, int* V, int dimV, int* matVerPos, int* vetVerNeg);

int main() {
    int n, m, dimV, matVerPos, vetVerNeg, i;
    int* V;
    int** M;

    matVerPos = 0;
    vetVerNeg = 0;

    printf("Inserisci dimensione vettore:");
    scanf("%d", &dimV);
    V = (int*) malloc(dimV * sizeof(int));
    if (V == NULL) {
        printf("Errore allocazione memoria");
        exit(1);
    }
    for (i = 0; i < dimV; i++) {
        printf("Inserisci V[%d]", i);
        scanf("%d", &V[i]);
    }

    printf("Inserisci n:");
    scanf("%d", &n);
    printf("Inserisci m:");
    scanf("%d", &m);

    if (m != dimV) {
        printf("Errore! Il numero delle colonne della matrice deve essere uguale alla dimensione del vettore V");
        exit(1);
    }

    M = create(n, m);
    read(M, n, m);
    print(M, n, m);

    verifica_vet_matrice(M, n, m, V, dimV, &matVerPos, &vetVerNeg);

    printf("matVerPos = %d\n", matVerPos);
    printf("vetVerNeg = %d\n", vetVerNeg);

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

void verifica_vet_matrice(int** M, int n, int m, int* V, int dimV, int* matVerPos, int* vetVerNeg) {
    int i, j, numPosPari, numNegDispari, numElemNegativi, numElemOk;

    for (j = 0; j < m; j++) {
        numPosPari = 0;
        numNegDispari = 0;

        for (i = 0; i < n; i++) {
            if (i % 2 == 0) {
                if (M[i][j] >= 0) {
                    numPosPari++;
                }
            } else {
                if (M[i][j] < 0) {
                    numNegDispari++;
                }
            }
        }

        if (numPosPari > numNegDispari) {
            *matVerPos = (*matVerPos) + 1;
        }
    }

    for (i = 0; i < n; i++) {
        numElemNegativi = 0;
        numElemOk = 0;

        for (j = 0; j < m; j++) {
            if (M[i][j] < 0) {
                numElemNegativi++;

                if (M[i][j] > V[j]) {
                    numElemOk++;
                }
            }
        }

        if (numElemOk >= numElemNegativi/3) {
            *vetVerNeg = (*vetVerNeg) + 1;
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
