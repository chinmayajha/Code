
#include "bits/stdc++.h"
using lli = long long int;
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
    lli x,y,n; 
    cin >> x >> y >> n;
    n--;
    n %= 6;
    vector<lli> a{x,y,y-x,-x,-y,x-y};
    cout << (a[n]%1000000007+1000000007)%1000000007;
    
}
int main(){
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}