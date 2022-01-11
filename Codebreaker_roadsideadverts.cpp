#include "bits/stdc++.h"
using namespace std;
#define int long long

int n, q;
vector<vector<pair<int, int>>> a(50001);
vector<vector<int>> aa(50001);

vector<int> height, euler, first, segtree;
vector<bool> visited;

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

void LCA(vector<vector<int>> &adj, int root = 0) {
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

vector<int> dist(50001), dfs_number(50001);
int temp2;
int dfs2(int node, int cur_dist = 0, int parent = -1) {
    dfs_number[node] = temp2;
    temp2++;
    dist[node] = cur_dist;
    int ans = 0;
    for(auto& i : a[node]) {
        if(i.first == parent) continue;
        ans += dfs2(i.first, cur_dist + i.second, node);
    }
    return ans;
}

int calc_dist(int x, int y) {
    int temp = lca(x, y);
    return dist[x] + dist[y] - 2 * dist[temp];
}

bool cmp(int x, int y) {
    return dfs_number[x] < dfs_number[y];
}

signed main() {
    cin >> n;
    for(int i = 0; i < n - 1; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        a[x].push_back(make_pair(y, w));
        a[y].push_back(make_pair(x, w));
        aa[x].push_back(y);
        aa[y].push_back(x);
    }
    LCA(aa, 0); // calculate LCAs
    dfs2(0); // calculate dist from root
    cin >> q;
    while(q--) {
        vector<int> x(5);
        for(int i = 0; i < 5; ++i) cin >> x[i];
        // sort according to height in tree, so that DFS occurs in increasing order
        sort(x.rbegin(), x.rend(), cmp);
        int w = lca(x[0], x[1]);
        w = lca(w, x[2]);
        w = lca(w, x[3]);
        w = lca(w, x[4]);// common LCA found
        // calculate distance of node from LCA
        int ans = calc_dist(w, x[0]);
        ans += calc_dist(x[1], lca(x[1], x[0]));
        ans += calc_dist(x[2], lca(x[2], x[1]));
        ans += calc_dist(x[3], lca(x[3], x[2]));
        ans += calc_dist(x[4], lca(x[4], x[3]));
        cout << ans << "\n";
    }
}