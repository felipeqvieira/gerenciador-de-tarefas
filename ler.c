#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#include "lista.h"
#include "ler.h"

#define CARACTERES 1024

void ler_arquivo(FILE *arq, lista_t* l){

    char *buffer = NULL;
    size_t bufsize = 0;
    ssize_t characters;

    while ((characters = getline(&buffer, &bufsize, arq)) != -1)
        adiciona_ordem_lista(l, buffer);

    free(buffer);
    fclose(arq);

}