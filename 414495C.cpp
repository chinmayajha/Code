#include "bits/stdc++.h"
using namespace std;
#define int long long
// #include "debug.hpp"

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    // cin >> t;
    while (t--) {
        int n, cnt = 0; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        
        for(int i = 0; i < n - 2; ++i) {
            if(a[i] + a[i + 1] == a[i + 2] || abs(a[i] - a[i + 1]) == a[i + 2]) cnt += 1;
        }
        cout << cnt << '\n';
    }
}
