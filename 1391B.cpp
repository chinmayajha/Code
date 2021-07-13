
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
    int n,m;cin >> n >> m;
    string s;
    int cnt = 0;
    while(n--){
        cin >> s;
        cnt += (s[m-1] == 'R');
    }
    for(int i=0;i<m;++i)cnt += (s[i] == 'D');
    cout << cnt << "\n";
}
int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}