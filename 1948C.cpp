#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<string> a(2);
        cin >> a[0] >> a[1];

        vector<vector<bool>> vis(2, vector<bool>(n, 0));
        auto valid = [&] (int i, int j) {
            return (i >= 0 && i < 2 && j >= 0 && j < n && vis[i][j] == 0);
        };

        queue<pair<int, int>> q;
        q.push({0,0});

        while(!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            if(vis[i][j]) continue;
            vis[i][j] = 1;
            // i will always START at an even (i + j) - (1,1) ; (0,0)
            if((i + j) % 2 == 0) {
                if(valid(i + 1, j)) q.push({i + 1, j});
                if(valid(i, j + 1)) q.push({i, j + 1});
                if(valid(i, j - 1)) q.push({i, j - 1});
                if(valid(i - 1, j)) q.push({i - 1, j});
            } else {
                if(a[i][j] == '>') {
                    if(valid(i, j + 1)) q.push({i, j + 1});
                } else {
                    if(valid(i, j - 1)) q.push({i, j - 1});
                }
            }
        }

        cout << (vis[1][n - 1] ? "YES" : "NO") << "\n";
    }
}

