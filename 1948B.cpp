#include "bits/stdc++.h"
using namespace std;
// #define int long long

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        
        int last = INT_MAX;
        string ans = "YES";
        for(int i = n - 1; i >= 0; --i) {
            if(last >= a[i]) {
                last = a[i];
                continue;
            } else {
                // split a[i] now
                // last becomes the first digit of this number
                while(a[i] > 0) {
                    if(a[i] % 10 > last) {
                        ans = "NO";
                        break;
                    }
                    last = a[i] % 10;
                    a[i] /= 10;
                }
            }
        }

        cout << ans << "\n";
    }
}


