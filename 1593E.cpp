#include "bits/stdc++.h"
using namespace std;

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<vector<int>> a(n + 1);
        vector<int> vis(n + 1, 0), degrees(n + 1, 0);
        for(int i = 0, x, y; i < n - 1; ++i) {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
            degrees[x]++;
            degrees[y]++;
        }
        if(k >= n) {
            cout << "0\n";
            continue;
        }
        deque<int> q;
        for(int i = 1; i <= n; ++i) {
            if((int)(a[i].size()) == 1) {
                q.push_back(i);
                vis[i] = 1;
            }
        }
        int temp = 1;
        while(temp < k && !q.empty()) {
            temp += 1;
            int x = q.size();
            for(int j = 0; j < x; ++j) {
                int cur = q.front(); q.pop_front();
                for(auto& i : a[cur]) {
                    degrees[i]--;
                    if(degrees[i] != 1) continue;
                    q.push_back(i);
                    vis[i] = 1;
                }
            }
        }

        n -= (accumulate(vis.begin(), vis.end(), 0ll));
        cout << n << "\n";
    }
}
