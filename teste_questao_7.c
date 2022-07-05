#include <stdio.h>
#include <stdlib.h>

#define QTD 7

int main()
{
    FILE *binario = fopen("numeros.bin", "rb");
    float *vetor = malloc(QTD * sizeof(float));
    fread(vetor, sizeof(float), QTD, binario);

    for (int i = 0; i < QTD; i++)
    {
        printf("%f\n", vetor[i]);
    }
    fclose(binario);
}