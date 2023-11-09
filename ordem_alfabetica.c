#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp_function(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    FILE *file;
    file = fopen("arq.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    char line[100];
    char *token;
    char **names = NULL;
    int aux = 0;

    while (fgets(line, sizeof(line), file)) {
        int size = strlen(line);

        if (size > 0 && line[size - 1] == '\n') {
            line[size - 1] = '\0';
        }

        token = strtok(line, "-");

        names = (char **)realloc(names, (aux + 1) * sizeof(char *));
        names[aux] = strdup(token);
        aux++;
        
    }

    qsort(names, aux, sizeof(char *), cmp_function);

    printf("Nomes em ordem alfabética:\n");
    for (int i = 0; i < aux; i++) {
        printf("%s\n", names[i]);
        free(names[i]);
    }

    free(names);
    fclose(file);

    return 0;
}
