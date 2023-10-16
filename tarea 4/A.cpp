#include<iostream>
#include <iomanip>
#include<cmath>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long ll;

struct point{
    ll x,y;
    point(ll x=0, ll y=0):x(x), y(y){}

    point operator+(point p){
        return {x + p.x, y + p.y};}

    point operator-(point p){
        return {x+p.x, y+p.y};}

    ll operator*(point p){
        return x*p.x + y*p.y;}

    ll operator^(point p){
        return x*p.y - y*p.x;}

    ll dist(){
        return sqrt(x*x+y*y);}

    ll dist2(){
        return x*x + y*y;}

};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    for(int i = 0; i < t; i++){
        int n; cin >> n;
        vector<ll>minerosp;
        vector<ll>diamantesp;

        for(int j=0; j<2*n; j++){
            ll x,y; cin >> x >> y;
            if(x == 0){
                minerosp.push_back(abs(y));  
            }
            else{
                diamantesp.push_back(abs(x));  
            }   
        }
        sort(minerosp.begin(), minerosp.end(), greater<ll>());
        sort(diamantesp.begin(), diamantesp.end(),greater<ll>());
        double resultado = 0;
       for(int k=0; k<n; k++){
            point puntom(0,minerosp[k]);point puntod(diamantesp[k],0);
            resultado += sqrt(puntom.y*puntom.y + puntod.x*puntod.x);
        }
        cout << setprecision(11) << resultado << endl;
    }
    return 0;
}