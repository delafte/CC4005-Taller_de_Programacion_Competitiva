#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <stack>
using namespace std;


void dfs_recursivo(int s,int j,  map<int, vector<int> > &grafo, map <int,int> &visited){
    visited[s] = 1;                
    for(int v : grafo[s]){                   
        if(visited[v] == -1){                   
            dfs_recursivo(v,j+=1, grafo, visited);  
        }
    }
}
int main(){
    int cant_zona_tierra; cin >> cant_zona_tierra; 
    map<int, vector<int> > grafo;
    map<int,int> visited;

    for(int i=0; i<cant_zona_tierra; i++){
        int x,y; cin >> x >> y; 
        grafo[x].push_back(y+1000); grafo[y+1000].push_back(x);
        visited[x] = -1; visited[y+1000] = -1; 
        
    }

    int componentes_conexas = 0;
    for(auto it = grafo.begin(); it != grafo.end(); it++){
        if (visited[it->first] == -1){
            componentes_conexas += 1;
            int j =0;
            dfs_recursivo(it -> first,j, grafo,visited);
        }
    }
    cout << componentes_conexas-1<< endl;
    return 0;
}