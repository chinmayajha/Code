#include "bits/stdc++.h"
using namespace std;

int dist = 0, mx_node = -1;

void dfs(int node, vector<vector<int>>& a, int cur_dist, int parent) {
    if(cur_dist > dist) mx_node = node, dist = cur_dist;

    for(auto& i : a[node]) {
        if(i != parent) dfs(i, a, cur_dist + 1, node);
    }
}

signed main() {
    int n; cin >> n;
    vector<vector<int>> a(n + 1);

    for(int i = 1, x, y; i < n; ++i) {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    dfs(1, a, 0, -1);
    dist = 0;
    dfs(mx_node, a, 0, -1);

    cout << dist;
}
