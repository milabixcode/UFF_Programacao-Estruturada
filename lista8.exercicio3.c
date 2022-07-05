#include <stdio.h>
#include <stdbool.h>

void **criaTransposta(int **matriz, int **matrizTrans, int coluna, int linha)
{
    int i,j;
    if(coluna==linha)
    {
        for (i=0;i<coluna;i++)
        {
            for (j=0;j<linha;j++)
            {
                matrizTrans[j][i]=matriz[i][j];
            }
        }
    }

    else
    {
        printf("A matriz nao eh quadratica, logo ela tambem nao eh simetrica");
    }
}
bool **verificaSimetria(int **matriz, int **matrizTrans, int coluna, int linha)
{
    int i,j;

    for (i=0;i<coluna;i++)
    {
        for (j=0;j<linha;j++)
        {
            if (matrizTrans[i][j] == matriz[i][j])
                continue;
            else
                return false;
        }
    }

    return true;
}
void main()
{
    int i,j,m,n;

    printf("Digite o numero de colunas: ");
    scanf("%d", &m);
    printf("Digite o numero de linhas: ");
    scanf("%d", &n);

    int **mat = (int **) malloc(m*sizeof(int *));
    if (mat==NULL)
    {
        exit(1);
    }
    int **matT = (int **) malloc(m*sizeof(int *));
    if (matT==NULL)
    {
        exit(1);
    }
    for (i=0;i<m;i++)
    {
        mat[i]= (int *) malloc(n*sizeof(int));
        if (mat[i]==NULL)
        {
            exit(1);
        }
        matT[i]= (int *) malloc(n*sizeof(int));
        if (matT[i]==NULL)
        {
            exit(1);
        }
    }
    printf("Preencha o vetor1 %d x %d: ", m, n);
    for (i=0;i<m;i++)
    {
        for (j=0;j<n;j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    criaTransposta(mat,matT,m,n);
    if (matT[0][0]==mat[0][0])
    {
        bool verifica = verificaSimetria(mat,matT,m,n);
        if (verifica == true)
            printf("As duas matrizes sao simetricas");
        else
            printf("As duas matrizes nao sao simetricas");
    }

    free(mat);
    free(matT);
}
