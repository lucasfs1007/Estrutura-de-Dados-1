#include <stdio.h>

int main() {

int numeros;
int par = 0;
int impar = 0;

scanf("%d", &numeros);

while ( numeros !=0 ) {
    if ( numeros % 2 == 0) {
        par += numeros;
    }else 
        impar += numeros;
        scanf("%d", &numeros);
   
}
printf("%d %d\n", par , impar);
    return 0;
}