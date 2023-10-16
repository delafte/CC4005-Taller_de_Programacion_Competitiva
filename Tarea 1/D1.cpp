#include <iostream>
#include <cmath>
#include <utility>
#include <vector>
#include <set>

using namespace std;

int main(){
    int n, A, B;
    cin >> n;
    vector <int> a(n);
    vector <int> c(n);
    multiset <int> b;
    for(int i = 0; i < n; i++){
        cin >> A;
        a[i] = A; 
    }
    for(int i = 0; i<n; i++){
        cin >> B;
        b.emplace(B);
    }
    // vector a
    // vector b multiset
    //b.lowerbound(6) nos entrega el valor que sea al menos 6
    for(int i =0; i < n; i++){
        // nos da el (a_i + b_i)%n menor posible
        auto itr = b.lower_bound(n-a[i]);//que pasa si no hay un valor >= n-a[i]
        if (itr == b.end()){
            // b.begin() minimiza (a+b)%n
            itr = b.begin();
        }
        c[i] = (a[i]+(*itr))%n;  
        b.erase(itr);
    }
    for(int i =0; i <n;i++){
        cout << c[i]<< " ";  
    }

    return 0;
}