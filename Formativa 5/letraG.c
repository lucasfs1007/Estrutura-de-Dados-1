#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//criação da fila
typedef struct fila { //formato base dado no exercicio
  int *dados; //conteudo
  int N, p, u; //tamanho, primeiro e ultimo elemento da fila
} fila;

//função para se fazer o desnfileiramento
int desenfileira (fila *f, int *y) {
    //precisamos verificar se a fila esta vazia
    if (f->p==f->u) { //temos a primeira e a ultima posição apontando p msm lugar
        return 0; //codigo de erro
    }else {
        *y = f->dados[f->p]; //guardando os dados na primeira posição
        f->p = (f->p+1)% f->N; //deslocando o ponteiro para as novas posições
        return 1; //desfileiramento bem sucedido
    }
}