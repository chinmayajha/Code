
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
    int n; cin >> n;
    string s,t;cin>>s>>t;
    int o = 0, cnt = 0;
    for(int i=0;i<n;++i){
        if(s[i]!=t[i]){
            if(t[i] == 'o')o++;
            else cnt++;
        }
    }
    if(o - cnt < 0 || (o - cnt) % 2 != 0){
        cout << "NO\n";
    } else cout << "YES\n";
    
}
int main(){
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}