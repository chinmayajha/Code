
#include "bits/stdc++.h"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
void solve(){
    int n; cin >> n;
    string s; cin >> s;
    string t = s;
    i64 cnt = 0;
    sort(all(t));
    for(int i=0;i<sz(s);++i){
        cnt += (s[i] != t[i]);
    }
    cout << cnt << "\n";
    // generate_n(a.begin(), n, nxt);
    
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
