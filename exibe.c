#include "lista.h"

void exibir_tarefas(lista_t *l){

    printf("Tarefas:\n\n");

    for(int i = 0; i < tamanho_lista(l); i++){
        printf("%d:", i);
        printa_lista(l);
        printf("\n");
    }
        
    return ;
}