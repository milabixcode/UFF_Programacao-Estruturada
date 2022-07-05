#include <stdio.h>
#include <stdlib.h>
void criptografia(char *fraseNova, int tamanhoNovo)
{
    int i;

    for (i=0;i<tamanhoNovo;i+=5)
    {
        fraseNova[i] += 1;
    }
    for (i=1;i<tamanhoNovo;i+=5)
    {
        fraseNova[i] += 2;
    }
    for (i=2;i<tamanhoNovo;i+=5)
    {
        fraseNova[i] += 3;
    }
    for (i=3;i<tamanhoNovo;i+=5)
    {
        fraseNova[i] += 4;
    }
    for (i=4;i<tamanhoNovo;i+=5)
    {
        fraseNova[i] += 5;
    }

    printf("%s", fraseNova);
}
void main()
{
    int i, cont=0;
    char frase[80];
    printf("Digite uma frase de ate 80 characteres: ");
    gets(frase);
    int tam = strlen(frase);
    char *fraseSemEspaco =(char *) malloc(tam*sizeof(char));
    if (fraseSemEspaco == NULL)
    {
        exit(1);
    }

    for (i=0;i<tam;i++)
    {
        if (frase[i] != ' ')
        {
            fraseSemEspaco[cont] = frase[i];
            cont++;
        }
    }
    fraseSemEspaco[cont] = '\0';
    int tamNovo = strlen(fraseSemEspaco);

    criptografia(fraseSemEspaco,tamNovo);
}
