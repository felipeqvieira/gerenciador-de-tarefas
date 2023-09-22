#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "conclui.h"

void conclui_tarefa(lista_t *l, int n){

    if (n > tamanho_lista(l) || n <= 0)
        printf("Numero invalido\n");

    int i = 1;

    nodo_lista_t * aux;
    aux = l->Primeiro;
     
    while (aux != NULL && i < n){

        aux = aux->prox;
        i++;

    }

    aux->concluido = 1;
    
}