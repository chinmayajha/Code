#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        // 2n - 2 2s and 2 1s
        // m = 2*(2n-2) + k*1 where k = [0,1,2]
        // print n + k

        // takes both 1s
        int x = (2 * n - 2) * 2 + 2;
        // takes one 1
        int y = (2 * n - 2) * 2 + 1;
        if(x == m) {
            cout << 2 * n << "\n";
        } else if(y == m) {
            cout << 2 * n - 1 << "\n";
        } else {
            if(m % 2 == 1) m++;
            cout << (m / 2) << "\n";
        }
        
    }
}