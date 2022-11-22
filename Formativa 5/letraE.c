#include <stdio.h>
#include <string.h>
#include<stdlib.h>

//criaremos uma lista encadeada para receber as palavras.
typedef struct no {
  char *palavra; //trataremos a sequencia de caracteres como uma "palavra"
  struct no *proximo; //utilizaremos o nó cabeça para podermos inserir ou remover a estrutura de pilhas
}no;

 //estrutura de uma pilha onde pegaremos o topo para podermos trabalhar com as funções
no *cria_pilha() {
 no *topo;
 topo = malloc (sizeof(no)); //estamos abrindo espaço para inserção de novos elementos
 topo->proximo = NULL; //como ele é o ultimo elemento inserido não há nada depois dele
 return topo; //sempre será o último elemento
}

//criaremos a função de desempilhamento
int desempilha (no *topo) {
      no *lixo = topo->proximo; //pegando a última celula para remove-la.
      //não poderemos remover se o seu conteúdo for NULL,portando é um erro.
      if (lixo == NULL ){
        printf("NULL\n");
        return 1;
      } 
      //caso contrário poderemos remover o ultimo elemento (topo).
       printf("%s\n",lixo->palavra); //printando a palavra que iremos remover
       topo->proximo = lixo->proximo; //removendo o topo, a última celula
       free(lixo); // devolvendo a memória que estava sendo consumida 
       return 0; //desempilhamento bem sucedido
}

//criaremos agora a função de empilhamento.
int empilha (no *topo, char *frase) { // empilharemos no topo essa sequencia de palavras
    no *novo = malloc (sizeof(no)); //abrindo espaço na lista encadeada para inserção.
    //não vamos conseguir inserir NULL em uma pilha,portanto é um código de erro.
    if (novo == NULL) return 1; //código de erro
    //caso contrário poderemos fazer a inserção.
    novo->palavra = frase; //nova celula vai receber a palavra
    novo->proximo = topo->proximo; //pegando a proxima celula
    topo->proximo = novo; //fazendo a inserção já na próxima celula com o conteudo de palavra
  
  return 0; //empilhamento bem sucedido
}

//deverá ser tratado se o programa vai inserir ou desfazer

//função para fazer o tratamento da operação.
int operacao(char *op) {
  //iremos comparar as expressões para verificar qual operação iremos executar
    char *inserir = "inserir";
    char *desfazer = "desfazer";
    //variaveis auxiliares
    int i; //para inserir
    int d; //para desfazer.
    //comparação dos conteudos.
      i = strcmp(op,inserir);
      d = strcmp(op,desfazer);

      if (i == 0) {
        return 1;

      }else if (d == 0) {
        return 2;

      } else {
        return 0;

      }
}

//onde nós trabalharemos com todas as funções
int main () {
    no *topo; //pegaremos o topo da lista para poder trabalhar com ele.
    topo = cria_pilha(); //pegaremos o topo pela nossa estrutura de criação de pilha
    char input[10]=""; //iniciaremos vazio para não termos risco de ter algum lixo na compilação.

    //estrutura das funções
    int chamaOperacao;

     while(scanf("%s",input) != EOF) {
      //chamada da função que determinará o que faremos
      chamaOperacao = operacao(input);

        //chamada para empilhar
        if(chamaOperacao == 1) {
            char *palavra = calloc(101,sizeof(char)); //entrada maxima
            scanf("%[^\n]s",palavra);
            //incrementando a pilha com o que foi digitado
            empilha(topo,palavra);

        //chamada para desempilhar...cntrl z
        } else if(chamaOperacao == 2) {
            desempilha(topo);

        }
      
        //caso venha algum lixo de memoria ou algo diferente de empilhar ou desempilhar
        else {
            printf("entrada invalida\n");

        }
     }
   return 0; 
}