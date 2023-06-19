#include "bits/stdc++.h"
using namespace std;

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        int ans = 0;
        vector<vector<int>> a(n + 1);
        vector<pair<int, int>> edges;
        for(int i = 0, x, y; i < n - 1; ++i) {
            cin >> x >> y;
            if(x > y) swap(x, y);
            edges.insert({x, y});
        }
        cout << ans << "\n";
    }
}
