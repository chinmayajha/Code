
#include "bits/stdc++.h"
using namespace std;
#define int long long

void solution2() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(n, INT_MAX));
    for(int i = 0; i < m; ++i) {
        int x, y, z; cin >> x >> y >> z;
        x--; y--;
        a[x][y] = z, a[y][x] = z;
    }

    for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) {
        a[i][j] = a[i][j];
        a[i][i] = 0;
    }

    for(int k = 0; k < n; ++k) 
    for(int i = 0; i < n; ++i) 
    for(int j = 0; j < n; ++j) {
        a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
    }
    
    int ans = INT_MIN;
    for(auto& i : a) for(auto& j : i) ans = max(ans, j);
    cout << ans;
}

signed main() {
    solution2();
    return 0;

    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> a(n);
    for(int i = 0; i < m; ++i) {
        int x, y, z; cin >> x >> y >> z;
        x--; y--;
        a[x].push_back({y, z});
        a[y].push_back({x, z});
    }
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    for(int i = 0; i < n; ++i) {
        dist[i][i] = 0;
        set<pair<int, int>> s;
        s.insert({0, i}); // distance, node
        while(!s.empty()) {
            auto x = *s.begin();
            s.erase(x);
            for(auto& node : a[x.second]) {
                int newdist = dist[i][x.second] + node.second;
                if(dist[i][node.first] > newdist) {
                    s.erase({dist[i][node.first], node.first});
                    dist[i][node.first] = newdist;
                    s.insert({dist[i][node.first], node.first});
                }
            }
        }
    }

    int ans = INT_MIN;
    for(auto& i : dist) for(auto& j : i) ans = max(ans, j);
    cout << ans;
}