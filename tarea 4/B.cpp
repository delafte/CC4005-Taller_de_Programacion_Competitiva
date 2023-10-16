#include<iostream>
#include <iomanip>
#include<cmath>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll x,y; cin >> x >> y;//ptos geometrita

    ll v,w; cin>>v>>w;//ptos facu

    int n; cin >> n;
    ll contador = 0;

    for(int i =0; i<n; i++){
        ll a,b,c; cin >> a>>b>>c;
        if(((a*x)+(b*y)+c<0 and (a*v)+(b*w)+c>0)or((a*x)+(b*y)+c>0 and (a*v)+(b*w)+c<0)){//condicion de que esten a cierto lado de la recta pero no ambos al mismo tiempo
            contador++;
        }
    }
    cout << contador << endl;
    return 0;
}