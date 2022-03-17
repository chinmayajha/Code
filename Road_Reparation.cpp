// https://cses.fi/problemset/task/1675
#include "bits/stdc++.h"
using namespace std;
#define int long long

int n, e, ans, cnt;
vector<vector<int>> edges, a;
vector<int> parent, siz, vis;

void dfs(int node) {
    vis[node] = 1;
    cnt++;
    for(auto& i : a[node]) if(!vis[i]) dfs(i);
}

int findpar(int x) {
    if(parent[x] == x) return x;
    return parent[x] = findpar(parent[x]);
}

void unite(int w, int x, int y) {
    x = findpar(x);
    y = findpar(y);
    if(x == y) return;
    ans += w;
    if(siz[y] > siz[x]) swap(x, y);
    siz[x] += siz[y];
    parent[y] = x;
}

signed main() {
	cin >> n >> e;
    a.resize(n + 1); vis.assign(n + 1, 0);
    parent.resize(n + 1); siz.assign(n + 1, 1);
    for(int i = 0; i <= n; ++i) parent[i] = i;
	for(int i = 0, x, y, z; i < e; ++i) {
		cin >> x >> y >> z;
        a[x].push_back(y);
        a[y].push_back(x);
		edges.push_back({z, x, y});
	}
    dfs(1);
    if(cnt != n) {
        cout << "IMPOSSIBLE";
        exit(0);
    }
	sort(edges.begin(), edges.end());
	for(auto& i : edges) {
		unite(i[0], i[1], i[2]);
	}
    cout << ans;
}