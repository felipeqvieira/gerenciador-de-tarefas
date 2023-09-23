#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"
#include "lista.h"
#include "adiciona.h"
#include "conclui.h"
#include "desfaz.h"
#include "remove.h"
#include "exibe.h"
#include "ler.h"
#include "atualiza.h"

int main(int argc, char **argv){

    lista_t *l = cria_lista();

    if(l == NULL){
        printf("Erro ao criar a lista!\n");
        return 0;
    }

    int saida = -1;
    int option = -1;
    int n = 0;

    int tam = sizeof(argv[1]);

    char *nome_arquivo = malloc(sizeof(tam));

    strcpy(nome_arquivo, argv[1]);

    FILE *arquivo_tarefas = fopen(nome_arquivo, "r");

    if (! arquivo_tarefas){
        printf("Gerenciador inexistente. Criando um novo...\n");
        arquivo_tarefas = fopen(nome_arquivo, "w");
    }
    else{
        ler_arquivo(arquivo_tarefas, l);
    }

    printf("\nSeja bem vindo ao gerenciador de tarefas!\n");

    while(saida != 0){
        
        printf("\n\n\nMostrar menu?\n");
        printf("1. Sim  2. Sair\n");
        
        scanf("%d", &n);
        
        if (n == 1)
            menu();
        else 
            return 1;


        scanf("%d", &option);

        system("clear");

        switch(option){

            case 0:
                saida = 0;
                break;
        
            case 1:
                //adiciona
                n = tamanho_lista(l);

                printf("Escreva a tarefa: \n");
                
                while (tamanho_lista(l) != n+1){
                    if (adiciona_tarefas(l) != 1)
                        fprintf(stderr, "Erro ao adicionar tarefa");
                }
                break;
            
            case 2:
                //remove
                printf("Digite o numero da tarefa:\n");
                
                if(! scanf("%d", &n))
                    printf("Erro ao inserir numero da tarefa\n");

                remove_lista(l, n);
                break;
            
            case 3:
                //concluida 
                printf("Digite o numero da tarefa:\n");
                
                if(! scanf("%d", &n))
                    printf("Erro ao inserir numero da tarefa\n");
            
                conclui_tarefa(l, n);
                break;

            case 4:
                //desfazer
                printf("Digite o numero da tarefa:\n");
                
                if(! scanf("%d", &n))
                    printf("Erro ao inserir numero da tarefa\n");
            
                desfaz_tarefa(l, n);
                break;

            case 5:
                //exibir 
                exibir_tarefas(l);
                break;

            case 6:
                atualiza(l);
                break;

        }

    }

    atualiza(l);

    destroi_lista(l);

    free(nome_arquivo);

    return 1;
}