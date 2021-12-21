
#include "bits/stdc++.h"
using namespace std;

void solve(){
    int64_t n; cin >> n;
    vector<int64_t> a(n + 3, 0);
    for(int64_t i = 0; i < n; ++i) cin >> a[i + 3];
    
    for(int64_t i = 3; i < n + 3; ++i) {
        a[i] += min({a[i - 3], a[i - 2], a[i - 1]});
    }

    cout << min({a[n + 2], a[n + 1], a[n]});
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int testt = 1;
    // cin >> testt;
    for (int i = 1; i <= testt; ++i){
        // cout << "Case #" << i << ": ";
        solve();
    }
}
