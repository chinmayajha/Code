#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n + 1);
    vector<int> incoming(n + 1, 0), ans(n + 1);
    for(int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y;
        a[y].push_back(x);
    }
    queue<int> x;
    for(int i = 1; i <= n; ++i) for(auto& k : a[i]) incoming[k]++;
    for(int i = 1; i <= n; ++i) if(!incoming[i]) x.push(i);

    while(!x.empty()) {
        int cur = x.front();
        x.pop();
        for(auto& i : a[cur]) {
            incoming[i]--;
            if(incoming[i] == 0) {
                ans[i] = 1 + ans[cur];
                x.push(i);
            }
        }
    }

    for(int i = 1; i <= n; ++i) cout << ans[i] << " ";
}
