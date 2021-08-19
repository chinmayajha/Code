
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
    int n,d,h,cnt = 0;cin >> n >> d >> h;
    vector<int> a(n);inarr(a,n);
    bool chk = 0;
    for(int i=0;i<n;++i){
        if(cnt > h)chk = 1;
        if(a[i])cnt += a[i];
        if(!a[i])cnt = max(0,cnt - d);
        if(cnt > h)chk = 1;
    }
    cout << (chk ? "YES\n" : "NO\n");
    
}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    cin >> testt;
    for (int i = 0; i < testt; ++i) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}


