#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int x;
    int y;
}ParOrdenado;

int main(){
    int quantidadeDeElementos;
    int *elementos;
    
    scanf("%d ",&quantidadeDeElementos);
    elementos = (int*) malloc(quantidadeDeElementos*sizeof(int));

    for (int i=0; i<quantidadeDeElementos; i++){
        scanf("%d", &(elementos[i]));
    }

    return 0;
}