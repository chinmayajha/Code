#include "bits/stdc++.h"
using namespace std;

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        for(int i = 1; i <= n; ++i) cout << 2 * i << " ";
        cout << "\n";
    }
}
