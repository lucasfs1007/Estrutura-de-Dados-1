#include <stdio.h>
#include <stdlib.h>

//estrutura da celula
typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

//agora vamos poder implementar a função de desinfileirar.
int desenfileira (celula *f, int *y) { //estrutura base dada no exercicio
    //iremos retirar da fila aquilo que está no nó seguinte ao nó cabeça
    celula *lixo = f->prox;
    //o conteúdo descartado não pode ser NULL
    if (lixo == NULL) {
        return 0; //codigo de erro pois não podemos desinfileirar NULL
    }
    //como não entrou nesse if vamos poder remover o elemento da lista
    *y = lixo->dado; //vamos armazenar na variavel y o conteudo a ser removido
    f->prox = lixo->prox; //reajustando a ordem da fila para termos um proximo elemento como elemento a ser desinfileirado
    free(lixo); //removendo da memória o conteudo
    return 1; //tivemos um desinfileiramento bem sucedido
}