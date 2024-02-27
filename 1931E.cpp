#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        vector<int> a(n, 0);
        
        int plus = 0;
        for(int i = 0, x, y; i < n; ++i) {
            cin >> x; y = x;
            while(x > 0 && x % 10 == 0) {
                a[i]--;
                x /= 10;
            }
            while(y > 0) {
                y /= 10;
                plus++;
            }
        }

        shuffle(a.begin(), a.end(), rng); sort(a.begin(), a.end());
        for(int i = 0; i < n; i += 2) plus += a[i];

        cout << (plus <= m ? "Anna" : "Sasha") << "\n";
    }
}

