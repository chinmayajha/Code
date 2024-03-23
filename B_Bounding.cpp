#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    // cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];

        int cnt = 1 + (a[0] <= m);
        for(int i = 1; i < n; ++i) {
            a[i] += a[i - 1];
            if(a[i] <= m) cnt++;
            else break;
        }

        cout << cnt;        
    }
}

