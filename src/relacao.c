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
        fscanf(arquivo,"%d",&paresOrdenados[quantidadeParesOrdenados].x);
        fscanf(arquivo,"%d",&paresOrdenados[quantidadeParesOrdenados].y);
        quantidadeParesOrdenados++;
    }

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
    return 0;
}
