#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using vi = vector<int>;

void solve(){
    lli x,y,a,b;cin>>x>>y>>a>>b;
    if((y-x)%(a+b)!=0){
        cout << "-1\n";
    } else {
        cout << (y-x)/(a+b) << "\n";
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}