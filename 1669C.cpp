#include "bits/stdc++.h"
using namespace std;

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        string ans = "YES\n";
        for(int i = 0; i < n; i += 2) if(a[i] % 2 != a[0] % 2) ans = "NO\n";
        if(n > 1) for(int i = 1; i < n; i += 2) if(a[i] % 2 != a[1] % 2) ans = "NO\n";
        cout << ans;
    }
}
