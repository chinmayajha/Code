#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    // cin >> T;
    while (T--) {
        int n, s; cin >> n >> s;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        
        int i = 0, j = 0, sum = 0, mx = 0;
        while(i < n && j < n) {
            if(sum + a[j] <= s) {
                sum += a[j];
                mx = max(mx, j - i + 1);
                j++;
            } else {
                sum -= a[i];
                i++;
            }
        }

        cout << mx;
    }
}

