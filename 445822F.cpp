#include "bits/stdc++.h"
using namespace std;

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n + 1, 0), diff(n + 2, 0);
        for(int i = 1; i <= n; ++i) cin >> a[i];

        int q, x, y; cin >> q;
        while(q--) {
            cin >> x >> y;
            diff[x] += 1;
            diff[y + 1] -= 1;
        }
        for(int i = 1; i <= n; ++i) diff[i] += diff[i - 1];
        for(int i = 1; i <= n; ++i) diff[i] *= i;
        sort(diff.begin() + 1, diff.end() - 1);
        sort(a.begin() + 1, a.end());
        
        int ans = 0;
        for(int i = 1; i <= n; ++i) ans += a[i] * diff[i];
        cout << ans << "\n";
    }
}


// (freq * index) * element
// First diff stores frequency of each index (diff array)
// then i convert it into (freq * index) and sort it
// And then i calculate ans based on that (f * i) * a_i 
// After sorting a