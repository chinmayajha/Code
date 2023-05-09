#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        string ans = "NO\n";

        queue<int> q;
        q.push(n);
        while(!q.empty()) {
            int x = q.front(); q.pop();
            if(x == m) {
                ans = "YES\n";
                break;
            }
            if(x % 3 == 0) {
                q.push(x / 3);
                q.push(2 * x / 3);
            }
        }
        cout << ans;
    }
}
