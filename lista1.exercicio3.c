#include <stdio.h>

int main(void){
    char op;
    float a, b;

    printf("Operacao: ");
    scanf("%c", &op);
    printf("a = ");
    scanf("%f", &a);
    printf("b = ");
    scanf("%f", &b);

    printf("%.2f %c %.2f = ", a, op, b);
    switch(op){
        case '+':
            printf("%.2f", a+b);
            break;
        case '-':
            printf#include <stdio.h>

int main(void){
    char op;
    float a, b;

    printf("Operacao: ");
    scanf("%c", &op);
    printf("a = ");
    scanf("%f", &a);
    printf("b = ");
    scanf("%f", &b);

    printf("%.2f %c %.2f = ", a, op, b);
    switch(op){
        case '+':
            printf("%.2f", a+b);
            break;
        case '-':
            printf("%.2f", a-b);
            break;
        case '/':
            printf("%.2f", a/b);
            break;
        case '*':
            printf("%.2f", a*b);
            break;
    }

    return 0;
}