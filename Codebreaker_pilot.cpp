#include "bits/stdc++.h"
using namespace std;
#define int long long
// O(N * Q) solution, should not pass many cases

signed main() {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];

    for(auto& k : b) {
        int i = 0, ans = 0;
        while(i < n) {
            int cnt = 0;
            while(i < n &&  k >= a[i]) {
                cnt++;
                i++;
            }
            ans += cnt * (cnt + 1) / 2;
            i++;
        }
        cout << ans << "\n";
    }
}
