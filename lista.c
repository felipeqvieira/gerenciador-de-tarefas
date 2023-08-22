#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lista.h"

#define STRING_SIZE 1024

/* funcao que cria lista */
lista_t *cria_lista(){

    /* aloca lista */
    lista_t *l = malloc(sizeof(lista_t));

    /* verificacao */
    if (l == NULL){
        printf("Erro de alocacao de memoria!\n");
        return NULL;
    }

    /* inicializacao de Primeiro e tamanho */
    l->Primeiro = NULL;

    l->tamanho = 0;

    return l;
}

/* funcao que destroi a lista */
lista_t * destroi_lista(lista_t *l){
    
    /* verifica se ha elementos */
    if (l->Primeiro != NULL){
        nodo_lista_t * aux;
        
        /* se tiver, vai varrendo e dando free com aux */
        while (l->Primeiro){

            aux = l->Primeiro;

            l->Primeiro = aux->prox;

            free(aux->dado);
            free(aux);

            l->tamanho--;

        }
    }

    /* da free na lista no fim */
    free(l);

    return NULL;
}


/* funcao para inserir numero de forma ordenada*/
int adiciona_ordem_lista(lista_t *l, char* elemento){

    /* cria novo nodo */
    nodo_lista_t *novo;

    /* aloca novo nodo */
    novo = malloc(sizeof(nodo_lista_t));
    novo->dado = malloc(sizeof(STRING_SIZE));

    /* verificacao */
    if (novo == NULL){
        printf("Erro de alocacao de memoria!\n");
        return 0;
    }

    /* nodo recebe o elemento */
    novo->dado = elemento;

    /* indica prox como null*/
    novo->prox = NULL;

    /* se nao ha elementos */
    if(l->Primeiro == NULL){

        novo->prox = l->Primeiro;
        l->Primeiro = novo;
        l->tamanho++;
        return 1;

    }
    /* se ha elemento(s) */
    else{
        /* ordenacao */
        if(novo->dado[0] < l->Primeiro->dado[0]){

            novo->prox = l->Primeiro;
            l->Primeiro = novo;
            l->tamanho++;
            return 1;

        }else if(novo->dado[0] > l->Primeiro->dado[0]){

            nodo_lista_t *aux;
            aux = l->Primeiro;

            while (aux->prox != NULL && aux->prox->dado[0] < novo->dado[0])
                aux = aux->prox;

            novo->prox = aux->prox;
            aux->prox = novo;

            l->tamanho++;

            return 1;
        }
    }

    return 0;
}

/* funcao para buscar numero na lista */
int busca_inteiro (lista_t *l, char* c){

    /* verifica se ha elementos*/
    if (l->Primeiro != NULL){

        /* cria ponteiro aux */
        nodo_lista_t *aux;

        /* aux aponta para primeiro*/
        aux = l->Primeiro;

        /* enquanto nao chegar no ultimo elemento da lista */
        while (aux != NULL){
            
            /* se encontrar o valor */
            if(aux->dado == c)
                return 1;

            /* se nao for, continua seguindo */
            aux = aux->prox;
        }
        
        return 0;
    }

    return 0;
}

/* funcao que calcula tamanho da lista */
int tamanho_lista(lista_t *l){
    
    return l->tamanho;

}