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
        for (int i = 0; i < n; ++i) cin >> a[i], a[i] += (i + 1);
        shuffle(a.begin(), a.end(), rng); sort(a.rbegin(), a.rend());

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!ans.size()) ans.push_back(a[i]);
            else ans.push_back(min(a[i], ans.back() - 1));
        }

        for(auto& i : ans) cout << i << " ";
        cout << "\n";
    }
}

