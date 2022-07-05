#include <stdio.h>;
#include <stdlib.h>;

int compara_float(const void *a, const void *b);

void ordena(float *vetor, int qtd)
{
    // qsort(vetor, qtd, sizeof(float), compara_float);

    // selection
    for (int i = 0; i < qtd; i++)
    {
        for (int j = i + 1; j < qtd; j++)
        {
            if (vetor[i] > vetor[j])
            {
                float tmp = vetor[j];
                vetor[j] = vetor[i];
                vetor[i] = tmp;
            }
        }
    }
}

void main()
{
    FILE *arquivo = fopen("numeros.txt", "r");
    if (!arquivo)
    {
        printf("n consegui abrir o arquivo!!!!!\n");
        exit(1);
    }

    int qtd = 0;
    int capacidade = 1000;
    float *vetor = malloc(capacidade * sizeof(float));

    float valor;
    while (!feof(arquivo))
    {
        fscanf(arquivo, "%f", &valor);
        vetor[qtd] = valor;
        qtd++;

        if (qtd == capacidade)
        {
            capacidade *= 2;
            vetor = realloc(vetor, capacidade * sizeof(float));
            if (!vetor)
            {
                printf("Deu pau no realloc\n");
                exit(1);
            }
        }
    }

    ordena(vetor, qtd);

    FILE *binario = fopen("numeros.bin", "wb");
    if (!binario)
    {
        printf("fudeu no binario\n");
        exit(1);
    }

    fwrite(vetor, sizeof(float), qtd, binario);

    fclose(arquivo);
    fclose(binario);
    free(vetor);
}

int compara_float(const void *a, const void *b)
{
    float val_a = *((float *)a);
    float val_b = *((float *)b);
    if (val_a < val_b)
    {
        return -1;
    }
    else if (val_b < val_a)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}