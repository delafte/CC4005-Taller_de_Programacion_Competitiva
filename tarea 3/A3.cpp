#include <iostream>
#include <vector>
#include <queue>
#include<math.h>
//el descuennto se aplica solo al valor de una arista
//hacer un dij
//dos grafos, el original y el clon, del original al clon se tienen aristas con el descuento, y solo se puede ir una vez

using namespace std;

typedef long long ll;

ll INF = 1e18; // debe ser mayor a n*w_maximo = 10^11 (que es el peso del camino más largo posible)

int main(){
	int n, m; cin >> n >> m;

	// adj[i] = {{u1, w1}, {u2,w2}, ...} ahora se guarda el peso de la arista también (w)
	vector <vector <pair<int,ll> > > grafo1(n+n); 

	for(int i=0; i<m; i++){
		int paisa,paisb;
		long long costo; cin >> paisa >> paisb >> costo;
		paisa--; paisb--;
		grafo1[paisa].push_back({paisb, costo}); grafo1[paisa].push_back({paisb+n, floor(costo/2)}); 
		grafo1[paisa+n].push_back({paisb+n,costo});
	}
	using state = pair<ll,int>; 
	priority_queue <state, vector<state>, greater<state>> pq;
	vector <ll> dist(n+n, INF);
	pq.push({0,0});dist[0] = 0;
	while(!pq.empty()){
		auto [peso_camino, paisa] = pq.top(); // C++17 (structured binding)
		pq.pop();
		if(peso_camino != dist[paisa]) continue; // ya revisamos un camino mejor hacia u, ignoramos este
		for(auto [paisb, costo] : grafo1[paisa]){ // [v,w] de C++17
			if(peso_camino + costo < dist[paisb]){
				dist[paisb] = peso_camino+costo;
				pq.push({dist[paisb], paisb});
			}
		}
	}

	// las distancias finales están en "dist"
	ll respuesta1 = dist[n+n-1];
	cout << respuesta1 << endl;

	return 0;
}
