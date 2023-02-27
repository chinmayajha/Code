#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tt = 1;
    cin >> tt;
    while (tt--) {
        int n, m, cnt = 0; cin >> n >> m;
        string s, t; cin >> s >> t;

        reverse(t.begin(), t.end());
        s += t;
        for(int i = 1; i < n + m; ++i) cnt += (s[i] == s[i - 1]);
        
        cout << (cnt > 1 ? "NO" : "YES") << "\n";
    }
}
