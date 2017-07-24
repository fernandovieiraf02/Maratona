#include <bits/stdc++.h>

using namespace std;

typedef struct{

	int p;
	int v;
}Graph;

bool compare(Graph a, Graph b){

	return a.p < b.p;
}

int main() {

	int n = -1, m = -1, pivo = 0, total = 0, economizado = 0, menor = 0;
	list<Graph> grafo[200000];
	Graph g;
	bitset<200000> visitados;

	while(scanf("%d %d\n", &m, &n) != EOF){

		g.v = 0, g.p = 0;
		total = 0, economizado = 0;

		if(!m && !n) continue;

		for(int i = 0; i < n; i++){

			scanf("%d %d %d\n", &pivo, &g.v, &g.p);
			grafo[pivo].push_back(g);
			total += g.p;
		}

		for(int i = 0; i < n; i++)
			grafo[i].sort(compare);

		//verifica se todos os vertices ja foram marcados
		while(visitados.count() < (unsigned) m-1){

			menor = INT_MAX;
			pivo = 0;
			//percorre todos vertices
			for(int i = 0; i < m-1; i++){
				//verifica se o vector nao esta vazio e se contem o menor valor do peso
				if( !grafo[i].empty() &&  menor >= grafo[i].front().p){
						//verifica se os vertices ja foram visitados, no maximo um dos vertices pode ter sido visitado
						if( !(visitados.test(grafo[i].front().v) && visitados.test(i)) ){

							menor = grafo[i].front().p;
							pivo = i;
						}
						//caso os dois foram ja foram visitados elimina esse elemento e volta um laco anterior
						else grafo[i].pop_front(), i--;

						printf("%d - %d - %d\n", i, grafo[i].front().v, grafo[i].front().p);
				}
			}

			printf("MST: %d - %d - %d\n", pivo, grafo[pivo].front().v, menor);

			//contabiliza os valores do custo da AGM.
			economizado += grafo[pivo].front().p;

			//marcando os vertices visitados no vetor
			if(visitados.count() == 0 ) visitados[pivo] = 1;
			visitados[ grafo[pivo].front().v ] = 1;

			//elimina o vertice ja visitado;
			grafo[pivo].pop_front();
		}

		printf("%d\n", total - economizado);
	}
	return 0;
}
