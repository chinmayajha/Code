#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i].first;
        for (int i = 0; i < n; ++i) cin >> a[i].second;
        sort(a.begin(), a.end());
        int i = 0, sum = m;
        while(i < n && sum - a[i].first >= 0) {
            sum += a[i].second;
            i++;
        }
        cout << sum << "\n"; 
    }
}
