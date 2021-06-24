

#include "bits/stdc++.h"
using namespace std;
using lli = long long int;
using vi = vector<int>;

void solve(){
    int n;
    cin >> n;
    multiset<int> a;
    for(int i=0;i<n;++i){
        int x;cin >> x;
        a.insert(x);
    }
    int x = *prev(a.end());
    for(int i=1;i<=x;++i){
        if(x%i == 0)a.erase(a.find(i));
    }
    cout << x << " " << *prev(a.end());
}
int main(){
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}