/*
    Author : Chinmay Jha
    @chinmayajha on Codeforces, Codechef, USACO, AtCoder and CSES.fi
    Date: 2021-06-21 21:32:53
*/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using vi = vector<int>;
unordered_set<lli> a;
void solve(){
    lli x;cin>>x;
    
    for(lli i = 1; i*i*i < x; ++i){
        lli cb = i*i*i;
        if(a.count(x - cb) > 0){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
int main(){
    
    for(lli i = 1;i*i*i <= 1e12; ++i){
        a.insert(i*i*i);
    }
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}