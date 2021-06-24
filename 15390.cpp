#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using vi = vector<int>;

void solve(){
    lli n,x,t;
    cin >> n >> x >>t;
    lli p = min(n-1,t/x);
    if(!p){
        cout << p << "\n";
        return;
    }
    lli k = (p*(p-1))/2 + (p*(n-p));
    cout << max(0ll,k) << "\n";
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}