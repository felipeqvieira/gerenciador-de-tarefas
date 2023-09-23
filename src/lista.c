#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

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

void printa_lista(lista_t *l){

    int i = 1;

    /* verifica se ha elementos */
    if (l->Primeiro != NULL){
        nodo_lista_t * aux;
        aux = l->Primeiro;
        
        /* se tiver, vai varrendo e dando free com aux */
        while (aux != NULL){

            if(aux->concluido == 1)
                printf("%d: (concluido) %s\n",i, aux->dado);
            else
                printf("%d: %s\n",i, aux->dado);

            aux = aux->prox;
            i++;

        }
    }

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


int adiciona_ordem_lista(lista_t *l, char* elemento) {
    /* cria novo nodo */
    nodo_lista_t *novo;

    /* aloca novo nodo */
    novo = malloc(sizeof(nodo_lista_t));
    novo->dado = malloc(sizeof(char) * STRING_SIZE);
    novo->concluido = 0;

    /* verificação de alocação de memória */
    if (novo == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return 0;
    }

    /* copia o elemento para o novo nodo */
    strcpy(novo->dado, elemento);

    /* indica prox como null */
    novo->prox = NULL;

    /* se não há elementos */
    if (l->Primeiro == NULL) {
        novo->prox = l->Primeiro;
        l->Primeiro = novo;
        l->tamanho++;
        return 1;
    } else {
        nodo_lista_t *atual = l->Primeiro;
        nodo_lista_t *anterior = NULL;

        if(novo->dado[0] >= 97 && novo->dado[0] <= 122){
            novo->dado[0] = novo->dado[0] - 32;
        }

        if(atual->dado[0] >= 97 && atual->dado[0] <= 122){
            atual->dado[0] = atual->dado[0] - 32;
        }

        if(! toupper(atual->dado[0])){
            fprintf(stderr, "Erro na letra inicial\n");
        }

        /* Compare as strings e encontre a posição correta */
        while (atual != NULL && strcmp(novo->dado, atual->dado) > 0) {
            anterior = atual;
            atual = atual->prox;
        }

        /* Insira o novo nodo na posição correta */
        if (anterior == NULL) {
            /* Inserir no início da lista */
            novo->prox = l->Primeiro;
            l->Primeiro = novo;
        } else {
            /* Inserir após o anterior */
            anterior->prox = novo;
            novo->prox = atual;
        }

        l->tamanho++;
        return 1;
    }

    return 0;
}

/* funcao para buscar numero na lista */
int busca_string (lista_t *l, char* c){

    /* verifica se ha elementos*/
    if (l->Primeiro != NULL){

        /* cria ponteiro aux */
        nodo_lista_t *aux;

        char *string;

        /* aux aponta para primeiro*/
        aux = l->Primeiro;

        /* enquanto nao chegar no ultimo elemento da lista */
        while (aux != NULL){
            
            /* se encontrar o valor */
            if( (string = strstr(aux->dado, c)) != NULL ) 
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