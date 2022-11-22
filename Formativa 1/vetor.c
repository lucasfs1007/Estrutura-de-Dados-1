#include <stdio.h> 

int main() {

int quantidade;
    scanf("%d", &quantidade); //Tamanho do vetor
int valores[quantidade];    
int menorIndice = 0;
int  menorValor;
    

  

    scanf("%d", &valores[0]);

    menorValor = valores[0];

    for (int i = 1; i < quantidade; i++) {
        scanf("%d", &valores[i]);

        if (valores[i] < menorValor){
            menorValor = valores[i];
            menorIndice = i;
        }

    }
    
    printf("%d\n", menorIndice);


   return 0; 
}