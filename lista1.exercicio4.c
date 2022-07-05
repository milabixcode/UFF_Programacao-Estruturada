#include<stdio.h>
float media(float med){
	return med/3;
}
int main(){
	float med, retorno;
	float total=0;
	int i;
	for(i=0;i<3;i++){
		scanf("%f",&med);
		if(med>10){
			printf("nota errada, nota entre 0 a 10!\nDigite de novo.\n");
			i--;
		}
		else if(med<10){
		total=total+med;
		med=0;
	}
	}
	retorno=media(total);
	if(retorno>6)
	    printf("Aprovado!\nSua nota eh: %.2f", retorno);
	else if(retorno>4 && retorno<6)
	    printf("Voce esta de VS!\nSua nota eh: %.2f", retorno);
	else
	    printf("Reprovado!\nSua nota eh: %.2f", retorno);
	return 0;
}#include<stdio.h>
float media(float med){
	return med/3;
}
int main(){
	float med, retorno;
	float total=0;
	int i;
	for(i=0;i<3;i++){
		scanf("%f",&med);
		if(med>10){
			printf("nota errada, nota entre 0 a 10!\nDigite de novo.\n");
			i--;
		}
		else if(med<10){
		total=total+med;
		med=0;
	}
	}
	retorno=media(total);
	if(retorno>6)
	    printf("Aprovado!\nSua nota eh: %.2f", retorno);
	else if(retorno>4 && retorno<6)
	    printf("Voce esta de VS!\nSua nota eh: %.2f", retorno);
	else
	    printf("Reprovado!\nSua nota eh: %.2f", retorno);
	return 0;
}
