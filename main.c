#include <stdio.h>

#define STRING_SIZE 1024

int main(int argc, char **argv){

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

        scanf("%d", option);

        switch(option){

            case '0':
                saida = 0;
                break;
        
            case '1':
                //adiciona
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
                break;

        }

    }

}