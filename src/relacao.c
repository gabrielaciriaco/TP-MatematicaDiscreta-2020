#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int x;
    int y;
}ParOrdenado;

int main(){
    //Entrada de dados
    FILE * arquivo;
    arquivo = fopen("entrada.txt","r");
    int quantidadeDeElementos;
    int *elementos;
    char linha[5];
    int teste1;
    int teste2;
    if(arquivo != NULL){
        int contador = 0;
        while(!feof(arquivo)){
            if(contador == 0){
                fscanf(arquivo,"%d",&quantidadeDeElementos);
                elementos = (int*) malloc(quantidadeDeElementos*sizeof(int));
                for(int i = 0; i< quantidadeDeElementos; i++){
                    fscanf(arquivo,"%d",&elementos[i]);
                    printf("Elemento %d: %d\n",i,elementos[i]);
                }
            }else{
                fscanf(arquivo,"%d",&teste1);
                fscanf(arquivo,"%d",&teste2);
                printf("%d %d\n",teste1,teste2);
                //Todo armazenar par ordenado
            }
            fgets(linha,sizeof(linha),arquivo);
            contador++;
        }
        printf("Quantidade de elementos: %d ",quantidadeDeElementos);

        //Todo Comparacoes

        //Todo: saida
        return 0;

    }else{
        printf("Erro, não foi possível abrir o arquivo");
        return 0;
    }
}