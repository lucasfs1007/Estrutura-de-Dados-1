#include <stdio.h>

int main() {

int valorTotal = 0;
int consumo;
int fatura = 7;

scanf("%d", &consumo); 

for (int i = 0; i <= consumo; i++) {
    if (i > 100) {
        valorTotal = 5;
    } else if (i > 30) {
        valorTotal = 2;
    } else if (i > 10) {
       valorTotal = 1; 
    }
    
    fatura += valorTotal;
}
printf("%d\n", fatura);
    return 0;
}