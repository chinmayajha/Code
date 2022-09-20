#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n, cnt = 0; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < n; ++i) for(int j = i + 1; j < n; ++j) cnt += (a[j] <= a[i]);
        cout << cnt << "\n";
    }
}
