#include <conio.h>
#include <stdio.h>

void main(){
    float vet[5] = {1.1,2.2,3.3,4.4,5.5};
    float *f;
    int i;
    f = vet;
    printf("contador/valor/valor/endereco/endereco");
    for(i = 0 ; i <= 4 ; i++){
        printf("\ni = %d",i);
        printf(" vet[%d] = %.1f",i, vet[i]); /* Imprime a posicao i e o seu conteudo no vetor */
        printf(" *(f + %d) = %.1f",i, *(f+i)); /*  Imprime a posicao i e o seu conteudo no vetor f */
        printf(" &vet[%d] = %X",i, &vet[i]); /* Imprime a posicao i e o seu endereco no vetor */
        printf(" (f + %d) = %X",i, f+i); /* Imprime a posicao i e o seu endereco no vetor */
    }
 return 0;
}
                                       #include <conio.h>
#include <stdio.h>

void main(){
    float vet[5] = {1.1,2.2,3.3,4.4,5.5};
    float *f;
    int i;
    f = vet;
    printf("contador/valor/valor/endereco/endereco");
    for(i = 0 ; i <= 4 ; i++){
        printf("\ni = %d",i);
        printf(" vet[%d] = %.1f",i, vet[i]); /* Imprime a posicao i e o seu conteudo no vetor */
        printf(" *(f + %d) = %.1f",i, *(f+i)); /*  Imprime a posicao i e o seu conteudo no vetor f */
        printf(" &vet[%d] = %X",i, &vet[i]); /* Imprime a posicao i e o seu endereco no vetor */
        printf(" (f + %d) = %X",i, f+i); /* Imprime a posicao i e o seu endereco no vetor */
    }
 return 0;
}
