
#include "bits/stdc++.h"
using namespace std;

void solve(){
    int64_t n; cin >> n;
    vector<int64_t> a(n);
    for(int64_t i = 0; i < n; ++i) cin >> a[i];

    map<int64_t, int64_t> b;
    int64_t cnt = 0;
    
    for(auto& i : a) b[i]++;
    for(auto& i : b) cnt += max(0ll, i.second - 1);

    cout << cnt + 1;
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
