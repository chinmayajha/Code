#include "bits/stdc++.h"
using namespace std;
#define int long long

int n, qq, LOG, timer;
vector<vector<int>> adj, up;
vector<int> tin, tout, height, vis;

void dfs(int node, int par) {
    tin[node] = ++timer;
    up[node][0] = par;
    for(int i = 1; i <= LOG; ++i) {
        up[node][i] = up[up[node][i - 1]][i - 1];
    }
    for(auto& i : adj[node]) if(i != par) dfs(i, node);
    tout[node] = ++timer;
}

bool is_ancestor(int x, int y) {
    return (tin[x] <= tin[y] && tout[x] >= tout[y]);
}

int lca(int x, int y) {
    if(is_ancestor(x, y)) return x;
    if(is_ancestor(y, x)) return y;
    for(int i = LOG; i >= 0; --i) {
        if(!is_ancestor(up[x][i], y)) x = up[x][i];
    }
    return up[x][0];
}

void preprocess() {
    LOG = 1 + ceil(log2(n));
    up.assign(n + 1, vector<int>(LOG + 1)); vis.assign(n + 1, 0);
    adj.resize(n + 1); height.assign(n + 1, 0);
    tin.assign(n + 1, 0); tout.assign(n + 1, 0);
    
    for(int i = 0, x, y; i < n - 1; ++i) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 1);

    queue<int> q;
    q.push(1);
    height[1] = 0;
    int dist = 0;
    while(!q.empty()) {
        int siz = (int) q.size();
        dist++;
        while(siz--) {
            int cur = q.front(); q.pop();
            vis[cur] = 1;
            for(auto& i : adj[cur]) {
                if(!vis[i]) {
                    vis[i] = 1;
                    height[i] = dist;
                    q.push(i);
                }
            }
        }

    }
}

signed main() {
    cin >> n;
    preprocess();
    cin >> qq;
    for(int i = 0, x, y, z; i < qq; ++i) {
        cin >> x >> y;
        z = lca(x, y);
        cout << 1 + height[x] + height[y] - 2 * height[z] << "\n";
    }
}