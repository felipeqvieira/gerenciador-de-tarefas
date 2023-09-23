#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "adiciona.h"

char *inputString() {
    int ch;
    size_t size = 16; // Tamanho inicial do buffer
    char *str = malloc(size);
    if (!str) return NULL;
    
    size_t len = 0;
    
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (len == size - 1) {
            size *= 2;
            char *tmp = realloc(str, size);
            if (!tmp) {
                free(str);
                return NULL;
            }
            str = tmp;
        }
        str[len++] = ch;
    }
    
    str[len] = '\0';
    
    return str;
}

int adiciona_tarefas(FILE* arquivo_tarefas, lista_t* l){
    
    char *m = inputString();
    
    if (! m) 
        printf("Erro ao alocar memória para a entrada.\n");

    if (m[0] != '\0' && m[0] != '\n')
        adiciona_ordem_lista(l, m);

    free(m);

    return 1;

}
