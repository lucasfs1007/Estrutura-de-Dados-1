#include <stdio.h>

//variaveis
enum{MAXN=100010};
enum{MAXM=100010};
int n;
int m;
long long int r[MAXN];

int bbin(long long int valor) {

	int inicio = 1;
	int fim = n;
	if(valor > r[n])	return 0;
	
	while(inicio < fim) {

		int meio=(inicio + fim)/2;
		
		if(r[meio] >= valor) {

			fim=meio;
		
		} else {
			inicio = meio + 1;
		}

	}
	return n + 1 - fim;

}

int main() {

    scanf("%d %d",&n, &m);

	for(int i = 1;i <= n;i++) {

		scanf("%lld",&r[i]);

		//armazenando raios ao quadrado para comparar
		r[i]=r[i]*r[i];
	}
	long long int resp = 0;
	for(int i = 1;i <= m;i++) {

		long long int x;
        long long int y;

        //lendo x e y
		scanf("%lld %lld",&x,&y);

		resp+=bbin(x* x + y*y);
	}

	printf("%lld\n",resp);

	return 0;
}