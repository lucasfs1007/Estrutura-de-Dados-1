#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//estrutura da fila
typedef struct fila { //formato base dado no exercicio
  int *dados; //conteudo
  int N, p, u; //tamanho, primeiro e ultimo elemento da fila
} fila;

//função para fazermos o redimensionamento
int redimensiona (fila *f) {
    f->dados  = realloc (f->dados, 2*f->N*sizeof(int)); //dobrando o tamanho da fila
    //não podemos incrementar NULL
    if (f->dados == NULL) return 1;
    //zerando os valores do 
    for (int i = f->N; i< 2*f->N;i++) f->dados[i] = 0;
    //vamos verificar se a ordem da fila está ok
    if (f->p != 0 ) { //se p não tiver na primeira posição do vetor vamos precisar deslocar os elementos
        //vamos verificar qual a menor distancia
        if(f->N - f->p < f->u) { //se a distancia de p for menor que u deslocamos p 
            for ( int i = f->N - 1; i>= f->p;i--) { //pegando os valores de p ate N para deslocar
                f->dados[i+f->N] = f->dados[i]; //deslocando os valores em n posições pro final do novo vetor.
            }
            f->p += f->N; //deslocando o p
            //nesse else vamos deslocar o u
        }else {
            for (int i = 0; i< f->u;i++) { //pegando os valores de 0 ate u para deslocarmos n posições pro inicio do novo vetor
                f->dados[i+f->N] = f->dados[i]; //deslocando os valores em n posições para o inicio do novo vetor.               
            }
            f->u += f->N; //deslocamento do ponteiro de u
        }

    }
    f->N*=2; //dobrando o tamanho
    return 0;
}

//função para se fazer o enfileiramento
int enfileira (fila *f, int x) {
    //vamos validar se a fila já está cheia.
    if ((f->u+1)%f->N == f->p) { //temos uma fila cheia.
        if (redimensiona (f) != 0 ) return 0; //erro no redimensionamento
    }
    f->dados[f->u] = x;
    f->u = (f->u+1) %f->N;
    return 1; //enfileiramento bem sucedido
}