#define MAX 4
#define MAXNOME 31
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void atribui(char **nomes, int indice, char *nome){
      strcpy(nomes[indice], nome);
}

char * get_sobrenome(char *nome){
    char *sobrenome;
    int tamanho=0, i, index=0;
    sobrenome = (char *) malloc(MAXNOME*sizeof(char ));
    for ( i=strlen(nome) ;nome[i]!= ' ' ; i--) {
      tamanho++;
    }
    tamanho = strlen(nome) - tamanho + 1;
    for ( i=tamanho ; nome[i]!='\0' ; i++) {
        sobrenome[index] = nome[i];
        index++;
    }
    return sobrenome;
}

main()
{
    int i;
    char **nomes;
    char *sobrenome;
    nomes = (char **) malloc(MAX*sizeof(char *));
    for ( i=0 ; i<MAX ; i++) {
        nomes[i] = (char *) malloc(sizeof(char)*MAXNOME);
    }
    atribui(nomes,0,"Fulano Silva");
    atribui(nomes,1,"Maria do Carmo");
    atribui(nomes,2,"Beltrano Belmonte");
    atribui(nomes,3,"Pedro dos Santos");
    printf("Segundo printf:\n");
    for (i=0 ; i<MAX ; i++) {
    sobrenome = get_sobrenome(nomes[i]);
    printf("\n%s ", sobrenome);
    printf(" %d",strlen(sobrenome)>5?i:0); // 2o printf
    }
    printf("\n");
    printf("\nTerceiro printf:");
    printf("\n%c", nomes[0][3]); // 3o printf
}
