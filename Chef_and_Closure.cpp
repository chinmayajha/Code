
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
i64 n,a[100009];
void solve(){
    cin >> n;
    inarr(a, n);
    sort(a, a + n);
    if(n == 1) {cout << "1\n"; return;}
    
    bool k1 = 0, k2 = 0, k3 = 0;
    for(int i = 0 ; i < n ; ++i) if(a[i] == a[0] * a[1]) {k1 = 1; break;}
    for(int i = 0 ; i < n ; ++i) if(a[i] == a[n-2] * a[n-1]) {k2 = 1; break;}
    for(int i = 0 ; i < n ; ++i) if(a[i] == a[0] * a[n-1]) {k3 = 1; break;}
    if(!k1 || !k2 || !k3) {
        cout << "0\n";
        return;
    }
    cout << "1\n";
    

}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    cin >> testt;
    for (int i = 1; i <= testt; ++i){
        solve();
    }
}

