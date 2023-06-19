#include "bits/stdc++.h"
using namespace std;

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        
        if(a) {
            int ans = a, pairs = min(b, c);
            ans += 2 * pairs;
            b -= pairs;
            c -= pairs;
            ans += min(a + 1, d + abs(b - c));
            cout << ans << "\n";
        } else cout << "1\n";
    }
}
