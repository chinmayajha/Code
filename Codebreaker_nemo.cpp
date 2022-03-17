
#include "bits/stdc++.h"
using namespace std;
#define int long long

int n, e, qq, in, target;
vector<vector<vector<int>>> adj;

bool cantgo(int l, int r) {
    return (in < l || in > r);
}

bool dfs(int node, vector<int>& vis) {
    vis[node] = 1;
    bool check = 0;
    for(auto& i : adj[node]) {
        if(vis[i[0]] || cantgo(i[1], i[2])) continue;
        if(i[0] == target) {
            check = 1;
            break;
        }
        check = max(check, dfs(i[0], vis));
    }
    return check;
}

vector<int> parent, siz, vis2;
int findpar(int x) {
    if(x == parent[x]) return x;
    return parent[x] = findpar(parent[x]);
}
void unite(int x, int y) {
    x = findpar(x);
    y = findpar(y);
    if(x == y) return;
    if(siz[y] > siz[x]) swap(x, y);
    siz[x] += siz[y];
    parent[y] = x;
}
void dfs2(int node, int par) {
    vis2[node] = 1;
    if(par != -1) unite(node, par);
    for(auto& i : adj[node]) {
        if(!vis2[i[0]]) dfs2(i[0], node);
    }
}
void preprocess() {
    for(auto& j : adj) for(auto& i : j) if(i[1] != 0 || i[2] != 2000000000) return;
    siz.assign(n, 1); parent.resize(n); vis2.assign(n, 0); for(int i = 0; i < n; ++i) parent[i] = i;
    for(int i = 0; i < n; ++i) if(!vis2[i]) dfs2(i, -1);
    cin >> qq;
    for(int i = 0, x, y, z; i < qq; ++i) {
        cin >> x >> y >> z;
        if(findpar(x) == findpar(y)) cout << "Y\n";
        else cout << "N\n";
    }
    exit(0);
}

signed main() {
    cin >> n >> e;
    adj.resize(n);
    for(int i = 0, w, x, y, z; i < e; ++i) {
        cin >> w >> x >> y >> z;
        adj[w].push_back({x, y, z});
        adj[x].push_back({w, y, z});
    }
    preprocess();
    cin >> qq;
    for(int i = 0, x, y, z; i < qq; ++i) {
        cin >> x >> y >> z;
        in = z, target = y;
        vector<int> vis(n, 0);
        bool check = dfs(x, vis);
        cout << (check ? "Y\n" : "N\n");
    }
}