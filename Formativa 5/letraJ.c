//por solicitação do exercicio o nó cabeça "le" ta se chamando "f"
#include <stdio.h>
#include <stdlib.h>

//estrutura base da celula apresentada
typedef struct celula {
int dado;
struct celula *prox;
} celula;

//com essa estrutura base da celula poderemos fazer a função de enfileiramento
celula *enfileira (celula *f, int x) { //estrutura base da função dada no exercicio
    //ao se criar uma fila com listas precisamos sempre fazer o ajuste no tamanho da memória 
    celula*novo = malloc (sizeof(celula)); //abrindo espaço para implementação da lista
    //agora poderemos fazer o enfileiramento utilizando como referência o nó cabeça como ponto de partida da fila
    novo->prox=f->prox; //inserindo o proximo elemento apos o no cabeça "f"
    f->prox=novo; //pegando a proxima celula como novo nó cabeça
    f->dado=x; //armazenando o conteúdo no novo nó cabeça
    return novo;//tivemos uma inserção bem sucedida e por isso retomamos o novo nó cabeça
}
//caso não seja bem sucedida essa inserção será retornado um NULL por conta da biblioteca "stdlib.h"