#include <stdio.h>

int total_de_notas(int valor);

int main(void){
    int v;

    printf("Digite o valor: ");
    scanf("%d", &v);
    printf("Total de notas = %d", total_de_notas(v));
}

int total_de_notas(int valor){
    int num_n#include <stdio.h>

int total_de_notas(int valor);

int main(void){
    int v;

    printf("Digite o valor: ");
    scanf("%d", &v);
    printf("Total de notas = %d", total_de_notas(v));
}

int total_de_notas(int valor){
    int num_notas=0;
    
    num_notas += valor/100;
    valor = valor%100;
    num_notas += valor/50;
    valor = valor%50;
    num_notas += valor/20;
    valor = valor%20;
    num_notas += valor/10;
    valor = valor%10;
    num_notas += valor/5;
    valor = valor%5;
    num_notas += valor/2;
    valor = valor%2;
    num_notas += valor/1;
    valor = valor%1;
    
    return num_notas;
}