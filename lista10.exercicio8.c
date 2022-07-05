#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _ALUNO
{
    char nome[81];
    float nota1, nota2;
} ALUNO;

ALUNO *ler_aluno()
{
    ALUNO *aluno = (ALUNO *)malloc(sizeof(ALUNO));
    if (!aluno)
    {
        exit(1);
    }
    fgets(aluno->nome, 80, stdin);

    scanf("%f %f", &aluno->nota1, &aluno->nota2);

    return aluno;
}

void exibir_aluno(ALUNO *aluno)
{
    printf("%s %f %f\n", aluno->nome, aluno->nota1, aluno->nota2);
}

FILE *abrir_arquivo(char *nome)
{
    return fopen(nome, "rb+");
}

void incluir(FILE *arquivo, ALUNO *aluno)
{
    fseek(arquivo, 0, SEEK_END);
    fwrite(aluno, sizeof(ALUNO), 1, arquivo);
}

void alterar(FILE *arquivo, ALUNO *aluno)
{
    ALUNO atual;

    fseek(arquivo, 0, SEEK_SET);
    while (1)
    {
        int posicao_atual = ftell(arquivo);
        if (!fread(&atual, sizeof(ALUNO), 1, arquivo))
        {
            continue;
        }

        if (ferror(arquivo) || feof(arquivo))
            break;

        if (!strcmp(atual.nome, aluno->nome) && atual.nome[0] != '\0')
        {
            fseek(arquivo, posicao_atual, SEEK_SET);
            fwrite(aluno, sizeof(ALUNO), 1, arquivo);
        }
    }
}

ALUNO *consultar(FILE *arquivo, char *nome)
{
    ALUNO *atual = (ALUNO *)malloc(sizeof(ALUNO));

    fseek(arquivo, 0, SEEK_SET);
    while (1)
    {
        if (!fread(atual, sizeof(ALUNO), 1, arquivo))
        {
            continue;
        }

        if (ferror(arquivo) || feof(arquivo))
            break;

        if (!strcmp(atual->nome, nome) && atual->nome[0] != '\0')
        {
            return atual;
        }
    }

    free(atual);
    return NULL;
}

void excluir(FILE *arquivo, char *nome)
{
    ALUNO atual;

    fseek(arquivo, 0, SEEK_SET);
    while (1)
    {
        int posicao_atual = ftell(arquivo);
        if (!fread(&atual, sizeof(ALUNO), 1, arquivo))
        {
            continue;
        }

        if (ferror(arquivo) || feof(arquivo))
            break;

        if (!strcmp(atual.nome, nome) && atual.nome[0] != '\0')
        {
            atual.nome[0] = '\0';
            fseek(arquivo, posicao_atual, SEEK_SET);
            fwrite(&atual, sizeof(ALUNO), 1, arquivo);
        }
    }
}

void exibir_todos(FILE *arquivo)
{
    ALUNO aluno;

    printf("Alunos:\n");

    fseek(arquivo, 0, SEEK_SET);
    while (1)
    {
        if (!fread(&aluno, sizeof(ALUNO), 1, arquivo))
        {
            continue;
        }

        if (ferror(arquivo) || feof(arquivo))
            break;

        if (aluno.nome[0] != '\0')
        {
            exibir_aluno(&aluno);
        }
    }
}

float media(ALUNO *aluno)
{
    return (aluno->nota1 + aluno->nota2) / 2;
}

void exibir_aprovados(FILE *arquivo)
{
    ALUNO aluno;

    printf("Aprovados:\n");

    fseek(arquivo, 0, SEEK_SET);
    while (1)
    {
        if (!fread(&aluno, sizeof(ALUNO), 1, arquivo))
        {
            continue;
        }
        if (ferror(arquivo) || feof(arquivo))
            break;

        if (media(&aluno) >= 6.0)
        {
            printf("Aluno %s foi aprovado!\n", aluno.nome);
        }
    }
}

void exibir_menu()
{
    printf("0 - sair\n");
    printf("1 - exibir todos\n");
    printf("2 - inserir\n");
    printf("3 - consultar pelo nome\n");
    printf("4 - alterar\n");
    printf("5 - excluir\n");
    printf("6 - exibir aprovados\n");
}

char *obter_nome()
{
    printf("digite o nome: ");
    fflush(stdout);
    char *nome = malloc(81 * sizeof(char));
    scanf(" %[80\n]", nome);
    return nome;
}

void main()
{
    FILE *arquivo = abrir_arquivo("alunos.bin");

    while (1)
    {
        ALUNO *aluno;
        char *nome;
        int comando;

        exibir_menu();

        scanf("%d\n", &comando);
        fflush(stdin);

        switch (comando)
        {
        case 0:
            // BYE BYE
            fclose(arquivo);
            return;
        case 1:
            printf("prestes a exibir todos\n");
            exibir_todos(arquivo);
            break;
        case 2:
            aluno = ler_aluno();

            incluir(arquivo, aluno);

            free(aluno);
            break;
        case 3:
            nome = obter_nome();
            aluno = consultar(arquivo, nome);
            if (!aluno)
            {
                printf("Aluno não encontrado!\n");
            }
            else
            {
                exibir_aluno(aluno);
            }

            free(aluno);
            free(nome);
            break;
        case 4:
            aluno = ler_aluno();
            alterar(arquivo, aluno);
            free(aluno);
            break;
        case 5:
            nome = obter_nome();

            excluir(arquivo, nome);

            free(nome);
            break;
        case 6:
            exibir_aprovados(arquivo);
            break;
        }
    }
}