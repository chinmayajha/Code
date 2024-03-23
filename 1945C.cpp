#include "bits/stdc++.h"
using namespace std;
// #define int long long

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;

        vector<int> a(n + 2, 0);
        for(int i = 1; i <= n; ++i) a[i] = (s[i - 1] - '0');
        
        vector<int> pref = a, suff = a;
        
        // pref[i] = number of people satisfied on left of wall
        // suff[i + 1] = number of people satisfied on right of wall

        for(int i = n; i >= 0; --i) suff[i] = a[i] + suff[i + 1];
        a.back() = 1;
        for(int i = 1; i <= n + 1; ++i) pref[i] = (1 - a[i]) + pref[i - 1];
        
        int ans = -1, mn = INT_MAX / 4;
        for(int i = 0; i <= n; ++i) {
            // wall drawn between i and i + 1
            // pref[i] and suff[i + 1] to be compared
            // i people on the left, n - i on the right of wall
            if(pref[i] >= (i + 1) / 2 && suff[i + 1] >= (n - i + 1) / 2) {
                // i is a valid index
                if(mn > abs(2 * i - n)) {
                    ans = i;
                    mn = abs(2 * i - n);
                }
            }
        }
        
        cout << ans << "\n";
    }
}

