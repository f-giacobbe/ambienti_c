/*Scrivere un programma in C per la gestione di matrici di double, che contenga i seguenti metodi:
Una funzione create, che riceve due interi (dimensione di righe e colonne), crea una matrice delle dimensioni indicate, e restituisce il suo puntatore.
Un metodo read per la lettura di una matrice da tastiera.
Un metodo print per la stampa della matrice su output.
Un metodo verifica_mat che riceve una matrice di double, un vettore di interi e le opportune variabili e restituisce (in maniera opportuna usando i puntatori) 
1) il numero di colonne della matrice, che sono DOPPIE del vettore, cioè in cui ogni elemento del vettore è contenuto almeno 2 volte.
2) il numero di righe in cui la somma degli elementi sia minore di 5 volte la media degli elementi.
Il metodo main che dichiara e alloca la matrice  e invoca opportunamente i metodi precedenti.
NOTA: QUALSIASI SOLUZIONE ALTERNATIVA CHE NON USI I PUNTATORI SARA’ CONSIDERATA ERRATA. */

#include <stdio.h>
#include <stdlib.h>
typedef enum {false, true} boolean;

double** create(int n, int m);
void read(double** M, int n, int m);
void print(double**M, int n, int m);
void verifica_mat(double** M, int n, int m, int* V, int dimV, int* colVerificate, int* rigVerificate);

int main() {
    int i, n, m, dimV, colVerificate, rigVerificate;
    int* V;
    double** M;

    colVerificate = 0;
    rigVerificate = 0;

    /* Definizione vettore */
    printf("Inserisci dimensione vettore:");
    scanf("%d", &dimV);
    V = (int*) malloc(dimV * sizeof(int));
    if (V == NULL) {
        printf("Errore allocazione memoria\n");
        exit(1);
    }
    for (i = 0; i < dimV; i++) {
        printf("Inserisci V[%d]", i);
        scanf("%d", &V[i]);
    }

    /* Definizione matrice */
    printf("Inserisci n:");
    scanf("%d", &n);
    printf("Inserisci m:");
    scanf("%d", &m);
    M = create(n, m);
    read(M, n, m);
    print(M, n, m);

    /* Chiamata al metodo verifica_mat */
    verifica_mat(M, n, m, V, dimV, &colVerificate, &rigVerificate);
    printf("colVerificate = %d\nrigVerificate = %d", colVerificate, rigVerificate);

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

void verifica_mat(double** M, int n, int m, int* V, int dimV, int* colVerificate, int* rigVerificate) {
    int i, j, k, contenuto;
    double sommaElementiRiga, mediaRiga;
    boolean colonnaOK;

    /* Calcolo colVerificate */
    for (j = 0; j < m; j++) {
        colonnaOK = true;

        /* Verifico se ogni elemento del vettore è contenuto almeno 2 volte */
        for (k = 0; k < dimV; k++) {
            contenuto = 0;

            for (i = 0; i < n; i++) {
                if (M[i][j] == (double)V[k]) {
                    contenuto++;

                    if (contenuto >= 2) {
                        break;
                    }
                }
            }

            if (contenuto < 2) {
                colonnaOK = false;
                break;
            }
        }

        if (colonnaOK) {
            *colVerificate = (*colVerificate) + 1;
        }
    }

    /* Calcolo rigVerificate */
    for (i = 0; i < n; i++) {
        sommaElementiRiga = 0;
        mediaRiga = 0;

        /* Calcolo somma elementi riga */
        for (j = 0; j < m; j++) {
            sommaElementiRiga += M[i][j];
        }

        mediaRiga = sommaElementiRiga/m;

        if (sommaElementiRiga < 5*mediaRiga) {
            *rigVerificate = (*rigVerificate) + 1;
        }
    }
}

double** create(int n, int m) {
    int i;
    double** M;

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

void print(double**M, int n, int m) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("M[%d][%d] = %lf\n", i, j, M[i][j]);
        }
    }
}
