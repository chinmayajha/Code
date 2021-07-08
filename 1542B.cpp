
#include "bits/stdc++.h"
using i64 = long long int;
using namespace std;
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
#ifndef ONLINE_JUDGE
    #define db(x) cerr << #x <<" = " << n << "\n";
#else
    #define db(...)
#endif
//
void solve(){
    i64 a,b,n; 
    cin >> n >> a >> b;
    i64 cur = 1;
    while(cur <= n ){
        if((n-cur)%b == 0){cout << "YES\n";return;}
        cur *= a;
        if(cur == 1) break;
        
    }
    cout << "NO\n";
    
}
int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}