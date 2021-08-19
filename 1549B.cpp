
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
    int n,cnt = 0;cin >> n;
    string s,t; cin >> s >> t;
    for(int i=0;i<n;++i){
        if(t[i]!='1')continue;
        if(i && s[i-1] == '1'){
            cnt++;
            s[i-1] = '0';
        } else if(s[i] == '0'){
            cnt++;
            s[i] = '0';
        } else if(i+1 < n && s[i+1] == '1'){
            cnt++;
            s[i+1] = '0';
        }
    }
    cout << cnt << "\n";
    
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


