#include <stdio.h>
#include <stdlib.h>

void regua_inglesa (int numero) {
    
    if (numero == 1) {
        printf(".-");
    }else {

        regua_inglesa (numero - 1);
        printf("\n");

        printf(".");
        traco(numero);

        printf("\n");
        regua_inglesa(numero - 1);
    }

}

void traco (int total) {
    if (total == 1) {
        printf("-");
    }else {
        printf("-");
        traco(total - 1);
    }
}

int main() {

    int numero;
    scanf("%d", &numero);

    if(numero > 0 ) {

      regua_inglesa(numero);
      printf("\n");  
    }
    
    return 0;
}

//validado