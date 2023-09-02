#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>

#define STRING_SIZE 1024

/* struct lista*/
typedef struct nodo_lista{

    struct nodo_lista *prox;
    char* dado;
    int concluido;

}nodo_lista_t;

typedef struct lista{

    nodo_lista_t *Primeiro;
    int tamanho;

}lista_t;

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

    /* verifica se ha elementos */
    if (l->Primeiro != NULL){
        nodo_lista_t * aux;
        aux = l->Primeiro;
        
        /* se tiver, vai varrendo e dando free com aux */
        while (aux != NULL){
            
            printf("%s\n", aux->dado);

            aux = aux->prox;

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

    novo->concluido = 0;

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

    adiciona_ordem_lista(l, m);

    free(m);

}

void exibir_tarefas(lista_t *l){

    printf("Tarefas:\n\n");

    for(int i = 0; i < tamanho_lista(l); i++){
        printf("%d:", i);
        printa_lista(l);
        printf("\n");
    }
        
    return ;
}

void ler_arquivo(FILE *arq, lista_t* l){

    char *buffer = NULL;
    size_t bufsize = 0;
    ssize_t characters;

    printf("lendo arquivo!\n");

    while ((characters = getline(&buffer, &bufsize, arq)) != -1){
        puts(buffer);
        adiciona_ordem_lista(l, buffer);
    }

    free(buffer);
    fclose(arq);

}


int main(int argc, char **argv){

    lista_t *l = cria_lista();

    if(l == NULL){
        printf("Erro ao criar a lista!\n");
        return 0;
    }

    int saida = -1;
    int option = -1;

    char *nome_arquivo = malloc(sizeof(STRING_SIZE));

    FILE *arquivo_tarefas = fopen(nome_arquivo, "r");

    if (! arquivo_tarefas){
        printf("Gerenciador inexistente. Criando um novo...\n");
        arquivo_tarefas = fopen(nome_arquivo, "w");
    }
    else{
        printf("Arquivo encontrado!\n");
        ler_arquivo(arquivo_tarefas, l);
    }

    while(saida != 0){

        printf("\n\n===========================================\n\n");
        printf("0. Sair\n");
        printf("1. Adicionar Tarefa\n");
        printf("2. Remover Tarefa\n");
        printf("3. Marcar Tarefa como Concluida\n");
        printf("4. Desmarcar Tarefa como Concluida\n");
        printf("5. Exibir Tarefas\n");
        printf("\n\n===========================================\n\n");
        
        scanf("%d", &option);

        switch(option){

            case 0:
                saida = 0;
                break;
        
            case 1:
                //adiciona
                printf("Voce quer adicionar uma tarefa!\n");
                adiciona_tarefas(arquivo_tarefas, l);
                break;
            
            case 2:
                //remove
                break;
            
            case 3:
                //concluida 
                break;

            case 4:
                //desfazer
                break;

            case 5:
                //exibir 
                printf("Voce quer exibir as tarefas!\n");
                exibir_tarefas(l);
                break;

        }

    }

    return 1;
}