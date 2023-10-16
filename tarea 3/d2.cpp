#include <iostream>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;
using state = pair<ll,int>;

ll INF = 1e18; 

void dijk(int n, vector <ll> &dist,priority_queue <state, vector<state>, greater<state> > &pq, vector <vector <pair<int,ll> > > &adj){
    while(!pq.empty()){
		auto [peso_camino, u] = pq.top();
		pq.pop();

		if(peso_camino != dist[u]) continue;
   
		for(auto [v, w] : adj[u]){ // [v,w] de C++17
			if(peso_camino + w < dist[v]){
				dist[v] = peso_camino+w;
				pq.push({dist[v], v});
			}
		}
	}
}

int main(){
	int n, m; 
	vector<int>respuestas;

	while(true){
		cin >> n >> m;
		if(n == 0 && m ==0) break;
        int s,d;
		cin >> s >> d;
		vector <vector <pair<int,ll> > > adj(n); 
		vector <vector <pair<int,ll> > > adj2(n); 
		for(int i=0; i<m; i++){
			int u, v;
			ll w;
			cin >> u >> v >> w;
			//u-=s; 
			//v-=s;
			adj[u].push_back({v, w});
			adj2[v].push_back({u,w});
		}
		priority_queue <state, vector<state>, greater<state> > pq;
		vector <ll> dist(n, INF);
		vector <ll> dist2(n, INF);
		pq.push({0,s});
		dist[s] = 0;
		dist2[d] = 0;

		dijk(n,dist,pq,adj);
		pq.push({0,d});
		dijk(n,dist2,pq,adj2);

		vector <vector <pair<int,ll> > > adj3(n); 

		for(int i = 0; i <n; i++){
			for(auto it = adj[i].begin(); it!= adj[i].end();it++){
			int v; ll w;	
			v = it->first; w = it->second;
			if(dist[i]+w+dist2[v]!=dist[d]){
					adj3[i].push_back({v,w});
				}
			}
		}
		vector <ll> dist3(n, INF);
		pq.push({0,s}); dist3[s]=0;

		dijk(n,dist3,pq,adj3);

		if(dist3[d]==INF){
			respuestas.push_back(-1);
		}
		else{
			respuestas.push_back(dist3[d]);
		}
	}
	
	for(int i =0; i < respuestas.size(); i++){
		cout << respuestas[i] << endl;
	}
	return 0;
}


