// STUPID BRACKETS ON LINE 20 -> prefOr | a[i] > temp <- WASTED MY 1 HOUR

#include "bits/stdc++.h"
using namespace std;

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n), ans;
        for(int i = 0; i < n; ++i) cin >> a[i];

        vector<int> vis(n, 0);

        int prefOr = 0;
        for(int j = 0; j < 31; ++j) {
            int temp = prefOr, mxi = -1;
            for(int i = 0; i < n; ++i) {
                if(vis[i]) continue;
                if((prefOr | a[i]) > temp) mxi = i, temp = prefOr | a[i];
            }
            if(mxi == -1) break;
            prefOr = temp;
            vis[mxi] = 1;
            ans.push_back(a[mxi]);
        }

        for(int i = 0; i < n; ++i) 
            if(!vis[i]) ans.push_back(a[i]);
        
        for(auto& i : ans) cout << i << " ";
        cout << "\n";
    }
}

