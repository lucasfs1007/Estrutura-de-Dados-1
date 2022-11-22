#include <stdio.h> 

int main() {
    int numero1;
    int numero2;
    int numero3;
    int resultado;

scanf("%d",&numero1); 
scanf("%d",&numero2); 
scanf("%d", &numero3); //lendo os 3 numeros na mesma linha
scanf("%d", &resultado); //lendo o resultado digitado
    if (resultado == numero1+numero2+numero3) {
        printf("Acertou\n");
    }else {
        printf("Errou \n");
    }



    return 0;
}