/*
Usate un vettore dinamico e una matrice statica
    void massimo_negativi (int **mat, int n, int m, int *vett, int k, int *max, int *neg) 
Un metodo massimo_negativi che restituisce (in maniera opportuna usando i puntatori), due interi, 
a)	il massimo di tutta la matrice
b)	il numero di righe che contengono tutti gli elementi del vettore (stessa posizione più facile
o posizione diversa (più difficile))
nel primo caso la dimens. del vettore == num_colonne k==m
*/



#include <stdio.h>
#include <stdlib.h>

#define N 3
#define M 4


void massimo_negativi(int **mat, int n, int m, int *vett, int k, int *max, int *neg) {
    // Massimo matrice
    if (N > 0 && M > 0) {
        *max = mat[0][0];
    } else {
        printf("Matrice vuota\n");
        return;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (mat[i][j] > *max) {
                *max = mat[i][j];
            }
        }
    }


    // Calcolo neg
    *neg = 0;
    int trovato;
    for (int i = 0; i < N; i++) {
        for (int q = 0; q < k; q++) {
            trovato = 0;
            for (int j = 0; j < M; j++) {
                if (mat[i][j] == vett[q]) {
                    trovato = 1;
                    break;  // Se ho trovato l'elemento q-esimo, verifico se il prossimo elemento è presente nella riga
                }
            }

            if (!trovato) {     // Se almeno un elemento del vettore non è presente nella riga, passo alla prossima
                break;
            }
        }

        if (trovato) {
            *neg += 1;
        }
    }
}


int main(void){
    // Istanziazione e popolamento matrice
    int mat[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("Inserisci elemento mat[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }


    /* Se volessi copiare la matrice statica in una dinamica, in modo da passarla al metodo come int **mat.
    In alternativa, il metodo avrebbe dovuto prendere int mat[N][M] */
    int **new_mat = (int **) malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        new_mat[i] = (int *) malloc(M * sizeof(int));
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            new_mat[i][j] = mat[i][j];
        }
    }


    // Istanziazione e popolamento vettore
    int k;
    printf("Inserisci dimensione vettore: ");
    scanf("%d", &k);
    int *vett = (int *) malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        printf("Inserisci elemento vett[%d]", i);
        scanf("%d", &vett[i]);
    }

    // Chiamata al metodo e terminazione programma
    int max;
    int neg;
    massimo_negativi(new_mat, N, M, vett, k, &max, &neg);
    printf("max=%d, neg=%d\n", max, neg);

    return 0;
}