#include <stdio.h>
#include <stdlib.h>

typedef struct data {
    int dia;
    int mes;
    char nomeMes[12];
} Data;

void main()
{
    Data aniversarios[3] = {{5,1,"JANEIRO"},{4,2,"FEVEREIRO"},{10,3,"MAIO"}};
    int a;
    Data *p_dt;
    p_dt=&aniversarios[2];
    strcpy(p_dt->nomeMes, "MARÇO");
    Data *p_dt2;
    p_dt2 = (Data *) malloc(sizeof(Data));
    p_dt2 = &aniversarios[0];

    printf("a:  Primeiro e preciso declarar p_dt2 como ponteiro para depois alocar dinamicamente\n");
    printf("b: 5");
}
