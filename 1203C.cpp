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

i64 n,k,b,cnt;
void solve(){
    cin >> n;
    while(n--){
        cin>>b;
        k = __gcd(k,b);
    }
    for(int i=1;i*1ll*i<=k;++i){
        cnt += (k%i==0) + (k%i==0 && i!=k/i);
    }
    cout << cnt;
}
int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}