#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n; cin >> n;
        map<int, int> mp;
        for(int i = 0, x; i < n; ++i) cin >> x, mp[x]++;
        
        int cnt = 0, ans = -1;
        for(int i = 0; i <= n; ++i) {
            cnt += (mp[i] == 1);
            if(mp[i] == 0 || cnt == 2) {
                ans = i;
                break;
            }
        }
        
        cout << ans << "\n";
    }
}

