#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    for(int i = 0; i < 10;i++){
        char name[20];
        printf("Digite o nome: ");
        scanf("%s",&name);

        FILE *f = fopen(name,"w");
        fprintf(f,"Texo do arquivo",name);
        fclose(f);
    }
    return 0;
}