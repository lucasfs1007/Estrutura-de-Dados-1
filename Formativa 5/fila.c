#include <stdio.h>
#include <stdlib.h>

typedef struct fila { 
  int *dados;  
  int N, p, u;
} fila;

fila *cria_fila () {
    fila *f = malloc(sizeof(fila));
    f->dados = malloc(5+sizeof(int));
    f->p = f->u = 0;
    return f;
}

int redimensiona (fila *f){
    // Não implementado
    return 1;
}

int enfileira (fila *f, int x){

    // Condição que a fila está cheia
    if((f->u+1)%f->N == f->p){
        if(redimensiona(f) != 0) return 1;
    }

    f->dados[f->u] = x;
    f->u = (f->u+1) % f->N;
    return 0;
}

int desenfileira (fila *f, int *y){
    // Fila vazia
    if(f->p == f->u) return 1;

    *y = f->dados[f->p];
    f->p = (f->p+1)%f->N;

    return 0;
}

