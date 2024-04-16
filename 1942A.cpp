#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        if(n == k) {
            while(k--) cout << "1 ";
            cout << "\n";
        } else if (k == 1) {
            while(n-- > 1) cout << "1 ";
            cout << "2\n";
        } else cout << "-1\n";
    }
}

