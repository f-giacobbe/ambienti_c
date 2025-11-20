#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char prima[100];
    char seconda[100];
    char finale[100];

    printf("Prima stringa: ");
    scanf("%s", prima);

    printf("Seconda stringa: ");
    scanf("%s", seconda);

    sprintf(finale, "%s%s", prima, seconda);

    printf("La concatenazione delle due stringhe è %s\n", finale);
    return 0;
}