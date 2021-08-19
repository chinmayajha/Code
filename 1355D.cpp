
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
    i64 n,s;cin >> n >> s;
    if(n == 1){
        if(s == 1)cout << "NO";
        else {
            cout << "YES\n";
            cout << s << "\n";
            cout << s-1;
        }
        return;
    }
    if( s < 2*n) {cout << "NO\n";return;}
    cout << "YES\n";
    vector<i64>a(n,(s/n));
    a.back() += (s%n);
    for(auto& i : a) {cout << i << " ";} cout << "\n";
    if(a[0]-1 > 0){
        cout << a[0]-1;
    } else if(a[0]+1 != a.back()) {
        cout << a[0]+1;
    } else cout << a[0]+2;
    
}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    // cin >> testt;
    for (int i = 0; i < testt; ++i) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}


