#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n, m, ans = 0; cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) cin >> a[i][j];
        
        // iterate over diagonals of each cell
        for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) {
            int curi = i, curj = j;
            int sum = 0;
            // moving topleft
            while(curi >= 0 && curj >= 0) {
                sum += a[curi][curj];
                curi--; curj--;
            }
            curi = i; curj = j;
            // moving topright
            while(curi >= 0 && curj < m) {
                sum += a[curi][curj];
                curi--; curj++;
            }
            curi = i; curj = j;
            // moving bottomleft
            while(curi < n && curj >= 0) {
                sum += a[curi][curj];
                curi++; curj--;
            }
            curi = i; curj = j;
            // moving bottomright
            while(curi < n && curj < m) {
                sum += a[curi][curj];
                curi++; curj++;
            }
            sum -= (3 * a[i][j]);
            ans = max(ans, sum);
        }
        cout << ans << "\n";
    }
}
