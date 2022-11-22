#include<stdio.h>
#include<stdlib.h>

//funcao para trocar todos os x digitados por y
void trocaXporY(char *frase) {

//equanto não tiver uma quebra de linha vou ter caracteres sendo adicionados
  if ((*frase) != '\0') {

        //toda a string vai estar como X 
        if ((*frase) == 'x') {
            (*frase) = 'y';
        }

        //troca dos x por y
        trocaXporY(frase +1);
  }  
}

int main() {
    
    //declarando variaveis
    //garantindo que seja  80 caracteres
    char frase[80];

    //lendo as string - receberei ate 80 caracteres
    scanf("%s" , frase);

    //função que vai trocar os X por Y
    trocaXporY(frase);

    //printando a string já trocada agora
    printf("%s\n" , frase);

    return 0;
}

//validado