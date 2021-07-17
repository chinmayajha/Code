
#include "bits/stdc++.h"
using i64 = long long int;
using namespace std;
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
#ifndef ONLINE_JUDGE
    #define db(x) cerr << #x <<" = " << x << "\n";
#else
    #define db(...)
#endif
//
void solve(){
    i64 n,a,x,y;cin >> n >> a >> x >> y;
    if(n<=a){
        cout << n*x;
    } else {
        cout << a*x + ((n-a)*y);
    }

    
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
