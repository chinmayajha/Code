#include <bits/stdc++.h> 
using namespace std;

struct edges {
    int weight, x, y;
};
bool cmp(edges& a, edges& b) {
    return a.weight < b.weight;
}
struct MST {
    int n, m, cost = 0;
    vector<int> rankk, parent;
    vector<vector<pair<int, int>>> adj;
    int findpar(int x) {
        if (parent[x] == x) return x;
        return parent[x] = findpar(parent[x]);
    }
    void unite(int x, int y) {
        x = findpar(x);
        y = findpar(y);
        if(rankk[x] < rankk[y]) {
            swap(x, y);
        }
        if(rankk[x] == rankk[y]) rankk[x]++;
        parent[y] = x;
    }
    vector<edges> edge;
    MST(vector<edges> EDGES, int N) {
        edge = EDGES, n = N, m = (int) EDGES.size();
        rankk.resize(n + 1);
        parent.resize(n + 1);
        adj.resize(n + 1);
        // building the MST
        for(int i = 1; i <= n; ++i) parent[i] = i;
        sort(edge.begin(), edge.end(), cmp);
        for(auto& i : edge) {
            if(findpar(i.x) != findpar(i.y)){
                unite(i.x, i.y);
                cost += i.weight;
                adj[i.x].push_back({i.y, i.weight});
                adj[i.y].push_back({i.x, i.weight});
            }
        }
    }
    void print_MST() {
        for(int i = 1; i <= n; ++i) {
            for(auto& j : adj[i]) {
                cout << i << " " << j.first << " " << j.second << "\n";
            }
        }
    }
};

signed main() {
    int n, m; cin >> n >> m;
    vector<edges> a(n + 1);
    for(int i = 1; i <= n; ++i) cin >> a[i].x >> a[i].y >> a[i].weight;
    auto x = MST(a, 9);
    x.print_MST();
}