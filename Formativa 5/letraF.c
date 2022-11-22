#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//declaração de variaveis
int topo = -1; //para indicar que ela está vazia --> estado inicial
char entrada[501];
int  maxPilha = 501;
char pilha[501];
//essa variavel vamos usar para verificar se as aberturas e fechamentos estao de acordo.
int desbalanceamento = 0;

//função para empilhar.
void empilha (char valor) {
    //caso não tivermos ocupado todo o espaço vamos poder incrementar
    if(topo < maxPilha-1) {
        topo++; //incrementando o topo
        pilha[topo] = valor; //passando o conteúdo digitado para o topo
    }
    //como está limitado o tamanho da entrada não precisaremos fazer realocação de tamanho da pilha
}

//função para desempilhar
char desempilha() {
    //caso essa pilha tenha sido já incrementada alguma vez poderemos desempilhar
    if (topo > -1) {
        char caracter; //vamos usar essa variavel para receber oq for retirado.
        caracter = pilha[topo]; //recebendo o conteudo a ser removido
        topo--; //decrementando
        return caracter;//retornando oq estamos removendo
    }
    //se a pilha tiver vazia não entraremos nesse if e não desempilharemos
}

int main() {

    
     scanf("%[^\n]",entrada);
    //passaremos por todos os caracteres inseridos na entrada
     for(int i=0; i<strlen(entrada);i++){
    //faremos o jogo de parenteização e inserir a ordem de abertura == Chaves--> colchete-->parenteses
    if(entrada[i] == '{'){empilha('{');}
    if(entrada[i] == '('){empilha('(');}
    if(entrada[i] == '['){empilha('[');}
    //mal parenteseado
    if(entrada[i] == '}' && topo < 0 || entrada[i] == ']' && topo < 0 || entrada[i] == ')' && topo < 0 ){desbalanceamento++;}
    //caso não tivermos com a pilha vazia vamos ver a ordem de fechamento seguindo a ordem.
    if(topo != -1){
    if(entrada[i] == '}' && desempilha() != '{'){desbalanceamento++;}else{}
    if(entrada[i] == ']' && desempilha() != '['){desbalanceamento++;}else{}
    if(entrada[i] == ')' && desempilha() != '('){desbalanceamento++;}else{}  
    }
}

//caso não tivermos algo sendo fechado na ordem errada e nem faltando algo a se fechar
if(desbalanceamento == 0 && topo == -1){
    printf("sim\n");
    } else {
        //caso contrario nao deu certo.
        printf("nao\n");
    }
    return 0;
}