#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//definimos vectores para bfs
vector<vector<int> > grafo;
vector<int> dist;
vector<int> parent;
//funcion bfs
void bfs(int s, int n) { //nodo inicial, cantidad de nodos
    dist.assign(n, -1);
    parent.assign(n, -1);

    queue <int> cola;
    
    dist[s] = 0;
    cola.push(s);
    
    while (!cola.empty()){
        int u = cola.front(); cola.pop();

        for (int i=0; i<(int) grafo[u].size(); i++) { 
            int v = grafo[u][i];
            if (dist[v] == -1) {        // veo si ya lo visite
                dist[v] = dist[u] + 1;  // guardo la distancia hasta v
                parent[v] = u;          // guardo el padre de v
                cola.push(v);           // lo agrego a la cola
            }
        }
    }
}
//nuestra funcion para el problema
int main(){
    int n,m;
    cin >> n >> m;
    vector<int>vectores_grafo;
    grafo.assign(n,vectores_grafo);//tamaño de grafo

    for(int i = 0; i<m ;i++){
        int A,B; 
        cin >>A >> B;
        A--;B--;
        grafo[A].push_back(B);
        grafo[B].push_back(A);
    }
    bfs(0,n);//usamos bfs para recorrer grafo y calculamos la distancia de 0 a n solicitado

    if(dist[n-1] == -1){//distancia por default es -1, entonces si es imposible, se mantendra igual
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        vector<int>planetas_visitar;
        planetas_visitar.push_back(n);//hay que ingresar el ultimo planeta porque no se guarda en el vector parent
        int nodo_actual = n-1;//para no confundirnos en el while jeje
        
        while(parent[nodo_actual] != -1){// cuando es -1 es porque el ultimo padre no tiene padre, ie, es el inicio, slay
            planetas_visitar.push_back(parent[nodo_actual]+1);//sumamos 1 porque habiamos restado antes
            nodo_actual = parent[nodo_actual];//actualizamos valor de nodo actual
        }
        //comenzamos a imprimir en pantalla los resultados
        cout << dist[n-1]+1 << endl;

        for(int i = planetas_visitar.size()-1; i>=0;i--){//recorremos la lista al reves porque los almacenamos al reves(a partir del ultimo hijo)
            cout << planetas_visitar[i] << " ";
        }
    }
    return 0;
}


