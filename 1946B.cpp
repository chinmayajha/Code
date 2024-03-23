#include "bits/stdc++.h"
using namespace std;
#define int long long

const int MOD = 1000000007;

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        
        int mx = INT_MIN, cur = 0, i = 0;
        while(i < n) {
            cur += a[i]; 
            mx = max(mx, cur);
            if(cur < 0) cur = 0;
            i++;
        }
        
        int ans = accumulate(a.begin(), a.end(), 0LL);
        if(mx > 0) {
            for(int i = 1; i <= k; ++i) {
                ans += mx;
                ans = (ans + MOD) % MOD;
                mx <<= 1;
                mx = (mx + MOD) % MOD;
            }
        }
        
        while(ans < 0) {
            ans += MOD;
            ans %= MOD;
        }
    
        cout << (ans + MOD) % MOD << "\n";
    }
}
