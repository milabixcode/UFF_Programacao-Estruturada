#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>

/*
11. Criar um tipo Aluno e um tipo Materia tal como dado abaixo:

typedef struct Aluno {
    int matricula;
    float *vNotas; // Armazena as 5 notas de um aluno ao longo de um ano.
    char nome[100];
}Aluno;

typedef struct Matéria {
    Aluno *V; // Armazena a informação de n alunos !!
    float media[5]; // Armazena as 5 médias do ano.
    int nAlunos // Número de alunos matriculados no curso.
}Materia;

(A) Criar uma função Aluno* fillAluno() que preenche os campos da estrutura do tipo Aluno com
dados fornecidos pelo usuário.

(B) Criar uma função Materia * fillMateria(int numAlunos) que preenche os campos da estrutura
do tipo Materia realizando chamadas a função fillAluno em um número de vezes igual ao número
contido na variável numAlunos.

(C) Criar uma função void mediaMateria(Materia *m1) que fornece a média de cada prova do
ano para os alunos contidos na variável m1 e assim preenche o campo media de m1.

(D) Criar uma função void mostraMateria(Materia *m1) que mostra as informações dos alunos
contidas na variável m1.

(E) Criar um programa que ilustra o funcionamento das funções anteriores.
*/

typedef struct Aluno {
    int matricula;
    float *vNotas; // Armazena as 5 notas de um aluno ao longo de um ano.
    char nome[100];
}Aluno;

typedef struct Materia {
    Aluno *V; // Armazena a informação de n alunos !!
    float media[5]; // Armazena as 5 médias do ano.
    int nAlunos; // Número de alunos matriculados no curso.
}Materia;

//(A) Criar uma função Aluno* fillAluno() que preenche os campos da estrutura do tipo Aluno com
//dados fornecidos pelo usuário.

Aluno *fillAluno(){
    Aluno *new;
    float *notas;

    notas = (float*) malloc(5 * sizeof(float));
    if(notas == NULL)exit(1);


    printf("\nInforme o nome do aluno: ");
    scanf("%s", &new->nome);

    printf("Informe a matricula do aluno: ");
    scanf("%s", &new->matricula);

    printf("Informe as notas do aluno %s: \n", new->nome);
    
    for(int i = 0; i < 5; i++){
        printf("Digite a %d ° nota do aluno: ", i+1);
        scanf("%f", &notas[i]);
    }
    
    new->vNotas = notas;
    
    return new;
}

/*
(C) Criar uma função void mediaMateria(Materia *m1) que fornece a média de cada prova do
ano para os alunos contidos na variável m1 e assim preenche o campo media de m1.
*/

void mediaMateria(Materia *m1){
    float medias[5];
    float sum;

    for(int i = 0; i < m1->nAlunos; i++){
        for(int k = 0; k < m1->nAlunos; k++){
            sum += m1->V[k].vNotas[i];
        }
        sum /= m1->nAlunos;
        m1->media[i] = sum;
    }
}

/*
(B) Criar uma função Materia * fillMateria(int numAlunos) que preenche os campos da estrutura
do tipo Materia realizando chamadas a função fillAluno em um número de vezes igual ao número
contido na variável numAlunos.
*/
Materia *fillMateria(int numAlunos){
    Materia *newM;
    Aluno *newA;

    for(int i = 0; i < numAlunos; i++){
        newA = fillAluno();
        newM->V = newA;        
    }

    newM->nAlunos = numAlunos;

    mediaMateria(newM);
}

/*
(D) Criar uma função void mostraMateria(Materia *m1) que mostra as informações dos alunos
contidas na variável m1.
*/
void mostraMateria(Materia *m1){
    printf("\nNUMERO DE ALUNOS MATRICULADOS: %d", m1->nAlunos);
    for(int i = 0; i < m1->nAlunos; i++){
        printf("%dº MEDIA GERAL: %d", i, m1->media[i]);
    }

    for(int i = 0; i < m1->nAlunos; i++){
        printf("\n============================= DADOS =============================\n");
        printf("NOME: %s\n", m1->V[i]);
        printf("MATRICULA: %s\n", m1->V[i].matricula);
        printf("\n============================= NOTAS =============================\n");
        for(int j = 0; j < 5; j++){
            printf("%dº NOTA: ", m1->V[i].vNotas[i]);
        }
    }
}

/*
(E) Criar um programa que ilustra o funcionamento das funções anteriores.
*/
void menu(Materia *lst, int op,int numAlunos){
    switch (op){
    case 1:
        lst = fillMateria(numAlunos);
        break;
    case 2:
        mostraMateria(lst);
        break;
    case -1:
        exit(1);
        break;
    default:
        printf("ERROR!");
        break;
    }
}

int main(){
    setlocale(LC_ALL,"portuguese");
    int op, numAlunos;

    Materia *lst = (Materia*) malloc(sizeof(Materia));
    if(!lst)exit(1);

    printf("Digite a quanidade de alunos: ");
    scanf("%d", &numAlunos);

    //system("cls");
    do{
        
        printf("Select the option: \n");
        printf("PREENCHER PRIMEIRO\n");
        printf("[1] - FILL\n");
        printf("[2] - PRINT\n");
        printf("[-1] - Exit\n");
        printf("Enter a option: ");
        scanf("%d", &op);

        menu(lst, op, numAlunos);
    } while (op != -1);

    free(lst);

    return 0;
}