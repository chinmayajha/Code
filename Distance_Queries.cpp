#include "bits/stdc++.h"
using namespace std;

vector<vector<int>> a, up;
vector<int> tin, tout, dis;
int n, q, k, LOG, timer, lca;

void dfs(int node, int parent) {
    dis[node] = 1 + dis[parent];
    tin[node] = ++timer;
    up[node][0] = parent;
    for(int i = 1; i < LOG; ++i) {
        up[node][i] = up[up[node][i - 1]][i - 1];
    }
    for(auto& i : a[node]) if(i != parent) dfs(i, node);
    tout[node] = ++timer;
}

bool is_ancestor(int l, int r) {
    return (tin[l] <= tin[r] && tout[r] <= tout[l]);
}

int query(int x, int y) {
    if(is_ancestor(x, y)) return x;
    if(is_ancestor(y, x)) return y;
    for(int i = LOG - 1; i >= 0; --i) {
        if(!is_ancestor(up[x][i], y)) x = up[x][i];
    }
    return up[x][0];
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> q;
    LOG = 1 + ceil(log2(n + 1));
    a.resize(n + 1); up.assign(n + 1, vector<int>(LOG + 1));
    tin.assign(n + 1, 0); tout.resize(n + 1, 0); dis.resize(n + 1, 0);
    for(int i = 2, x, y; i <= n; ++i) {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    
    dfs(1, 1);
    while(q--) {
        int x, y; cin >> x >> y;
        lca = query(x, y);
        cout << dis[x] + dis[y] - 2 * dis[lca] << "\n";   
    }
}
