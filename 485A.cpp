
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
string solve(){
    int n,m; cin >> n >> m;
    if(n % m == 0) return "Yes";
    int cnt = 0;
    while(cnt < 30) {
        cnt++;
        n += (n % m);
        n %= m;
        if(n == 0) return "Yes";
    }
    return "No";
}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    // cin >> testt;
    for (int i = 1; i <= testt; ++i){
        // cout << "Case #" << i << ": ";
        cout << solve();
    }
}


