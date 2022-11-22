#include <stdio.h>
#include <stdlib.h>

//Função para contar o numero de algarismos 7
long int conta7s (long int numero) {

    //nao temos o numero 7
    if(numero == 0) {
        return 0;

    //coletando o numero 7
    }else{
        return conta7s(numero/10) + (numero%10 == 7); 
    }
    
}

int main() {

    //Declaracao variaveis
    long int numero;

    //Leitura do numero
    scanf("%ld",&numero);

    printf("%ld\n", conta7s(numero));
    return 0;
}
//validado