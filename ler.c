#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#include "lista.h"
#include "ler.h"

void ler_arquivo(FILE *arq, lista_t* l){

    char *buffer = NULL;
    size_t bufsize = 0;
    ssize_t characters;

    while ((characters = getline(&buffer, &bufsize, arq)) != -1){
        // Remove o caractere de nova linha (se existir)
        size_t len = strcspn(buffer, "\n");
        if (len > 0) {
            buffer[len] = '\0';  // Substitui o '\n' pelo caractere nulo
        }
        printf("tarefas: %s\n", buffer);
        adiciona_ordem_lista(l, buffer);
    }

    free(buffer);
    fclose(arq);
}