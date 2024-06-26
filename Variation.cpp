
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
i64 n, k, cnt;
void solve(){
    cin >> n >> k;
    vector<i64> a(n); inarr(a,n);
    sort(all(a));
    for(auto& i : a) {
        i64 temp = (lower_bound(all(a), i + k) - a.begin());
        cnt += max(n - temp, 0LL);
    }
    cout << cnt;
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


