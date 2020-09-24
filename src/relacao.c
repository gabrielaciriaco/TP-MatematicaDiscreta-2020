/* GABRIELA DA SILVA CIRÍACO - 2019054595
// COMPLEXIDADE O(n^3)
// FEITO E TESTADO NO UBUNTU 18.0.4 LTS gcc 7.5.0
// COMANDO PARA EXECUTAR NO UBUNTU: g++ relacao.c -o relacao && ./relacao
*/

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
    
    int matrizAdjacencias[quantidadeDeElementos][quantidadeDeElementos];
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
    //verificando a relação reflexiva
    printf("Reflexiva: ");
    int cont = 0;
    int EhReflexiva = 1;
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
        EhReflexiva = 0;
        printf("F\n");
        for (int i = 0; i < quantidadeDeElementos; i++)
        {
            if (matrizAdjacencias[i][i] != 1)
            {
                printf("(%d,%d); ", elementos[i], elementos[i]);
            }
        }
        printf("\n");
    }

    //verificando a relação irreflexiva
    printf("Irreflexiva: ");
    int EhIrreflexiva = 1;
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
        EhIrreflexiva = 0;
        printf("F\n");
        for (int i = 0; i < quantidadeDeElementos; i++)
        {
            if (matrizAdjacencias[i][i] != 0)
            {
                printf("(%d,%d); ", elementos[i], elementos[i]);
            }
        }
        printf("\n");
    }

    //verificando a relação simetrica
    printf("Simétrica: ");
    ParOrdenado paresNaoSimetricos[quantidadeParesOrdenados];
    int EhSimetrica = 1;
    int numeroParesNaoSimetricos = 0;
    for (int i = 0; i < quantidadeDeElementos; i++)
    {
        for (int j = 0; j < quantidadeDeElementos; j++)
        {
            if (matrizAdjacencias[i][j] == 1)
            {
                if (matrizAdjacencias[i][j] != matrizAdjacencias[j][i])
                {
                    EhSimetrica = 0;
                    paresNaoSimetricos[numeroParesNaoSimetricos].x = elementos[j];
                    paresNaoSimetricos[numeroParesNaoSimetricos].y = elementos[i];
                    numeroParesNaoSimetricos++;
                }
            }
        }
    }
    if (EhSimetrica == 1)
    {
        printf("V\n");
    }
    else
    {
        printf("F\n");
        for (int i = 0; i < numeroParesNaoSimetricos; i++)
        {
            printf("(%d,%d); ", paresNaoSimetricos[i].x, paresNaoSimetricos[i].y);
        }
        printf("\n");
    }

    //verificando a relacao anti simetrica
    printf("Anti-simétrica: ");
    ParOrdenado paresNaoAntiSimetricos[quantidadeParesOrdenados];
    int EhAntiSimetrica = 1;
    int numeroParesNaoAntiSimetricos = 0;
    int jaEstaNoVetor = 0;
    for (int i = 0; i < quantidadeDeElementos; i++)
    {
        for (int j = 0; j < quantidadeDeElementos; j++)
        {
            if (matrizAdjacencias[i][j] == 1)
            {
                if (matrizAdjacencias[i][j] == matrizAdjacencias[j][i] && i != j)
                {
                    for (int x = 0; x < numeroParesNaoAntiSimetricos; x++)
                    {
                        if (paresNaoAntiSimetricos[x].y == elementos[i] && paresNaoAntiSimetricos[x].x == elementos[j])
                        {
                            jaEstaNoVetor = 1;
                        }
                    }
                    if (!jaEstaNoVetor)
                    {
                        EhAntiSimetrica = 0;
                        paresNaoAntiSimetricos[numeroParesNaoAntiSimetricos].x = elementos[i];
                        paresNaoAntiSimetricos[numeroParesNaoAntiSimetricos].y = elementos[j];
                        numeroParesNaoAntiSimetricos++;
                    }
                    jaEstaNoVetor = 0;
                }
            }
        }
    }
    if (EhAntiSimetrica == 1)
    {
        printf("V\n");
    }
    else
    {
        printf("F\n");
        for (int i = 0; i < numeroParesNaoAntiSimetricos; i++)
        {
            printf("(%d,%d); (%d,%d); ", paresNaoAntiSimetricos[i].x, paresNaoAntiSimetricos[i].y, paresNaoAntiSimetricos[i].y, paresNaoAntiSimetricos[i].x);
        }
        printf("\n");
    }

    //verificando a relacao assimética
    printf("Assimétrica: ");
    int EhAssimetrica = 1;
    for (int i = 0; i < quantidadeDeElementos; i++)
    {
        for (int j = 0; j < quantidadeDeElementos; j++)
        {
            if (matrizAdjacencias[i][j] == 1)
            {
                if (matrizAdjacencias[i][j] == matrizAdjacencias[j][i])
                {
                    EhAssimetrica = 0;
                }
            }
        }
    }
    if (EhAssimetrica == 1)
    {
        printf("V\n");
    }
    else
    {
        printf("F\n");
    }

    //verificando a relacao transitiva
    printf("Transitiva: ");
    ParOrdenado paresNaoTransitivos[quantidadeParesOrdenados];
    int EhTransitiva = 1;
    int numeroDeParesNaoTransitivos = 0;
    jaEstaNoVetor = 0;
    for (int i = 0; i < quantidadeDeElementos; i++)
    {
        for (int j = 0; j < quantidadeDeElementos; j++)
        {
            for (int k = 0; k < quantidadeDeElementos; k++)
            {
                if (matrizAdjacencias[i][j] == 1 && matrizAdjacencias[j][k] == 1)
                {
                    if (matrizAdjacencias[i][k] != 1)
                    {
                        for (int x = 0; x < numeroDeParesNaoTransitivos; x++)
                        {
                            if (paresNaoTransitivos[x].x == elementos[i] && paresNaoTransitivos[x].y == elementos[k])
                            {
                                jaEstaNoVetor = 1;
                            }
                        }
                        if (!jaEstaNoVetor)
                        {
                            EhTransitiva = 0;
                            paresNaoTransitivos[numeroDeParesNaoTransitivos].x = elementos[i];
                            paresNaoTransitivos[numeroDeParesNaoTransitivos].y = elementos[k];
                            numeroDeParesNaoTransitivos++;
                        }
                        jaEstaNoVetor = 0;
                    }
                }
            }
        }
    }
    if (EhTransitiva == 1)
    {
        printf("V\n");
    }
    else
    {
        printf("F\n");
        for (int i = 0; i < numeroDeParesNaoTransitivos; i++)
        {
            printf("(%d,%d); ", paresNaoTransitivos[i].x, paresNaoTransitivos[i].y);
        }
        printf("\n");
    }

    printf("\n");
    printf("Relação de equivalência: ");
    if (EhReflexiva && EhSimetrica && EhTransitiva)
    {
        printf("V\n");
    }
    else
    {
        printf("F\n");
    }

    printf("Relação de ordem parcial: ");
    if (EhReflexiva && EhAntiSimetrica && EhTransitiva)
    {
        printf("V\n");
    }
    else
    {
        printf("F\n");
    }

    printf("\n");
    printf("Fecho transitivo da relação: ");
    for (int i = 0; i < quantidadeParesOrdenados; i++)
    {
        printf("(%d,%d); ", paresOrdenados[i].x, paresOrdenados[i].y);
    }
    for (int i = 0; i < numeroDeParesNaoTransitivos; i++)
    {
        printf("(%d,%d); ", paresNaoTransitivos[i].x, paresNaoTransitivos[i].y);
    }
    return 0;
}
