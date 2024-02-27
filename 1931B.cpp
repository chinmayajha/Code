#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        
        int per = accumulate(a.begin(), a.end(), 0LL) / n, sum = 0;
        string ans = "YES";

        for(int i = 0; i < n; ++i) {
            sum += a[i];
            if(sum < per * (i + 1)) {
                ans = "NO";
                break;
            }
        }

        cout << ans << "\n";
    }
}