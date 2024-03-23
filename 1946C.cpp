#include "bits/stdc++.h"
using namespace std;
#define int long long

int dfs(vector<vector<int>> &a, int node, int par, int x, int &cc) {
    int total = 1;

    for(auto& i : a[node]) {
        if(i == par) continue;
        total += dfs(a, i, node, x, cc);
    }

    if(total >= x) {
        cc++;
        return 0;
    } else return total;
}

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        vector<vector<int>> a(n + 1);
    
        for(int i = 1, x, y; i < n; ++i) {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }

        int mid, cc, sz, l = 1, r = n;
        while(l < r) {
            mid = (l + r + 1) >> 1;
            cc = 1, sz = dfs(a, 1, -1, mid, cc);
            if(sz < mid) cc--;

            if(cc > k) l = mid;
            else r = mid - 1;
        }

        cout << l << "\n";
    }
}

