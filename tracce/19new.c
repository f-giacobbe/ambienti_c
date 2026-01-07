/* Scrivere un programma in C per la gestione di matrici di float, che contenga i seguenti metodi:
Una funzione create, che riceve due interi (dimensione di righe e colonne), crea una matrice delle dimensioni indicate, e restituisce il suo puntatore.
Un metodo read per la lettura di una matrice da tastiera.
Un metodo print per la stampa della matrice su output.
Un metodo verifica_vet_matrice che restituisce (in maniera opportuna usando i puntatori) 2 interi, vetMultipli e vetIncluso:
il primo (vetMinimo) è il numero di colonne della matrice in cui tutti gli elementi siano multipli  del minimo della matrice. 
il secondo (vetSbagliato) è il numero di righe che contengono il vettore ma con almeno un elemento in posizione differente. Ad esempio se il vettore è: [4, 2, 8], la riga della matrice è: [4, 2, 8] non deve essere considerato. Se la riga fosse stata [4 8 2]  andava invece contato.
Il metodo main che dichiara e alloca la matrice e invoca opportunamente i metodi precedenti. */

#include <stdio.h>
#include <stdlib.h>
typedef enum {false, true} boolean;

float** create(int n, int m);
void read(float** M, int n, int m);
void print(float**M, int n, int m);
void verifica_vet_matrice(float** M, int n, int m, float* V, int dimV, int* vetMultipli, int* vetSbagliato);

int main() {
    int i, n, m, dimV, vetMultipli, vetSbagliato;
    float* V;
    float** M;

    vetMultipli = 0;
    vetSbagliato = 0;

    /* Definizione vettore */
    printf("Inserisci dimensione vettore:");
    scanf("%d", &dimV);
    V = (float*) malloc(dimV * sizeof(float));
    if (V == NULL) {
        printf("Errore allocazione memoria\n");
        exit(1);
    }
    for (i = 0; i < dimV; i++) {
        printf("Inserisci V[%d]", i);
        scanf("%f", &V[i]);
    }

    /* Definizione matrice */
    printf("Inserisci n:");
    scanf("%d", &n);
    printf("Inserisci m:");
    scanf("%d", &m);
    M = create(n, m);
    read(M, n, m);
    print(M, n, m);

    /* Chiamata al metodo */
    verifica_vet_matrice(M, n, m, V, dimV, &vetMultipli, &vetSbagliato);
    printf("vetMultipli = %d\nvetSbagliato = %d", vetMultipli, vetSbagliato);

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

void verifica_vet_matrice(float** M, int n, int m, float* V, int dimV, int* vetMultipli, int* vetSbagliato) {
    int i, j, k;
    float min;
    boolean tuttiMultipli, elemInPosDifferente, contieneTutto, elemContenuto;

    /* Calcolo minimo matrice */
    min = M[0][0];

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (M[i][j] < min) {
                min = M[i][j];
            }
        }
    }


    /* Calcolo vetMinimo */
    for (j = 0; j < m; j++) {
        tuttiMultipli = true;

        for (i = 0; i < n; i++) {
            if ((int)M[i][j] % (int)min != 0) {
                tuttiMultipli = false;
                break;
            }
        }

        if (tuttiMultipli) {
            *vetMultipli = (*vetMultipli) + 1;
        }
    }

    
    /* Calcolo vetSbagliato*/
    for (i = 0; i < n; i++) {
        elemInPosDifferente = false;
        contieneTutto = true;

        for (k = 0; k < dimV; k++) {
            elemContenuto = false;

            for (j = 0; j < m; j++) {
                if (M[i][j] == V[k]) {
                    elemContenuto = true;

                    if (j != k) {
                        elemInPosDifferente = true;
                    }

                    break;
                }
            }

            if (!elemContenuto) {
                contieneTutto = false;
                break;
            }
        }

        if (elemInPosDifferente && contieneTutto) {
            *vetSbagliato = (*vetSbagliato) + 1;
        }
    }
}

float** create(int n, int m) {
    int i;
    float** M;

    M = (float**) malloc(n * sizeof(float*));
    if (M == NULL) {
        printf("Errore allocazione memoria\n");
        exit(1);
    }
    for (i = 0; i < n; i++) {
        M[i] = (float*) malloc(m * sizeof(float));
        if (M[i] == NULL) {
            printf("Errore allocazione memoria\n");
            exit(1);
        }
    }

    return M;
}

void read(float** M, int n, int m) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("Inserisci M[%d][%d]:", i, j);
            scanf("%f", &M[i][j]);
        }
    }
}

void print(float**M, int n, int m) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("M[%d][%d] = %f", i, j, M[i][j]);
        }
    }
}
