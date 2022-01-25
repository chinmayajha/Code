#include "bits/stdc++.h"
// using namespace std;

std::vector<std::vector<int>> adj;

std::vector<std::vector<int>> up;
std::vector<int> vis, tin, tout;
int LOG, timer, N;

void dfs(int node, int parent) {
    vis[node] = 1;
    tin[node] = ++timer;
    up[node][0] = parent;
    for(int i = 1; i <= LOG; ++i) {
        up[node][i] = up[up[node][i - 1]][i - 1];
    }
    for(auto& i : adj[node]) if(!vis[i]) dfs(i, node);
    tout[node] = ++timer;
}

bool is_ancestor(int x, int y) {
    return tin[y] >= tin[x] && tout[y] <= tout[x];
}

int lca(int u, int v) {
    if(is_ancestor(u, v)) return u;
    else if(is_ancestor(v, u)) return v;
    else {
        for(int i = LOG; i >= 0; --i) {
            if(!is_ancestor(up[u][i], v)) u = up[u][i];
        }
    }
    return up[u][0];
}

void LCA(int n) {
    N = n;
    LOG = 1 + (int) ceil(log2(N));
    tin.assign(N + 1, 0);
    vis.assign(N + 1, 0);
    tout.assign(N + 1, 0);
    adj.resize(N + 1);
    up.assign(N + 1, std::vector<int>(LOG + 1));
}

signed main() {
    int n;
    std::cin >> n;
    LCA(n);
    for(int i = 0, x, y; i < n; ++i) {
        std::cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 1);
    // std::cout << lca(3, 4);
}
