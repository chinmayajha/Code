// #include "debug.h"
#include "bits/stdc++.h"
using namespace std;
// #define int long long

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n, q, l, r; cin >> n >> q;
        string s, t;
        cin >> s >> t;

        vector<vector<int>> x(n, vector<int>(26, 0));
        for(int i = 0; i < n; ++i) {
            if(i > 0) x[i] = x[i - 1];
            x[i][s[i] - 'a']++;
            x[i][t[i] - 'a']--;
        }

        while(q--) {
            cin >> l >> r; l--; r--;
            if(l > r) swap(l, r);
            int ans = 0;

            for(int c = 0, temp; c < 26; ++c) {
                temp = x[r][c];
                if (l > 0) temp -= x[l - 1][c];
                ans += max(0, temp);
            }

            cout << ans << "\n";
        }
    }
}

