#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n, check = 0; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if(a[i]) check = 1;
        }
        
        int mx = *max_element(a.begin(), a.end());
        int sum = accumulate(a.begin(), a.end(), 0LL);

        cout << max(check, 2 * mx - sum) << "\n";
    }
}

