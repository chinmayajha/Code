#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> c(n), m(n);
        for (int i = 0; i < n; ++i) cin >> c[i];
        for (int i = 0; i < n; ++i) cin >> m[i];

        for(int i = 0; i < n - 1; ++i) {
            m[i + 1] = min(c[i + 1], m[i] + m[i + 1]);
        }

        cout << m.back() << "\n";
    }
}
