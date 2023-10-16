#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

int main(){
    int n;
    vector <string> Resultados;

    while(cin >> n){
        //vector <int> quitados;
        stack <int> pilauwu;
        queue <int> filauwu;
        priority_queue <int> filapriuwu;
        
        bool fila = true, pila = true, filapri = true;
        for(int i = 0; i < n; i++){
            int a,b;
            cin >> a >> b;
            if(a == 1){
                filauwu.push(b);
                filapriuwu.push(b);
                pilauwu.push(b);
            }
            else if(a == 2){
                if(filauwu.empty() || b != filauwu.front()){
                    fila = false;
                }
                else{
                    filauwu.pop();
                }
                if(filapriuwu.empty() || b != filapriuwu.top()){
                    filapri = false;
                }
                else{
                    filapriuwu.pop();
                }
                if(pilauwu.empty() || b != pilauwu.top()){
                    pila = false;
                }
                else{
                    pilauwu.pop();
                }
            }
        }

        if(pila == true && filapri != true && fila != true){
            Resultados.push_back("stack");
            }
        else if(pila != true && filapri == true && fila != true){
            Resultados.push_back("priority queue");
            }
        else if(pila != true && filapri !=true && fila == true){
            Resultados.push_back("queue");
            }
        else if(pila == true || filapri == true || fila == true){
            Resultados.push_back("not sure");
            }
        else if(pila != true && filapri != true && fila != true){
            Resultados.push_back("impossible");
            }
    }
    for(int i = 0; i< Resultados.size(); i++){
        cout << Resultados[i] << endl;
    }
    return 0;
}