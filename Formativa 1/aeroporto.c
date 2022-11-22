#include <stdio.h>

int main () {

int numeroAeroportos;
int numeroVoos;
int maisUsado = 0; 
int aeroportoA; 
int aeroportoB;
int  count = 0;
int identificadorAeroportos[101];

	scanf("%d %d", &numeroAeroportos, &numeroVoos);

	if(numeroAeroportos >= 0 && numeroAeroportos <= 100){

		if(numeroVoos >= 0 && numeroVoos <= 10000){

			while(numeroAeroportos != 0 && numeroVoos != 0){

				for(int i = 1; i <= numeroAeroportos; i++){
					identificadorAeroportos[i] = 0;
				}

				for(int i = 1; i <= numeroVoos; i++){
					scanf("%d %d", &aeroportoA, &aeroportoB);
					identificadorAeroportos[aeroportoA]++;
					identificadorAeroportos[aeroportoB]++;
				}

				for(int i = 1; i <= numeroAeroportos; i++){

					if(identificadorAeroportos[i] > maisUsado){
						maisUsado = identificadorAeroportos[i];
					}
				}
				printf("Teste %d\n", count+1);

				for(int i = 1; i <= numeroAeroportos; i++){
					if(identificadorAeroportos[i] == maisUsado){
						printf("%d ", i);
					}
				}
				printf("\n\n");
				count++;
				maisUsado = 0;
				scanf("%d %d", &numeroAeroportos, &numeroVoos);
			}
		}
	}



 return 0;   
}