#include "bits/stdc++.h"
using namespace std;

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n, q, x, y; cin >> n >> q;
        map<int, vector<int>> mp;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            mp[x].push_back(i + 1);
        }
        while(q--) {
            cin >> x >> y;
            // Go from x to y
            // x [i1..i2] and y [i3 .. i4]
            // if ranges are disjoint, we can't visit else YES
            if(!mp[x].size() || !mp[y].size() || mp[x][0] > mp[y].back()) cout << "NO\n";
            else cout << "YES\n";
        }
    }
}
