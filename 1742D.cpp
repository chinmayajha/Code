#include "bits/stdc++.h"
using namespace std;
#define int long long

// Efficient GCD Calc
int ef_gcd(int a, int b) {
    // Source : https://en.algorithmica.org/hpc/analyzing-performance/gcd/
    if (a == 0) return b;
    if (b == 0) return a;
    int az = __builtin_ctz(a);
    int bz = __builtin_ctz(b);
    int shift = std::min(az, bz);
    b >>= bz;
    while (a != 0) {
        a >>= az;
        int diff = b - a;
        az = __builtin_ctz(diff);
        b = std::min(a, b), a = std::abs(diff);
    }
    return b << shift;
}

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    
    // preprocessing all coprimes
    vector<vector<int>> cop(1001, vector<int>(1001, 0));
    for(int x = 1; x <= 1000; ++x) {
        for(int y = 1; y <= 1000; ++y) {
            if(ef_gcd(x, y) == 1) cop[x].push_back(y);
        }
    }

    cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n), last(1001, -1);
        for(int i = 0; i < n; ++i) cin >> a[i], last[a[i]] = i + 1;

        int ans = -1;
        for(int i = 1; i <= 1000; ++i) {
            for(auto& j : cop[i]) {
                if(last[i] != -1 && last[j] != -1) ans = max(ans, last[i] + last[j]);
            }
        }

        cout << ans << "\n";
    }
}

