/* Scrivere un programma in C per la gestione di matrici di double, che contenga i seguenti metodi:
Una funzione create, che riceve due interi (dimensione di righe e colonne), crea una matrice delle dimensioni indicate, e restituisce il suo puntatore.
Un metodo read per la lettura di una matrice da tastiera.
Un metodo print per la stampa della matrice su output.
Un metodo verifica_mat che riceve una matrice di double, un vettore di interi e le opportune variabili e restituisce (in maniera opportuna usando i puntatori) 
1) il numero di righe della matrice, in cui sono contenuti tutti gli elementi del vettore (anche in posizione diversa). Gli elementi della matrice devono essere trasformati in intero prima del confronto.
2) il numero di colonne in cui la media degli elementi pari sia superiore in valore assoluto alla media degli elementi in posizione dispari.
Il metodo main che dichiara e alloca la matrice  e invoca opportunamente i metodi precedenti.
NOTA: QUALSIASI SOLUZIONE ALTERNATIVA CHE NON USI I PUNTATORI SARA’ CONSIDERATA ERRATA. */

#include <stdio.h>
#include <stdlib.h>
typedef enum {false, true} boolean;

void verifica_mat(double** M, int n, int m, int* V, int dimV, int* righeOK, int* colonneOK);
double** create(int n, int m);
void read(double** M, int n, int m);
void print(double** M, int n, int m);

int main() {
    int i, n, m, dimV, righeOK, colonneOK;
    int* V;
    double** M;

    righeOK = 0;
    colonneOK = 0;

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
    printf("Inserisci numero righe:");
    scanf("%d", &n);
    printf("Inserisci numero colonne:");
    scanf("%d", &m);
    M = create(n, m);
    read(M, n, m);
    print(M, n, m);

    /* Chiamata al metodo */
    verifica_mat(M, n, m, V, dimV, &righeOK, &colonneOK);
    printf("Righe OK = %d\nColonne OK = %d\n", righeOK, colonneOK);

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

void verifica_mat(double** M, int n, int m, int* V, int dimV, int* righeOK, int* colonneOK) {
    int i, j, k, elemPari, elemDispari;
    double mediaPari, mediaDispari, sommaPari, sommaDispari;
    boolean rigaOK, elemContenuto;

    /* Calcolo righeOK */
    for (i = 0; i < n; i++) {
        rigaOK = true;

        for (k = 0; k < dimV; k++) {
            elemContenuto = false;

            for (j = 0; j < m; j++) {
                if ((int)M[i][j] == V[k]) {
                    elemContenuto = true;
                    break;
                }
            }

            if (!elemContenuto) {
                rigaOK = false;
                break;
            }
        }

        if (rigaOK) {
            *righeOK = (*righeOK) + 1;
        }
    }

    /* Calcolo colonneOK */
    for (j = 0; j < m; j++) {
        sommaPari = 0;
        sommaDispari = 0;
        mediaPari = 0;
        mediaDispari = 0;
        elemPari = 0;
        elemDispari = 0;

        for (i = 0; i < n; i++) {
            if (i % 2 == 0) {
                sommaPari += M[i][j];
                elemPari++;
            } else {
                sommaDispari += M[i][j];
                elemDispari++;
            }
        }

        mediaPari = sommaPari / elemPari;
        mediaDispari = sommaDispari / elemDispari;

        if (abs(mediaPari) > abs(mediaDispari)) {
            *colonneOK = (*colonneOK) + 1;
        }
    }
}

double** create(int n, int m) {
    double** M;
    int i;

    M = (double**) malloc(n * sizeof(double*));
    if (M == NULL) {
        printf("Errore allocazione memoria\n");
        exit(1);
    }
    for (i = 0; i < n; i++) {
        M[i] = (double*) malloc(m * sizeof(double));
        if (M[i] == NULL) {
            printf("Errore allocazione memoria\n");
            exit(1);
        }
    }

    return M;
}

void read(double** M, int n, int m) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("Inserisci M[%d][%d]:", i, j);
            scanf("%lf", &M[i][j]);
        }
    }
}

void print(double** M, int n, int m) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("M[%d][%d] = %lf\n", i, j, M[i][j]);
        }
    }
}
