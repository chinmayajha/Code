#include "bits/stdc++.h"
using namespace std;
#define int long long
 
signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int cnt = 0, ans = 1, temp, k, x, a; cin >> k >> x >> a;
        temp = a;
        for(int i = 0; i < x; ++i) {
            if(temp <= 0) {
                ans = 0;
                break;
            }
            cnt = 1 + ((a - temp) / (k - 1));
            temp -= cnt;
        }
 
        cout << (ans && temp * k > a ? "YES\n" : "NO\n");
    }
}