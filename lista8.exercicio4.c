#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char mat[100][100];
    int cont=0,i,j,tam=0,total=0;
    int *caracter;
    float varianca=0,soma=0,media=0;
    char fim[]="fim";
    printf("Preencha os nomes, digite o fim caso queira parar: ");
    fflush(stdin);
    for(i=0;i<100;i++){
        gets(mat[i]);
        if(strcmp(mat[i],fim)==0){
            tam=i;
            break;
        }
    }
    caracter=(int*)malloc(tam*sizeof(int));
    if(caracter==NULL){
        printf("error");
        exit(1);
    }
    for(i=0;i<tam;i++){
        for(j=0;j<strlen(mat[i]);j++){
            cont++;
        }
        caracter[i]=cont;
        total=total+cont;
        cont=0;
    }
    media=total/tam;
    for(i=0;i<tam;i++){
        soma=soma+((caracter[i]-media)*(caracter[i]-media));
    }
    varianca=soma/tam;
    printf("a media de caracteres: %.2f",media);
    printf("\na varianca de caracteres: %.2f",varianca);
    free(caracter);
    return 0;
}
