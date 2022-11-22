#include <stdio.h>

int main() {
    int count =0;//Variavel onde contarei os meus numeros
    int numbers = 0;
    int ref ;

    ref= scanf("%d", &numbers); //Lendo os numeros digitados

    while (ref!= EOF) { //Enquanto ele quiser testar ele vai contar
    
         ref= scanf("%d", &numbers); //Lendo os numeros digitados
         count++;
         
          
    }
    printf("%d\n",count);
    

    return 0;
}