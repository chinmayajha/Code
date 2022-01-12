#include "bits/stdc++.h"
using namespace std;
#define int long long

int n, q;
vector<vector<int>> a;
vector<bool> vis;
vector<int> ans;

struct LCA {
    vector<int> height, euler, first, segtree;
    vector<bool> visited;
    int n;

    LCA(vector<vector<int>> &adj, int root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(adj, root);
        int m = euler.size();
        segtree.resize(m * 4);
        build(1, 0, m - 1);
    }

    void dfs(vector<vector<int>> &adj, int node, int h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs(adj, to, h + 1);
                euler.push_back(node);
            }
        }
    }

    void build(int node, int b, int e) {
        if (b == e) {
            segtree[node] = euler[b];
        } else {
            int mid = (b + e) / 2;
            build(node << 1, b, mid);
            build(node << 1 | 1, mid + 1, e);
            int l = segtree[node << 1], r = segtree[node << 1 | 1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }

    int query(int node, int b, int e, int L, int R) {
        if (b > R || e < L)
            return -1;
        if (b >= L && e <= R)
            return segtree[node];
        int mid = (b + e) >> 1;

        int left = query(node << 1, b, mid, L, R);
        int right = query(node << 1 | 1, mid + 1, e, L, R);
        if (left == -1) return right;
        if (right == -1) return left;
        return height[left] < height[right] ? left : right;
    }

    int lca(int u, int v) {
        int left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }
};

void dfs(int v) {
    vis[v] = true;
    ans.push_back(v);
    for (int u : a[v]) if (!vis[u]) dfs(u);
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> q;
    a.resize(n + 1);
    vis.assign(n + 1, 0);
    vector<int> state(n + 100), topological_sort;
    for(int i = 1, x; i <= n - 1; ++i) {
        cin >> x;
        a[x].push_back(i + 1);
    }
    for(auto& i : a) sort(i.begin(), i.end());
    dfs(1); // stored the DFS order in ans

    for(auto& i : ans) {cout << i << " ";} cout << "\n";

    vector<int> index(200010, 0);
    for(int i = 0; i < (int)ans.size(); ++i) index[ans[i]] = i;

    auto k = LCA(a, 1);

    for(int w = 0, x, y; w < q; ++w) {
        cin >> x >> y; //x se yth element
        y--;
        int i = index[x];
        if(i + y >= (int)ans.size() || k.lca(x, ans[i + y]) != x) cout << "-1";
        else cout << ans[i + y];

        cout << "\n";
    }
}
