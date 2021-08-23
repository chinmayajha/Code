#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
int n,m,a[100010];
set<int> s;
void f(int k){
    set<int> t;
    if(k % 2 == 0) t.insert(2);
    while(k % 2 == 0) k /= 2;
    //
    for(int i = 3; i*i <= k; i+=2){
        if(k % i == 0) t.insert(i);
        while(k % i == 0) k /= i;
    }
    if(k > 2) t.insert(k);
    //
    for(auto& i : t) {
        if(s.find(i) == s.end()) continue;
        for(int j = i; j < 100010; j += i) {
            auto it = s.find(j);
            if(it == s.end()) continue;
            s.erase(it);
        }
    }
}
void solve(){
    cin >> n >> m; inarr(a,n);
    for(int i = 1; i < m + 1; ++i) s.insert(i);
    for(int i = 0; i < n; ++i) f(a[i]);
    cout << sz(s) << "\n";
    for(auto& i : s) cout << i << "\n";
}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    // cin >> testt;
    for (int i = 1; i <= testt; ++i){
        // cout << "Case #" << i << ": ";
        solve();
    }
}


