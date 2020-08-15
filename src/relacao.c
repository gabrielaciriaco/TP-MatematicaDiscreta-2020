#include <stdio.h>
#include <stdlib.h>
#define MAX_TAMANHO 1000

typedef struct
{
    int x;
    int y;
} ParOrdenado;

int encontraPosicaoElemento(int elementos[], int elemento, int quantidadeDeElementos)
{
    for (int i = 0; i < quantidadeDeElementos; i++)
    {
        if (elemento == elementos[i])
        {
            return i;
        }
    }
}

int main()
{
    //Entrada de dados
    FILE *arquivo;
    if ((arquivo = fopen("entrada.txt", "r")) == NULL)
    {
        printf("Arquivo não encontrado, verifique se o arquivo entrada.txt está na pasta");
        exit(1);
    }

    int quantidadeParesOrdenados = 0;
    ParOrdenado paresOrdenados[MAX_TAMANHO];

    int quantidadeDeElementos;
    fscanf(arquivo, "%d", &quantidadeDeElementos);
    int matrizAdjacencias[quantidadeDeElementos][quantidadeDeElementos];

    int elementos[quantidadeDeElementos];
    for (int i = 0; i < quantidadeDeElementos; i++)
    {
        fscanf(arquivo, "%d", &elementos[i]);
    }

    while (!feof(arquivo) && quantidadeParesOrdenados < MAX_TAMANHO)
    {
        fscanf(arquivo, "%d", &paresOrdenados[quantidadeParesOrdenados].x);
        fscanf(arquivo, "%d", &paresOrdenados[quantidadeParesOrdenados].y);
        quantidadeParesOrdenados++;
    }
    fclose(arquivo);
    //Montagem da matriz de adjacencias
    for (int i = 0; i < quantidadeDeElementos; i++)
    {
        for (int j = 0; j < quantidadeDeElementos; j++)
        {
            matrizAdjacencias[i][j] = 0;
        }
    }
    for (int i = 0; i < quantidadeParesOrdenados; i++)
    {
        int posicaoX = encontraPosicaoElemento(elementos, paresOrdenados[i].x, quantidadeDeElementos);
        int posicaoY = encontraPosicaoElemento(elementos, paresOrdenados[i].y, quantidadeDeElementos);
        matrizAdjacencias[posicaoX][posicaoY] = 1;
    }

    for (int i = 0; i < quantidadeDeElementos; i++)
    {
        for (int j = 0; j < quantidadeDeElementos; j++)
        {
            printf("%d  ", matrizAdjacencias[i][j]);
        }
        printf("\n");
    }

    printf("Propriedades\n");

    //verificando a relação reflexiva
    printf("1. Reflexiva: ");
    int cont = 0;
    for (int i = 0; i < quantidadeDeElementos; i++)
    {
        if (matrizAdjacencias[i][i] == 1)
        {
            cont++;
        }
    }
    if (cont == quantidadeDeElementos)
    {
        printf("V\n");
    }
    else
    {
        printf("F\n");
        printf("  ");
        for (int i = 0; i < quantidadeDeElementos; i++)
        {
            if (matrizAdjacencias[i][i] != 1)
            {
                printf("(%d,%d)", elementos[i], elementos[i]);
            }
        }
        printf("\n");
    }

    //verificando a relação irreflexiva
    printf("2. Irreflexiva: ");
    cont = 0;
    for (int i = 0; i < quantidadeDeElementos; i++)
    {
        if (matrizAdjacencias[i][i] == 0)
        {
            cont++;
        }
    }
    if (cont == quantidadeDeElementos)
    {
        printf("V\n");
    }
    else
    {
        printf("F\n");
        printf("   ");
        for (int i = 0; i < quantidadeDeElementos; i++)
        {
            if (matrizAdjacencias[i][i] != 0)
            {
                printf("(%d,%d)", elementos[i], elementos[i]);
            }
        }
        printf("\n");
    }

    //verificando a relação simetrica

    // printf("2. Simétrica: ");
    // ParOrdenado faltaParaSerSimetrica[quantidadeParesOrdenados];
    // int EhSimetrica = 1;
    // int numeroDeFaltaParaSerSimetrica = 0;
    // for (int i = 0; i < quantidadeDeElementos; i++)
    // {
    //     for (int j = 0; j < quantidadeDeElementos; j++)
    //     {
    //         if (matrizAdjacencias[i][j] != matrizAdjacencias[j][i])
    //         {
    //             EhSimetrica = 0;
    //             faltaParaSerSimetrica[numeroDeFaltaParaSerSimetrica].x = elementos[i];
    //             faltaParaSerSimetrica[numeroDeFaltaParaSerSimetrica].y = elementos[j];
    //             numeroDeFaltaParaSerSimetrica++;
    //         }
    //     }
    // }
    // if (EhSimetrica)
    // {
    //     printf("V\n");
    // }
    // else
    // {
    //     printf("F\n");
    //     printf("   ");
    //     for (int i = 0; i < numeroDeFaltaParaSerSimetrica; i++)
    //     {
    //             printf("(%d,%d)", faltaParaSerSimetrica[i].x, faltaParaSerSimetrica[i].y);
    //     }
    //     printf("\n");
    // }

    return 0;
}
