#include "bits/stdc++.h"
using namespace std;

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<string> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];

        for(int i = n - 1; i >= 0; --i) for(int j = m - 1; j >= 0; --j) {
            if(a[i][j] != '*') continue;
            for(int k = i + 1; k < n; ++k) {
                if(a[k][j] != '.') {
                    a[i][j] = '.';
                    a[k - 1][j] = '*';
                    break;
                } else if(k == n - 1) {
                    a[i][j] = '.';
                    a[n - 1][j] = '*';
                }
            }
        }
        
        for(auto& i : a) cout << i << "\n";
        cout << "\n";
    }
}
