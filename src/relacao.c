#include <stdio.h>
#include <stdlib.h>
#define MAX_TAMANHO 10000

typedef struct
{
    int x;
    int y;
} ParOrdenado;

int main()
{
    FILE *arquivo;
    arquivo = fopen("entrada.txt", "r");

    int quantidadeDeElementos;
    int *elementos;
    int quantidadeParesOrdenados = 0;
    ParOrdenado paresOrdenados[MAX_TAMANHO];

    if (arquivo != NULL)
    {
        char linha[MAX_TAMANHO];

        fscanf(arquivo, "%d", &quantidadeDeElementos);
        elementos = (int *)malloc(quantidadeDeElementos * sizeof(int));
        printf("Quantidade de elementos: %d\n", quantidadeDeElementos); //retirar

        for (int i = 0; i < quantidadeDeElementos; i++)
        {
            fscanf(arquivo, "%d", &elementos[i]);
            printf("Elemento %d: %d\n", i, elementos[i]);
        };

        while (!feof(arquivo) && quantidadeParesOrdenados<MAX_TAMANHO)
        {
            int cordenadaX,cordenadaY;
            fscanf(arquivo, "%d", &cordenadaX);
            fscanf(arquivo, "%d", &cordenadaY);
            paresOrdenados[quantidadeParesOrdenados].x = cordenadaX;
            paresOrdenados[quantidadeParesOrdenados].y = cordenadaY;
            printf("Cordenada %d x:%d\n",quantidadeParesOrdenados,paresOrdenados[quantidadeParesOrdenados].x); //retirar
            printf("Cordenada %d y:%d\n\n",quantidadeParesOrdenados,paresOrdenados[quantidadeParesOrdenados].y); //retirar
            quantidadeParesOrdenados++;
        }
        fclose(arquivo);
        printf("quantidade: %d",quantidadeParesOrdenados); //retirar
    }
    else
    {
        printf("Erro, não foi possível abrir o arquivo"); 
        return 0;
    }
}