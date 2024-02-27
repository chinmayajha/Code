#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n; cin >> n; n *= 2;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        shuffle(a.begin(), a.end(), rng); sort(a.rbegin(), a.rend());

        int sum = 0;
        for(int i = 1; i < n; i += 2) {
            sum += min(a[i], a[i - 1]);
        }
        cout << sum << "\n";
    }
}
