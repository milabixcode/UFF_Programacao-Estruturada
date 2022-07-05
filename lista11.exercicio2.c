#include <stdio.h>
#include <stdlib.h>

struct elemento
{
    float info; /* Valor real armazenado */
    struct elemento *prox; /* Ponteiro para o próximo elemento */
};
typedef struct elemento Elemento;

void preenche(Elemento *lst, int indice)
{
    Elemento* novo = (Elemento*) malloc(sizeof(Elemento));
    printf("Digite o elemento %d do vetor: ",indice+1);
    scanf(" %f", &novo->info);
    lst->info = novo->info;
    lst->prox = novo->prox;
}

Elemento* copia(Elemento* lst)
{
    Elemento *copia = lst;
    return copia;
}

void main()
{
    int tam;
    int i;
    printf("Digite o tamanho da lista: ");
    scanf(" %d", &tam);

    Elemento *lista = (Elemento*) malloc(tam*sizeof(Elemento));
    if (lista==NULL)
    {
        printf("Error!");
        exit(1);
    }

    for (i=0;i<tam;i++)
    {
        preenche(&lista[i], i);
    }

    Elemento *lstCopiada= copia(lista);

    for (i=0;i<tam;i++)
    {
        printf("\nInfo %d do vetor copiado: ", i+1);
        printf(" %f", lstCopiada[i].info);
    }

    free(lista);
    free(lstCopiada);
}
