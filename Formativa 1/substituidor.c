#include <stdio.h>

int main() {
   //variaveis
   char texto[10001];
   char palavraAntiga[41];
   char palavraNova[41];
   int caracteresIguais = 0;
   int contador;

    //Lendo o texto inteiro.
    scanf("%[^\n]",texto);

    //Lendo a palavra que se deseja trocar.
    scanf("%s",palavraAntiga);

    //Lendo a nova palavra
    scanf("%s",palavraNova);

    //Processo de substituicao

    //Passando por todas as palavras do texto
    for (contador = 0; texto[contador] != '\0'; contador++) {
        //Verificando se a palavra que se deseja substituir está no texto 
        if (palavraAntiga[caracteresIguais] == texto[contador]) { 
            caracteresIguais++;        
        }else {
            if (caracteresIguais > 0) {
                if (palavraAntiga[caracteresIguais] == '\0') {
                    printf("%s", palavraNova);
                    caracteresIguais = 0;
                }else {
                    while (caracteresIguais > 0) {
                        printf("%c", texto[contador - caracteresIguais]);
                        caracteresIguais--;
                    }
                }
            }
            printf("%c", texto[contador]);
        }
    }
      if(caracteresIguais > 0 && palavraAntiga[caracteresIguais]=='\0'){
            printf("%s",palavraNova);
        }
        printf("\n");
   return 0; 
}