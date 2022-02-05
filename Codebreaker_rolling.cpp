#include "bits/stdc++.h"
using namespace std;
#define int long long

int n, q, x, y, ans;
vector<int> parent, vis;
vector<vector<int>> adj;

void dfs(int node, int& balls) {
    for(auto& i : adj[node]) {
        if(vis[i]) continue;
        dfs(i, balls);
    }
    if(balls > 0) {
        balls--;
        vis[node] = 1;
    }
    if(balls == 0 && ans == -1) {
        ans = node;
        return;
    }
}

void dfs(int node) {
    for(auto& i : adj[node]) {
        if(vis[i]) continue;
        dfs(i);
    }
    ans.push_back(node);
}

signed main() {
    cin >> n >> q;
    parent.resize(n + 1);
    adj.resize(n + 1);
    vis.assign(n + 1, 0);
    for(int i = 1; i <= n; ++i) {
        cin >> parent[i];
        if(parent[i] != 0) adj[parent[i]].push_back(i);
    }
    
    int root = -1;
    for(int i = 1; i <= n; ++i) if(parent[i] == 0) root = i;

    while(q--) {
        cin >> x >> y;
        if(x == 2) {
            int cnt = 0;
            while(vis[parent[y]] && y != root) {
                y = parent[y];
                cnt += 1;
            }
            vis[y] = 0;
            cout << cnt << "\n";
        }
         else {
             ans = -1;
            dfs(root, y);
            cout << ans << "\n";
        }
    }
}

/*
