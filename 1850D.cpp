#include "bits/stdc++.h"
using namespace std;

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        
        int ans = n - 1, last = 0;
        for(int i = 0; i < n - 1; ++i) {
            if(a[i + 1] - a[i] <= k) continue;
            ans = min(ans, (i - last) + (n - i - 1));
            last = i;
        }
        
        cout << ans << "\n";
    }
}
