
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//

void solve(){
    i64 n, m;
    cin >> n >> m;
    if(n == m) {cout << "0\n"; return;}
    if(2*n > m) {
        cout << max(m%n, m%(n+1));
    } else {
        cout << max(m%(m/2), m%(m/2 + 1));
    }
    cout << "\n";

}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    cin >> testt;
    for (int i = 1; i <= testt; ++i){
        // cout << "Case #" << i << ": ";
        solve();
    }
}


