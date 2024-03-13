#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        vector<int> a, b;
        for(int i = 0, x; i < n; ++i) {
            cin >> x;
            if(x < 0) a.push_back(abs(x));
            else b.push_back(x);
        }
        shuffle(a.begin(), a.end(), rng); sort(a.rbegin(), a.rend());
        shuffle(b.begin(), b.end(), rng); sort(b.rbegin(), b.rend());

        int mx = 0;
        int ans = 0, n1 = a.size(), n2 = b.size();
        if(n1) {
            for(int i = 0; i < n1; i += k) {
                ans += a[i];
                mx = max(mx, a[i]);
            }
        }

        if(n2) {
            for(int i = 0; i < n2; i += k) {
                ans += b[i];
                mx = max(mx, b[i]);
            }
        }
        
        cout << ans * 2 - mx << "\n";
    }
}

