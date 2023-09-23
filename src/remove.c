#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "remove.h"

void remove_lista(lista_t *l, int n){

        nodo_lista_t *aux;

        if(n == 1){
            aux = l->Primeiro;
            l->Primeiro = l->Primeiro->prox;
            free(aux->dado);
            free(aux);
            return;
        }
        
        nodo_lista_t *anterior;
        anterior = l->Primeiro;
        
        int i = 0;        

        while (anterior->prox != NULL && i < n-2){
            anterior = anterior->prox;
            i++;
        }
        
        aux = anterior->prox;
        anterior->prox = anterior->prox->prox;

        l->tamanho--;

        free(aux->dado);
        free(aux);

        return;

}