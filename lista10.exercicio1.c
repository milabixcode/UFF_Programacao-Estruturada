Joao da Silva
15,0 160
Manuel Santos
15,0 80
Fulana de Tal
23,5 40#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct funcionario {
    char nome[81]; /* nome do funcionário */
    float valor_hora; /* valor da hora de trabalho em Reais */
    int horas_mes; /* horas trabalhadas em um mês */
};
typedef struct funcionario Funcionario;


void carrega(int n, Funcionario **vet, char *arquivo);
void imprime();


int main(){
    setlocale(LC_ALL, "Portuguese");
    int n = 1;
    char name[30], c;

    printf("Nome: ");
    scanf("%30s", &name);

    FILE *f_aux = fopen(name, "r");
    if(!f_aux)exit(1);

        
    while ((c = fgetc(f_aux)) != EOF)
    {
        //printf("%c",c);
        if(c == '\n')n++;
    }
    printf("\nLINHAS = %d\n\n",n);

    Funcionario **vet = (Funcionario**) malloc((n/2) * sizeof(Funcionario*));
    if(!vet)exit(1);

    carrega((n/2), vet, &name);


    free(vet);
    fclose(f_aux);
    return 0;
}

void carrega(int n, Funcionario **vet, char *arquivo){
    int i = 1, horas = 0, pos = 0;
    float valor = 0;
    char info[121], nome[80];

    FILE *f = fopen(arquivo, "rt");
    if(!f)exit(1);

    while((fgets(info, 121, f) != NULL)){
        Funcionario *tmp = (Funcionario*) malloc(sizeof(Funcionario));
        if(!tmp)exit(1);

        //printf("Linha: %s\n", info);
        if(i%2 != 0){
            strcpy(nome, info);
            
        }else{
            int aux = sscanf(info,"%f %d", &valor, &horas);
        }

        if(i%2 == 0){

            strcpy(tmp->nome, nome);
            tmp->horas_mes = horas;
            tmp->valor_hora = valor;

            vet[pos] = tmp;
            pos++;
            
            printf("%s", tmp->nome);
            printf("%.1f e %d\n\n", tmp->valor_hora, tmp->horas_mes);
            printf("SUCESSO!\n");
        }
        i++;
    }
    fclose(f);
}