/*
Escrever um programa que declare, inicialize e imprima um vetor de 10 inteiros. O
vetor deve conter os 10 primeiros múltiplos de 5. A inicialização do vetor e a sua
impressão devem ser feitas por funções. Generalize para um vetor de n elementos.
*/

#include <stdio.h>
#include <stdlib.h>

int inicializaVetor(int *v, int n){
    int i;
    for (i=1; i<=n; i++){
        v[i-1] = 5*i;
    }
}

int imprimeVetor(int *v, int n){
    int i;
    for(i=1; i<=n; i++){
        printf("%d", v[i]);
    }
}

void main(){
    
    int tamanho = 10;
    int *vetor = (int *) malloc (tamanho*sizeof(int));
    if(vetor == NULL){
        exit(1);
    }
    inicializaVetor(vetor, tamanho);
    imprimeVetor(vetor, tamanho);

    free(vetor);
}