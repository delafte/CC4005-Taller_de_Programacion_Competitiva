#include <iostream>
#include <set>
#include <vector>


using namespace std;

int main(){
    int n;
    int ans = 0;
    set <long long> moscas;

    cin >> n;
    vector <long long>porsi(n);

    for(int i = 0; i<n; i++){
        cin >>  porsi[i];
    }

    for(int i =0, j =0; i < n ; i++){
        if(moscas.find(porsi[i]) == moscas.end()){
            moscas.insert(porsi[i]);
        }
        else{
            while(moscas.find(porsi[i]) != moscas.end()){
                moscas.erase(porsi[j]);
                j += 1;
            } 
            moscas.insert(porsi[i]); 
        }
        if(moscas.size() > ans){
            ans = moscas.size();
        }
        
    }
    cout << ans << endl;
    return 0;
}