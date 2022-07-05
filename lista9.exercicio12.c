#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Redefine do tipo struct como livro */
typedef struct livro {
    int ano;
    char titulo[100];
    char autor[100];
    int nVolume; // Número de exemplares de um dado livro.
    float preco;
} Livro; //Dá um apelido para o tipo livro para encurtar o comando na declaração

typedef struct biblioteca {
    Livro **v;  // Armazena a informação de n livros !!
    int nLivros; // Número de livros existentes na biblioteca.
} Biblioteca;

/* 
(A) Criar uma função Livro * fillLivro() que preenche os campos da estrutura Livro e retorna
esse novo livro. 
*/
Livro* fillLivro()
{   
    int i;
    Livro *cadastro = (Livro*) malloc(sizeof(Livro));
    if(cadastro == NULL)
    {
        exit(1);
    };
    printf("\n\n -----------------Cadastro dos livros----------------- \n\n");

    printf("\n Título do livro............: ");
    //fflush(stdin); //limpa o buffer do teclado
    scanf("%s",cadastro->titulo);

    printf("\n Ano de publicação do livro............: ");
    scanf("%d", &(cadastro->ano));

    printf("\n Autor do livro............: ");
    //fflush(stdin);
    scanf("%s",cadastro->titulo);

    printf("\n Preco do livro............: ");
    scanf("%f", &(cadastro->preco));
    
    printf("\n Numero de exemplares do livro............: ");
    scanf("%d", &(cadastro->nVolume));
        
    return cadastro;   
};

/*
(B) Criar uma função Biblioteca * fillBiblioteca(int numLivros) que preenche os campos da
estrutura do tipo Biblioteca realizando chamadas a função fillLivro em um número de vezes igual
ao número contido na variável numLivros.
*/
Biblioteca* fillBiblioteca(int numLivros)
{
    int i;
    Livro **v = (Livro**) malloc(numLivros * sizeof(Livro*));
    Biblioteca *biblio = (Biblioteca*) malloc(sizeof(Biblioteca));
    if(biblio == NULL)
    {
        exit(1);
    }    
    for(i=0; i < numLivros; i++)
    {
        v[i] = fillLivro();
    } 

    biblio->v=v;
    biblio->nLivros = numLivros;

    return biblio;          
};
/*
C) Criar uma função void valorBiblioteca(Biblioteca * b1, int numLivros) que fornece o
montante gasto para se comprar todos os exemplares existentes na biblioteca.
*/
void valorBiblioteca(Biblioteca *b1, int numLivros)
{
    float valor = 0;
    for (int i = 0; i < numLivros; i++)
    {
        valor += b1->v[i]->preco;
    }
    
    printf("O valor total dos livros na Biblioteca é: %f", valor);
}
/*
(D) Criar uma função Livro * maiorBiblioteca(Biblioteca * b1, int numLivros) que retorna o livro
com maior número de exemplares.
*/
Livro* maiorBiblioteca(Biblioteca *b1, int numLivros)
{    
    //int livros = sizeof(biblioteca->v);
    int i, j;
    Livro* maior;    
    for(i=0; i<numLivros; i++)
    {
        for(j=0; j<numLivros; i++)
        {
            if((b1->v[i]->nVolume) > (b1->v[j]->nVolume)) 
            maior = b1->v[i];
        }
    }
    return maior;    
}

/*
    E)Criar um programa que ilustra o funcionamento das funções anteriores.
*/
void main()
{   
    int numLivros;
    printf("Informe a quantidade de livros que deseja cadastrar\n");
    scanf("%d", &numLivros);
    printf("inciando preenchimento da biblioteca\n");
    Biblioteca* b1 = fillBiblioteca(numLivros);
    valorBiblioteca(b1, numLivros);
    Livro* livrosMaisExemplares = maiorBiblioteca(b1, numLivros);
}