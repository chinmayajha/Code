#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n, q, k; cin >> n >> q;
        vector<int> a(n), mx(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        mx[0] = a[0];
        for(int i = 1; i < n; ++i) mx[i] = max(a[i], mx[i - 1]);
        for(int i = 1; i < n; ++i) a[i] += a[i - 1];

        while(q--) {
            cin >> k;
            int ind = upper_bound(mx.begin(), mx.end(), k) - mx.begin() - 1;
            if(ind == -1) cout << "0 ";
            else cout << a[ind] << " ";
        }

        cout << "\n";
    }
}