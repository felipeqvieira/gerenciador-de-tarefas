/*          LISTA           */

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


/* Cria uma lista vazia */
lista_t * cria_lista ();

/* Destroi a lista, sempre retorna NULL */
lista_t * destroi_lista (lista_t *l);

/*Adiciona na lista em ordem */
int adiciona_ordem_lista (lista_t *l, char* elemento);

/* verifica se ha um inteiro na lista */
int busca_string (lista_t *l, char* c);

/* Informa o tamanho da lista */
int tamanho_lista (lista_t *l);

/* Printa os elementos da lista*/
void printa_lista(lista_t *l);