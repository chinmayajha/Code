#include "bits/stdc++.h"
using namespace std;

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vector<int>> a(n, vector<int>(n));
        int cur = n * n;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                a[i][j] = cur;
                cur -= 2;
                if(cur <= 0) cur = n * n - 1;
            }
        }
        for(auto& i : a) {
            for(auto& ii : i) cout << ii << " ";
            cout << "\n";
        }
    }
}
