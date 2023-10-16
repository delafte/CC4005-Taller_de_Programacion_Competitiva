#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <stack>
using namespace std;

vector<int> representante;
map<int, int> tamanouwu;

//Dfs iterativo
void dfs(int s, vector <vector<int> > &grafo, vector<int> &visited){
    stack <int> pila;
    pila.push(s);
    tamanouwu[s] = 1; // ya que se distribuye a si mismo
    representante[s] = s;

    while(!pila.empty()){
        int u = pila.top();
        pila.pop();
        visited[u] = 1;
        
        for (int i=0; i<(int) grafo[u].size(); i++) { 
            int v = grafo[u][i];
            if(visited[v] == -1){
                visited[v] =1;
                tamanouwu[s]++;
                representante[v] = s;
                pila.push(v);
            }
        }
    }
}
int main(){
    int n,m; cin >> n >> m;
    vector <vector<int> > grafo(n);
    vector<int> visited(n,-1);

    representante.assign(n,-1);

    while(m--){
        int usuarioscomunidad; cin >> usuarioscomunidad;
        if(usuarioscomunidad == 0){
            continue;
        }
        int first; cin >> first; first--;
        usuarioscomunidad--;
        while(usuarioscomunidad--){
            int personitas; cin >> personitas;
            personitas--;
            grafo[first].push_back(personitas);
            grafo[personitas].push_back(first);
        }
    }
    for(int i=0; i<n; i++){
        if (visited[i] == -1){
            dfs(i,grafo,visited);//si no se han visitado, dfs. asi es mas eficiente
        }
         cout << tamanouwu[representante[i]] << " ";//vamos imprimiendo resultado
    }
    return 0;
}