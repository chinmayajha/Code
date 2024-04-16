#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n; cin >> n;
        
        int sum = 0;
        for(int i = 1; i <= n; ++i) 
            sum += (2 * i - 1) * i;
        
        cout << sum << " " << 2 * n << "\n";
        for(int i = 1; i <= n; ++i) {
            cout << 1 << " " << n - i + 1 << " ";
            for(int j = 1; j <= n; ++j) cout << j << " ";
            cout << "\n";
            cout << 2 << " " << n - i + 1 << " ";
            for(int j = 1; j <= n; ++j) cout << j << " ";
            cout << "\n";
        }
    }
}

