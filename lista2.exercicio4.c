#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int charint(char chute){
	int chut=0;
	chut=(int)chute;
	return chut;
}
int main(){
    int letra,i,chut=1;
    char chute, let;
    srand(time(NULL));
    letra=97+rand()%25;
    
    while (chut!=letra){
    	chut=0;
        printf("digite a le#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int charint(char chute){
	int chut=0;
	chut=(int)chute;
	return chut;
}
int main(){
    int letra,i,chut=1;
    char chute, let;
    srand(time(NULL));
    letra=97+rand()%25;
    
    while (chut!=letra){
    	chut=0;
        printf("digite a letra do chute: ");
        scanf("%c",&chute);
        chut=charint(chute);
        i=i+1;
        if(chut>=97 and chut<=122){
        	if (chut<letra){
        		printf("Maior\n");
        	}
        	else if(chut>letra){
            	printf("Menor\n%");
        	}
        	else{
           		printf("Voce acertou %d tentivas",i);
        	}
    	}
    }
        
    return 0;
}
