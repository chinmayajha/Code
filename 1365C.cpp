
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
    int n; cin >> n;
    map<int, int> b;
    map<int, int> c;
    for(int i = 0; i < n; ++i) {
        b[nxt()] = i;
    }
    for(int j = 0; j < n; ++j) {
        int k; cin >> k;
        int temp = b[k] - j;
        if(temp < 0) temp += n;
        c[temp]++;
    }
    int mx = 0;
    for(auto& i : c) {
        mx = max(i.second, mx);
    }
    cout << mx;
}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    // cin >> testt;
    for (int i = 1; i <= testt; ++i){
        // cout << "Case #" << i << ": ";
        solve();
    }
}

