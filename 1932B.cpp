#include "bits/stdc++.h"
using namespace std;
#define int long long

int ceild(int x, int y) {
    return (x + y - 1) / y;
}

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n + 1, 0);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        
        for (int i = 1; i <= n; ++i) {
            // a[i] = multiple of a[i] just larger than a[i - 1]
            if(a[i - 1] < a[i]) continue;
            a[i] =  a[i] * ceild(a[i - 1] + 1, a[i]);
        }
        
        cout << a[n] << "\n";
    }
}

