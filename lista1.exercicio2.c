#include<stdio.h>
int primo(int n){
   int d;
   if(n <= 1) printf("NUMERO NAO PRIMO");
   
   for (d = 2; d*d <= n; d++) {
     if (n%d == 0)   // d divide n
       return printf("NUMERO NAO PRIMO");
    }
    
   return printf("NUMERO PRIMO");
}
int main(){
	
	int num#include<stdio.h>
int primo(int n){
   int d;
   if(n <= 1) printf("NUMERO NAO PRIMO");
   
   for (d = 2; d*d <= n; d++) {
     if (n%d == 0)   // d divide n
       return printf("NUMERO NAO PRIMO");
    }
    
   return printf("NUMERO PRIMO");
}
int main(){
	
	int num,i;
	
	printf("Digite um numero: ");
	scanf("%d",&num);
	
	primo(num);
	
	return 0;
}
