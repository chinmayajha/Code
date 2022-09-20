#include "bits/stdc++.h"
using namespace std;

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n, ans; cin >> n;
        if(n >= 1900) ans = 1;
        else if(n >= 1600) ans = 2;
        else if(n >= 1400) ans = 3;
        else ans = 4;
        cout << "Division " << ans << "\n";
    }
}
