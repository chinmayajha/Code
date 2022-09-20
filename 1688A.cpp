#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    int t = 1; cin >> t; while (t--) {
        int n, ans = 0; cin >> n;
        for(int i = 0; i < 31; ++i) {
            int k = (1ll << i);
            if((k & n) > 0) {
                ans = (ans | k);
                break;
            }
        }
        if(ans == n) {
            for(int i = 0; i < 31; ++i) {
                if(((1ll << i) & ans) != 1) {
                    ans = (ans | (1ll << i));
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
}
