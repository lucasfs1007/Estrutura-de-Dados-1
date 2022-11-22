#include <stdlib.h>
#include <stdio.h>

//estrutura de uma pilha
typedef struct pilha { //similar a uma lista encadeada
  int *dados;  //armazenando os dados que serão inseridos na pilha
  int N, topo; //armazenando o tamanho total da pilha e o ultimo elemento inserido
} pilha;

//função para descrementar a pilha...iremos retirar o ultimo elemento inserido, ou seja o topo

int desempilha (pilha *p, int *y) {

    if (p->topo == 0) { //temos uma pilha vazia
        return 0; //codigo de erro
    }
    //caso nao estiver vazia vamos desempilhar o topo.
    p->topo--;
    *y=p->dados[p->topo]; //temos um novo topo
    return 1; //conseguimos descrementar

}
