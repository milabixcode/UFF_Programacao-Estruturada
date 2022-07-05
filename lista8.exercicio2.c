#include <stdio.h>
void **matriz(int **matriz1, int **matriz2, int coluna, int linha)
{
    int i,j,soma=0;
    int **matriz3 = (int **) malloc(coluna*sizeof(int *));
    if (matriz3==NULL)
    {
        exit(1);
    }
    for (i=0;i<coluna;i++)
    {
        matriz3[i]= (int *) malloc(linha*sizeof(int));
        if (matriz3[i]==NULL)
        {
            exit(1);
        }
    }

    for (i=0;i<coluna;i++)
    {
        for (j=0;j<linha;j++)
        {
            matriz3[i][j]=matriz1[i][j] + matriz2[i][j];
        }
    }
    for (i=0;i<coluna;i++)
    {
        for(j=0;j<linha;j++)
        {
            printf("%d ", matriz3[i][j]);
        }
        printf("\n");
    }
    free(matriz3);
}
void main()
{
    int i,j,m,n;

    printf("Digite o numero de colunas: ");
    scanf("%d", &m);
    printf("Digite o numero de linhas: ");
    scanf("%d", &n);

    int **mat1 = (int **) malloc(m*sizeof(int *));
    if (mat1==NULL)
    {
        exit(1);
    }
    int **mat2 = (int **) malloc(m*sizeof(int *));
    if (mat2==NULL)
    {
        exit(1);
    }
    for (i=0;i<m;i++)
    {
        mat1[i]= (int *) malloc(n*sizeof(int));
        if (mat1[i]==NULL)
        {
            exit(1);
        }
        mat2[i]= (int *) malloc(n*sizeof(int));
        if (mat2[i]==NULL)
        {
            exit(1);
        }
    }
    printf("Preencha o vetor1 %d x %d: ", m, n);
    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("Preencha o vetor2 %d x %d: ", m, n);
    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {
            scanf("%d", &mat2[i][j]);
        }
    }

    matriz(mat1,mat2,m,n);
    free(mat1);
    free(mat2);
}
