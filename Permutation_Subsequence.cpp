#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        map<int, int> m;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            m[a[i]] += 1;
        }

        int x = 1, ans = 0; // x = answer for prev permutation
        for(int len = 1; len <= n; ++len) {
            x *= m[len];
            x = x % 1000000007;
            ans += x;
            ans = ans % 1000000007;
        }

        cout << (ans % 1000000007) << "\n";
    }
}
