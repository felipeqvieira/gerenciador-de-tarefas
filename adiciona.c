#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "adiciona.h"

char *inputString(FILE* fp, size_t size){
//The size is extended by the input with the value of the provisional
    char *str;
    int ch;
    size_t len = 0;
    str = realloc(NULL, sizeof(*str)*size);//size is start size
    if(!str)return str;
    while(EOF!=(ch=fgetc(fp)) && ch != '\n'){
        str[len++]=ch;
        if(len==size){
            str = realloc(str, sizeof(*str)*(size+=16));
            if(!str)return str;
        }
    }
    str[len++]='\0';

    return realloc(str, sizeof(*str)*len);
}

void adiciona_tarefas(FILE* arquivo_tarefas, lista_t* l){

    printf("Escreva a tarefa: \n");
    
    char *m;

    m = inputString(stdin, 10);

    if (m[0] != '\0' && m[0] != '\n')
        adiciona_ordem_lista(l, m);

    free(m);

}
