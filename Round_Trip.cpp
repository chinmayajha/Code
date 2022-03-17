#include "bits/stdc++.h"
using namespace std;

int n, e;
vector<vector<int>> a;
vector<int> path, vis;

void print() {
    for(int i = 0; i < (int) path.size(); ++i) {
        if(path[i] != path.back()) continue;
        int sz = (int) path.size() - i;
        if(sz <= 2) return;
        cout << sz <<  "\n";
        for(int j = i; j < (int) path.size(); ++j) cout << path[j] << " ";
        exit(0);
    }
}

void dfs(int node, int parent) {
    path.push_back(node);
    vis[node] = 1;
    for(auto& i : a[node]) {
        if(i != parent && vis[i]) {
            path.push_back(i);
            print();
        }
        if(!vis[i]) dfs(i, node);
    }
    path.pop_back();
}

signed main() {
    cin >> n >> e; a.resize(n + 1); vis.assign(n + 1, 0);
    for(int i = 0, x, y; i < e;  ++i) {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(int i = 1; i <= n; ++i){
        if(!vis[i]) dfs(i, -1);
        path.clear();
    }
    cout << "IMPOSSIBLE";
}
