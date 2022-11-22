#include <stdlib.h>
#include <stdio.h>

unsigned long int memorizacao[81];

long int fibonacci (int numero) {

    if (numero <= 2 ) {
        return 1;
    }
    if (memorizacao[numero] !=0 ) {
        return memorizacao[numero];
    }else{
        memorizacao[numero] = fibonacci(numero-1) + fibonacci(numero-2);
        return memorizacao[numero];
    }
}

//validado