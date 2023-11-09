#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file;
    file = fopen("arq.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    char line[100];
    char cpf[7] = "123445";

    while (fgets(line, sizeof(line), file)) {
        int size = strlen(line);

        if (size > 0 && line[size - 1] == '\n') {
            line[size - 1] = '\0';
        }

        if (strstr(line, cpf) != NULL) {
            printf("%s\n", line);
        }
    }

    fclose(file);

    return 0;
}