/* Scrivere un programma in C per la gestione di matrici di float, che contenga i seguenti metodi:
Una funzione create, che riceve due interi (dimensione di righe e colonne), crea una matrice delle dimensioni indicate, e restituisce il suo puntatore.
Un metodo read per la lettura di una matrice da tastiera.
Un metodo print per la stampa della matrice su output.
Un metodo verifica_vet_matrice, a cui viene passato fra gli altri parametri anche un vettore V, e che restituisce (in maniera opportuna usando i puntatori) 2 interi, matGrande e vetPiccolo:
il primo (matGrande) corrisponde al numero di righe pari che sono più grandi della corrispondente riga dispari (la 0 rispetto alla 1, 
la 2 rispetto alla 3. E così via). Per più grande si intende che almeno la metà più uno degli elementi siano maggiori degli elementi 
corrispondenti dell’altra riga.
il secondo (vetPiccolo) è il numero di colonne della matrice in cui almeno metà +1 elementi siano più grandi  del
corrispondente elemento del vettore V (si suppone che la dimensione di V è pari al numero di righe della matrice). 
Il metodo main che dichiara e alloca la matrice e invoca opportunamente i metodi precedenti.
NOTA: QUALSIASI SOLUZIONE ALTERNATIVA CHE NON USI I PUNTATORI SARA’ CONSIDERATA ERRATA. */

#include <stdio.h>
#include <stdlib.h>

void verifica_vet_matrice(float** M, int n, int m, float* V, int dimV, int* matGrande, int* vetPiccolo);
float** create(int n, int m);
void read(float** M, int n, int m);
void print(float** M, int n, int m);

int main() {
    int i, n, m, dimV, matGrande, vetPiccolo;
    float* V;
    float** M;

    matGrande = 0;
    vetPiccolo = 0;

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
    printf("Inserisci numero righe:");
    scanf("%d", &n);
    printf("Inserisci numero colonne");
    scanf("%d", &m);
    M = create(n ,m);
    read(M, n, m);
    print(M, n, m);

    /* Chiamata al metodo */
    verifica_vet_matrice(M, n, m, V, dimV, &matGrande, &vetPiccolo);
    printf("matGrande = %d\nvetPiccolo = %d", matGrande, vetPiccolo);

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

void verifica_vet_matrice(float** M, int n, int m, float* V, int dimV, int* matGrande, int* vetPiccolo) {
    int i, j, iPari, iDispari, elemMaggiori;

    /* Verifica assunzioni */
    if (n % 2 != 0) {
        printf("Errore, numero righe non pari\n");
        return;
    }
    
    if (dimV != n) {
        printf("Errore, numero righe della matrice diverso dalla dimensione di V\n");
        return;
    }
    
    /* Calcolo matGrande (si assume che n sia pari) */
    for (i = 0; i < n; i += 2) {
        iPari = i;
        iDispari = i + 1;

        elemMaggiori = 0;

        for (j = 0; j < m; j++) {
            if (M[iPari][j] > M[iDispari][j]) {
                elemMaggiori++;
            }
        }

        if (elemMaggiori >= (m / 2) + 1) {
            *matGrande = (*matGrande) + 1;
        }
    }

    /* Calcolo vetPiccolo */
    for (j = 0; j < m; j++) {
        elemMaggiori = 0;

        for (i = 0; i < n; i++) {
            if (M[i][j] > V[i]) {
                elemMaggiori++;
            }
        }

        if (elemMaggiori >= (n / 2) + 1) {
            *vetPiccolo = (*vetPiccolo) + 1;
        }
    }
}

float** create(int n, int m) {
    float** M;
    int i;

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

void print(float** M, int n, int m) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("M[%d][%d] = %f\n", i, j, M[i][j]);
        }
    }
}
