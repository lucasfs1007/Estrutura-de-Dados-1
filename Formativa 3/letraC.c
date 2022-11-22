#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

    //declarando variaveis
    int n;
    int m;
    int i;
    int direita;
    int esquerda;
    int j; //o que será impresso
    //*N e *M vão atuar como ponteiros


    //lendo a entrada
    scanf("%d %d", &n, &m);

    // fazendo deslocamentos pelo vetor
    int *N = malloc(n * sizeof(int)), *M = malloc(m * sizeof(int));

    //passando por todo o vetor de N e lendo o N na posição i
    for (i = 0; i < n; i++) {

        //lendo N na posição i --> aqui leio de fato o conteúdo dele
        scanf("%d", &N[i]);

    }

    //Passando por todo o vetor de M  e lendo o M na posição i
    for (i = 0; i < m; i++) {

        //lendo M na posição i --> aqui leio de fato o conteudo dele
        scanf("%d", &M[i]);

    }

    //passando por todo o vetor de m
    for (i = 0; i < m; i++) {

        direita = n - 1;
        esquerda = 0;

        if (M[i] > N[n - 1]) {

            printf("%d\n", n);
        
        }else{
        
            if (M[i] < N[0]) {
            
                printf("0\n");
            
            }else {
            
                do {
                

                    j = (esquerda+ direita) / 2;
                    if (N[j] < M[i] && M[i] <= N[j + 1]) {
                    
                        printf("%d\n", j+ 1);
                        
                        break;
                    
                    }else {
                    
                        if (N[j] < M[i]) {
                        
                            //parte a esquerda do vetor
                            esquerda= j + 1;
                        
                        }else {
                        
                            //parte a direita do vetor
                            direita= j - 1;
                        }
                    }
                    //faremos até se igualarem ou passarmos tudo da esquerda para direita
                } while (esquerda<= direita || esquerda == direita );
            }
        }
    }

    return 0;
}