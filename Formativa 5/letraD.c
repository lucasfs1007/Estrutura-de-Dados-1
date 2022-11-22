#include <stdio.h>
#include <stdlib.h>

//estrutura de uma lista encadeada com nó cabeça.
typedef struct celula{
    int dado;
    struct celula *prox; //nó cabeça==endereço inicial da lista...ou seja o primeiro topo da pilha
}celula;

//agora criaremos a função de empilhamento nessa lista encadeada.
int empilha (celula *p, int x) { //Essa estrutura de chamada é solicitada no enunciado
    celula *novo = malloc(sizeof(celula)); //certificando que teremos espaço de memória.
    //não conseguiremos inserir o valor 0 na pilha, ele é tratado como um erro.
    if (novo == 0 ) return 0; //código de erro
    //caso contrário conseguiremos fazer o empilhamento na lista encadeada.
    novo -> dado = x; //nova celula vai receber o conteúdo da variavel x na variavel novo
    novo -> prox = p -> prox; //incrementamos a pilha para receber o dado na próxima posição
    p -> prox = novo; //inserimos um dado x na pilha p
    
    return 0; //tivemos um empilhamento bem sucedido.
}