#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n), bit(31);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for(auto& j : a) {
            for(int i = 0; i < 31; ++i) {
                if(((1ll << i) & j)) bit[i] += 1;
            }
        }

        for(int i = 30; i >= 0; --i) {
            if(k <= 0) break;
            if(bit[i] + k >= n) {
                k -= (n - bit[i]);
                bit[i] = n;
            }
        }

        int ans = 0;
        for(int i = 0; i < 31; ++i) {
            if(bit[i] >= n) ans = (ans | (1ll << i));
        }
        cout << ans << endl;
    }
}
