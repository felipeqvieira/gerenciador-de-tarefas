#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "remove.h"
#include "atualiza.h"

void atualiza(lista_t *l, char *nome_arquivo) {

    puts(nome_arquivo);
    
    FILE *arquivo_saida = fopen(nome_arquivo, "w");

    if (arquivo_saida == NULL) {
        perror("Erro ao abrir o arquivo de saída");
        exit(1);
    }

    nodo_lista_t *aux = l->Primeiro;
    int i = 1;


    while (aux != NULL) {
        if (aux->concluido == 1) {
            nodo_lista_t *proximo = aux->prox;
            remove_lista(l, i);
            aux = proximo;
            i--;
        } else {
            // Use fprintf para escrever a frase inteira em uma nova linha
            fprintf(arquivo_saida, "%s\n", aux->dado);
            aux = aux->prox;
        }
        i++;
    }

    // Feche o arquivo após a escrita
    fclose(arquivo_saida);
}