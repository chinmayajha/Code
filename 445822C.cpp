#include "bits/stdc++.h"
using namespace std;
// #define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        int spends = 0;
        while(n > 0) {
            spends += min(n, 10);
            n -= min(n, 9);
        }
        cout << spends << "\n";
    }
}
