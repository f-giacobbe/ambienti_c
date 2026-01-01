/* Scrivere un programma in C per la gestione di matrici di interi, che contenga i seguenti metodi:
Un metodo verifica_vet_matrice, a cui viene passato fra gli altri parametri anche un vettore V di interi, un intero K e che restituisce (in maniera opportuna usando i puntatori) 2 interi, rigVerificata e colVerificata:
il primo (rigVerificata) corrisponde al numero di righe che verifichino la seguente proprietà: il numero di elementi dispari è maggiore di K (esempio: se K=4, la riga [11, 15, 8, 9, 7, 12, 13] rispetta la proprietà perché ha 5 elementi dispari). 
il secondo (colVerificata) è il numero di colonne della matrice in cui la somma degli elementi è minore di 100 e in cui ci sono almeno 4 elementi contenuti nel vettore V. 
Il metodo main che dichiara e alloca la matrice (chiamando il metodo create) e invoca opportunamente i metodi precedenti.
Facoltativi, se rimane tempo i seguenti 3 metodi:
Una funzione create, che riceve due interi (dimensione di righe e colonne), crea una matrice delle dimensioni indicate, e restituisce il suo puntatore.
Un metodo read per la lettura di una matrice da tastiera.
Un metodo print per la stampa della matrice su output. */

#include <stdio.h>
#include <stdlib.h>

void verifica_vet_matrice(int **M, int n, int m, int *V, int dimV, int K, int *rigVerificata, int *colVerificata);
int** create(int n, int m);
void read(int **M, int n, int m);
void print(int **M, int n, int m);

int main() {
    int n, m, dimV, K, rigVerificata, colVerificata, i;
    int *V;
    int **M;

    rigVerificata = 0;
    colVerificata = 0;

    /* Istanziazione e popolamento vettore */
    printf("Inserisci dimensione vettore: ");
    scanf("%d", &dimV);

    V = (int *) malloc(dimV * sizeof(int));
    if (V == NULL) {
        printf("Errore allocazione memoria");
        exit(1);
    }

    for (i = 0; i < dimV; i++) {
        printf("Inserisci V[%d]:", i);
        scanf("%d", &V[i]);
    }



    printf("Inserisci valore di K: ");
    scanf("%d", &K);

    
    /* Istanziazione e popolamento matrice */
    printf("Inserisci n: ");
    scanf("%d", &n);
    printf("Inserisci m: ");
    scanf("%d", &m);
    M = create(n, m);
    read(M, n, m);
    print(M, n, m);


    /* Chiamata al metodo e terminazione programma LIBERANDO LA MEMORIA ALLOCATA COL MALLOC */
    verifica_vet_matrice(M, n, m, V, dimV, K, &rigVerificata, &colVerificata);
    printf("rigVerificata = %d\ncolVerificata = %d\n", rigVerificata, colVerificata);

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

void verifica_vet_matrice(int** M, int n, int m, int* V, int dimV, int K, int* rigVerificata, int* colVerificata) {
    int i, j, k, numDispariRiga, sommaCol, elementiInV;

    /* Calcolo righe che rispettano la proprietà */
    for (i = 0; i < n; i++) {
        numDispariRiga = 0;

        for (j = 0; j < m; j++) {
            if (M[i][j] % 2 != 0) {     /* Per ogni elemento dispari della riga */
                numDispariRiga++;

                if (numDispariRiga > K) {
                    break;
                }
            }
        }

        if (numDispariRiga > K) {
            *rigVerificata = *rigVerificata + 1;
        }
    }

    /* Calcolo colonne che rispettano la proprietà */
    for (j = 0; j < m; j++) {
        sommaCol = 0;
        elementiInV = 0;

        for (i = 0; i < n; i++) {
            sommaCol += M[i][j];

            for (k = 0; k < dimV; k++) {
                if (M[i][j] == V[k]) {
                    elementiInV++;
                    break;
                }
            }

            if (sommaCol >= 100) {
                break;
            }
        }

        if (sommaCol < 100 && elementiInV >= 4) {
            *colVerificata = *colVerificata + 1;
        }
    }
}

int** create(int n, int m) {
    int i;
    int **M;

    M = (int **) malloc(n * sizeof(int *));
    if (M == NULL) {
        printf("Errore allocazione\n");
        exit(1);
    }
    for (i = 0; i < n; i++) {
        M[i] = (int *) malloc(m * sizeof(int));
        if (M[i] == NULL) {
            printf("Errore allocazione\n");
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