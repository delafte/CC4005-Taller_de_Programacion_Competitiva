#include <iostream>
#include <cmath>
#include <utility>
#include <map>
#include <set>

using namespace std;

int main(){
    long long n, paresx =0, paresy =0, repetidos = 0;
    
    map <long long,long long> coordenadax;
    map <long long,long long> coordenaday;  
    map <pair<long long, long long>, long long> punto;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        long long a,b;
        cin >> a >> b;
        if(i == 0){
            punto[make_pair(a,b)]++;
            coordenadax[a]++;
            coordenaday[b]++;
        }
        else if (punto.find(make_pair(a,b)) != punto.end()){
            punto[make_pair(a,b)]++;
            coordenadax[a]++;
            coordenaday[b]++;  
        }
        else if(punto.find(make_pair(a,b)) == punto.end()){
            punto[make_pair(a,b)]++;
            coordenadax[a]++;
            coordenaday[b]++;
        }
    }
    for (auto iter = punto.begin(); iter != punto.end(); iter++){
       if(iter -> second > 1){
           repetidos += (((iter -> second)-1)*iter -> second)/2;
        }
        
    }
    for (auto iter = coordenadax.begin(); iter != coordenadax.end(); iter++){
        paresx += (((iter -> second)-1)*iter -> second)/2; 
        
    }
    for (auto iter = coordenaday.begin(); iter != coordenaday.end(); iter++){
        paresy += (((iter -> second)-1)*iter -> second)/2;  
        
    }
    cout << paresx + paresy - repetidos << endl;
    return 0;
}