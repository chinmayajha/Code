#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n, q, x, y, temp1, temp2; cin >> n >> q;
        vector<int> a(n + 1, 0), pref1(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            pref1[i] = (a[i] == 1 ? 2 : 1);
        }

        for (int i = 1; i <= n; ++i) {
            pref1[i] += pref1[i - 1];
            a[i] += a[i - 1];
        }

        while(q--) {
            cin >> x >> y;

            temp1 = a[y] - a[x - 1];
            temp2 = pref1[y] - pref1[x - 1];
            if (temp1 >= temp2 && y - x + 1 >= 2) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}