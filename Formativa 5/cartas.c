#include <stdio.h>
#include <stdlib.h>

//estrutura da celula
typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

//estrutura da fila
typedef struct fila {
    //pegaremos o endereço do início e do fim da fila
  celula *inicio;
  celula *fim;
} fila;

//criando a função de criar fila
fila *cria_fila() {
    //precisamos fazer realocação de memória para abrir espaço na fila
    fila *filaCriada = (fila*) malloc(sizeof(fila));
    //no momento inicial vamos ter inicio e final da fila apontando para o mesmo lugar
   filaCriada->inicio = NULL;
   filaCriada->fim = NULL;
   return filaCriada;
}

//criando função para fazer o empilhamento das cartas
void *adiciona_carta_na_fila(fila *p, int carta){
    //precisaremos fazer realocação de memória
    celula *novo = (celula*) malloc(sizeof(celula));
    //pegando a proxima carta do leque
    novo->dado = carta;
    novo->prox = NULL; //reajustando o final da lista
    //em condições iniciais o fim e o inicio apontam para o mesmo lugar
    if(p->inicio == NULL) {
        p->inicio = novo;
        p->fim = novo;
        //caso não entrou nesse if vamos incrementando o final da fila
    } else {
        p->fim->prox = novo;
        p->fim = novo;
    }
}

//função para se manipular as cartas
int getCarta(fila *p){
    int carta;
    celula *celCarta;

    celCarta = p->inicio;
    carta = celCarta->dado;

    //marcando a primeira carta para se reajustar as demais
    p->inicio = celCarta->prox;

    if(p->inicio == NULL) {
        p->fim = NULL;
    }

    //retirando a carta, no caso a primeira --> fifo
    free(celCarta); //abrindo espaço na memória
    return carta;
}

//não temos cartas
int vazio(fila *p){
    return p->inicio == NULL;
}

int main() {
    int n, i, carta, cont = 0;
    fila *fila;
    fila = cria_fila();
    scanf("%d", &n);
    if (n) {
        cont = n;
        for(i=1; i<=n; i++) {
            adiciona_carta_na_fila(fila, i);
        }
    }

    printf("Cartas descartadas:");

    while(cont != 1) {
        printf(" %d", getCarta(fila));
        adiciona_carta_na_fila(fila, getCarta(fila));
        
        if(cont != 2) {
            printf(",");
        }

        cont--;
    }

    if(!vazio(fila)) {
        printf("\nCarta restante: %d\n", getCarta(fila));
    }
    return 0;
}