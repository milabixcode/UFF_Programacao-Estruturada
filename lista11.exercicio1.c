#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elemento {
    float info; /* Valor real armazenado */
    struct elemento *prox; /* Ponteiro para o próximo elemento */
};
typedef struct elemento Elemento;

Elemento *lista_insere(Elemento *lst, float info){
    Elemento *novo = (Elemento*) malloc(sizeof(Elemento));
    if(novo ==NULL){exit(1);}
    novo->info = info;
    novo->prox = lst;
    return novo;
}

Elemento* filtra(Elemento *lst, float min, float max){
    Elemento* ant = NULL;
    Elemento *p = lst;
    while(p!= NULL && p->info >= min && p->info<=max){
        ant = p;
        p = p->prox;
    }
    if(p== NULL){
        return lst;
    }
    if(ant == NULL){
        lst = p->prox;
    } else{
        ant->prox = p->prox;
    }
    lst = filtra(lst,min,max);
    free(p);
    return lst;
}

void imprime(Elemento *lst){
    Elemento *p;
    for(p=lst;p!=NULL;p = p->prox){
        printf("%.1f\n", p->info);
    }
}

int main(){
    Elemento* lista =   NULL;
    float min, max;

    lista = lista_insere(lista, 10);
    lista = lista_insere(lista, 20);
    lista = lista_insere(lista, 30);
    printf("Valores na lista: \n");
    imprime(lista);

    printf("Escreva o valor minimo na lista: ");
    scanf("%f", &min);

    printf("Escreva o valor maximo na lista: ");
    scanf("%f", &max);

    lista = filtra(lista,min,max);

    printf("Lista apos possivel remocao:\n");
    imprime(lista);
    return 0;
}