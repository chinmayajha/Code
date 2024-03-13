#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n; cin >> n;
        string s, t, ans; cin >> s >> t;
        
        ans = s[0];
        int change, cnt = 1; 
        bool done = 0;

        for(int i = 0; i < n; ++i) {
            if(!done && i == n - 1) {
                ans.push_back(t[i]);
                change = n - 1;
                continue;
            } 

            if(!done && s[i + 1] == '1' && t[i] == '0') {
                done = 1;
                change = i;
                ans.push_back(t[i]);
            } else {
                if(done) ans.push_back(t[i]); 
                else ans.push_back(s[i + 1]);
            }
        }

        cout << ans << "\n";

        for(int i = change; i > 0; --i) {
            if(s[i] == t[i - 1]) cnt++;
            else break;
        }

        cout << cnt << "\n";
    }
}

