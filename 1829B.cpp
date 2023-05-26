#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n, mx = 0; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        
        int i = 0;
        while(i < n) {
            int cur = 0;
            while(i < n && a[i] == 0) ++cur, ++i;
            i++;
            mx = max(mx, cur);
        }

        cout << mx << "\n";
    }
}
