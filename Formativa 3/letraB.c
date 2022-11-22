#include<stdio.h>
#include<stdlib.h>

//função para fazer a ordenação sem utilizar laços
void ordena(int *v, int n) {

    //declarando variaveis.
    int i;
    int j;
    int recebe;

    for (i = 1; i < n; i++) {

        //recebe recebe o v na posição i
        recebe = v[i];

        //manipulando as posições dentro do vetor
        j = i - 1;
  
      //passando por todo o vetor
        while (j >= 0 && v[j] > recebe) { 

            v[j + 1] = v[j];
            j = j - 1;
        }

        //agora teremos o vetor ordenado
        v[j + 1] = recebe;
    }
}