#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <string>
#include <strings.h>

using namespace std;

typedef struct {

	char nome[1500];
	char cor[20];
	char t;
}Input;

bool compare(Input a, Input b){

	int x = strcmp(a.cor, b.cor);//compara a cor

	if(x > 0)//verifica qual é antecessor
		return false;

	if(!x){//caso sejam iguais as cores

		x = a.t - b.t;

		if(x < 0)//verifica qual tamanho é antecessor
			return false;

		if(!x){

			x = strcasecmp(a.nome, b.nome);
			return x > 0 ? false : true;
		}
		return true;
	}
	return true;
}

void print(Input a){
	printf("%s %c %s\n", a.cor, a.t, a.nome);
}

int main(){

	int n = -1;
	Input in[60];

	scanf("%d\n", &n);
	while(true){

		for(int i = 0; i < n; i++){

			gets(in[i].nome);
			scanf("%s %c", in[i].cor, &in[i].t);
			getchar();
		}
		sort(in, in + n, compare);
		for_each(in, in + n, print);
		
		scanf("%d\n", &n);
		if(!n) break;
		
		printf("\n");
	}

	return 0;
}
