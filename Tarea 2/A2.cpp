#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <stack>
using namespace std;

int main(){
	int n, m, k,contador=0;
	cin >> n >> m >> k;
	vector <vector <char> > grilla(n, vector<char>(m));

	for(int i=0; i<n; i++){// ... leemos la grilla desde la entrada estándar
		for(int j=0; j<m; j++){
			char casilla; cin >> casilla;
			if(casilla=='#'){
				contador++;
			}
			grilla[i][j]=casilla;
		}
	}
	vector <int> dx = {0, 1, 0, -1, 0};
	vector <int> dy = {0, 0, 1, 0, -1};
	// dx y dy indican los cuatro movimientos posibles. Un vector de movimiento sería (dx[i], dy[i])
	queue <pair<int,int> > q; // Nuestros nodos ahora son pares (x, y)
	vector <vector <int> > dist(n, vector <int>(m,-1)); // ahora nuestro vector dist es una matriz de nxm
    //q.push({0,0}); // empezaremos desde el (0,0)
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grilla[i][j]=='.'){
                q.push({i,j});
                j = m;
                i = n;
            }
        }
    }
	int contador2 = ((m*n)-contador-k);
	while(!q.empty() && contador2 > 0){
		auto [x,y] = q.front();
		q.pop();
		for(int dir=0; dir<5 && contador2>0; dir++){
			int nx = x+dx[dir];
			int ny = y+dy[dir];
			if(ny>=m || nx>=n || ny <0 || nx<0) continue;/* coordenada (nx, ny) está fuera de la grilla */
			if(grilla[nx][ny]=='#') continue;/* hay una muralla, un obstáculo, un nodo que no queremos visitar, etc en (nx, ny) */
			if(dist[nx][ny] != -1) continue; // ya fue visitado
			dist[nx][ny] = dist[x][y]+1; contador2-=1;
			q.push({nx,ny});
		}
	}
	if(n==1 && m==1 && k == 0 && contador == 0){
		dist[0][0]+=1;
	}
	// la respuesta queda guardada en dist
	for(int i=0; i<n;i++){
		for(int j=0; j<m;j++){
			if(dist[i][j]>-1){
				cout << '.';
			}
			else if(grilla[i][j] == '#'){
				cout << '#';
			}
			else{
				cout <<'X';
			}
		}
		cout<<endl;
	}
	return 0;
}
