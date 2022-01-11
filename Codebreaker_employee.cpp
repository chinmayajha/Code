#include "bits/stdc++.h"
using namespace std;
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define int long long

vector<vector<int>> a(1000010);
set<int> s;
int nn;
vector<int> ans(1000010, 0);

void dfs(int node = 0, int temp = 0, int parent = -1) {
    s.insert(temp);
    for(auto& i : a[node]) {
        if(i != parent) dfs(i, temp + 1, node);
    }
} 

signed main() {
    cin >> nn;
    for (int i = 0; i < nn - 1; ++i){
        int x; cin >> x;
        a[x].push_back(i + 1);
        a[i + 1].push_back(x);
    }
    dfs();
    cout << (int)(s.size());
}

/*
TLE LCA APPROACH HERE
#include "bits/stdc++.h"
using namespace std;
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define int long long

vector<int> height, euler, first, segtree;
vector<bool> visited;

vector<vector<int>> a(1000010);
set<int> s;
int nn;

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
    int n = adj.size();
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

signed main() {
    cin >> nn;
    for (int i = 0; i < nn - 1; ++i){
        int x; cin >> x;
        a[x].push_back(i + 1);
        a[i + 1].push_back(x);
    }
    LCA(a, 0);
    for(int i = 0; i < nn; ++i) s.insert(i);
    
    int cnt = 0;
    while(!s.empty()) {
        cnt++;
        int x = *s.begin();
        s.erase(x);
        if(!s.empty()) for(int i : s) {
            int ancestor = lca(i, x);
            if(ancestor != x && ancestor != i) {
                s.erase(i);
            }
        }
    }
    cout << cnt;
}
*/