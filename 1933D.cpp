#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        // if count of gcd(all) > 1
        // if all elements same
        int gcd = a[0];
        for(int i = 1; i < n; ++i) gcd = __gcd(gcd, a[i]);
        int cnt = 0;
        for(auto& i : a) cnt += (i == gcd);
        
        cout << (cnt > 1 ? "NO" : "YES") << "\n";
    }
}

