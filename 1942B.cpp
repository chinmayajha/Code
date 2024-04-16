#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n, mex = 0; cin >> n;
        vector<int> a(n), ans, vis(n + 1, 0);
        for(int i = 0; i < n; ++i) cin >> a[i];

        for(int i = 0; i < n; ++i) {
            if(a[i] >= 0) ans.push_back(mex);
            else ans.push_back(mex - a[i]);

            vis[ans.back()] = 1;
            while(vis[mex]) mex++;
        }

        for(auto& i : ans) cout << i << " ";
        cout << "\n";
    }
}

