#include <stdio.h>
#include "lista.h"
#include "adiciona.h"
#include "conclui.h"
#include "desfaz.h"
#include "remove.h"
#include "exibe.h"

#define STRING_SIZE 1024

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
        ler_arquivo(arquivo_tarefas);
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

        scanf("%d", option);

        switch(option){

            case '0':
                saida = 0;
                break;
        
            case '1':
                //adiciona
                adiciona_tarefas(arquivo_tarefas, l);
                break;
            
            case '2':
                //remove
                break;
            
            case '3':
                //concluida 
                break;

            case '4':
                //desfazer
                break;

            case '5':
                //exibir 
                exibir_tarefas(l);
                break;

        }

    }

    return 1;
}