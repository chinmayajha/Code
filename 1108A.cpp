

#include "bits/stdc++.h"
using namespace std;
using lli = long long int;
using vi = vector<int>;

void solve(){
    int l1,r1,l2,r2;
    cin >> l1 >> r1 >> l2 >> r2;
    if(l1 == l2){
        l1 = r1;
    } 
    if(l1 == l2){
        l2 = r2;
    }
    cout << l1 << " " << l2 << "\n";
}
int main(){
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}