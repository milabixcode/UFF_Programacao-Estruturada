#include <stdio.h>
#include <math.h>

int main(void){
    float a, b, c, delta, x1, x2;

    printf("Digite os coeficientes da equacao a*x^2 + b*x + c = 0");
    printf("\n a = ");
    scanf("%f", &a);
    printf(" b = ");
    scanf("%f", &b);
    printf(" c = ");
    scanf("%f", &c);

    delta = b*b - 4*a*c;
    if(delta == 0){// Raizes reais e iguais
        x1 = (-b + sqrt(delta))/(2*a);
        printf("Raizes x1 = x2 = %.2f", x1);
    }
    else if (delta > 0){// Raizes reais e distintas
        x1 = (-b + sqrt(delta))/(2*a);
        x2 = (-b - sqrt(delta))/(2*a);
        printf("Raizes x1 = %.2f e x2 = %.2f", x1, x2);
    }
    else#include <stdio.h>
#include <math.h>

int main(void){
    float a, b, c, delta, x1, x2;

    printf("Digite os coeficientes da equacao a*x^2 + b*x + c = 0");
    printf("\n a = ");
    scanf("%f", &a);
    printf(" b = ");
    scanf("%f", &b);
    printf(" c = ");
    scanf("%f", &c);

    delta = b*b - 4*a*c;
    if(delta == 0){// Raizes reais e iguais
        x1 = (-b + sqrt(delta))/(2*a);
        printf("Raizes x1 = x2 = %.2f", x1);
    }
    else if (delta > 0){// Raizes reais e distintas
        x1 = (-b + sqrt(delta))/(2*a);
        x2 = (-b - sqrt(delta))/(2*a);
        printf("Raizes x1 = %.2f e x2 = %.2f", x1, x2);
    }
    else{// Sem raizes reais
        printf("Sem raizes reais");
    }

    return 0;
}