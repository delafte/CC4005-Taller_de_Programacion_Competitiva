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

    bool leftOF(point A, point B){
        return ((B-A)^(*this-A)) >= 0;}

};
int main(){
    int N,K; cin >> N >> K;
    vector<point>stars(N);
    vector<vector<bool> >visited(N);
    for(int i=0; i<N;i++){
        for(int j =0; j<N;j++){
            visited[i].push_back(false);
        }
    }
    for(int i=0;i<N;i++){
        ll x,y; cin >>x>>y;
        stars[i]= point(x,y);
    }    
    if(K==1){
        cout << "Infinity"<<endl;
    }
    else{
        int ans;
        for(int i=0; i<N;i++){
            for(int j=i+1; j<N;j++){
                if(visited[i][j]==true) continue;
                int count =2;
                vector<int>indices;
                indices.push_back(i);
                indices.push_back(j);
                for(int k=j+1; k<N; k++){
                    point punto1 = stars[i],punto2=stars[j],punto3=stars[k];
                    if((punto3.y-punto1.y)*(punto1.x-punto2.x)==(punto1.y-punto2.y)*(punto3.x-punto1.x)){
                        count++;indices.push_back(k);
                    }
                }
                for(int a=0; a<count; a++){
                    for(int b=a+1; b<count;b++){
                        visited[indices[a]][indices[b]]=true;
                    }
                }
                if(count>=K){
                    ans+=1;
                }
            }
        }
        cout<<ans<<endl;
    }
    
    return 0;
}