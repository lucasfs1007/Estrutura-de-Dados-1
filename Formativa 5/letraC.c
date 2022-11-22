#include <stdio.h>
#include <stdlib.h>

//estrutura da lista encadeada com nó cabeça
typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

//função para desempilhar usando listas encadeadas.
int desempilha (celula *p,int *y) { //salvarei a remocao em y
    celula *lixo = p->prox; //verificando o proximo endereco
     if(lixo == NULL) return 0; //nao ha oq remover,codigo de erro
     //nesse cado poderemos seguir para fazer o desempilhamento
    *y = lixo -> dado; //estamos armazenando em y o dado que queremos remover
    p -> prox = lixo -> prox; //pegando o elemento que iremos remover
    lixo -> prox = NULL; //removendo da lista.
    
    free(lixo); //"destruindo" o conteúdo

    return 1; //foi bem sucedido a remoção

}