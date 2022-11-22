#include <stdio.h>
#include <stdlib.h>

//funcao que troca a ordem da string
void contrario(char *palavra,int tamanho) {
    char letra = palavra[tamanho];

    //vendo se temos pelo menos mais de uma letra.
    if (tamanho == 0) {
        printf("%c",letra);

        //tendo mais que uma letra posso inverter elas
    }else {
         printf("%c",letra);
         //invertendo a ordem
         contrario(palavra,tamanho-1);
    }
}

int main() {

    //Declarando variaveis
    int tamanho;
    //Garantindo que essa string tenha tamanho suficiente
    char palavra[1000];

    //lendo a string digitada
    scanf("%s", palavra);
    //certificando que terei o tamanho digitado e não sobre lixo
    tamanho = strlen(palavra);

    //invertendo a string
    contrario(palavra,tamanho-1);
    printf("\n");

    return 0;
}

//validado