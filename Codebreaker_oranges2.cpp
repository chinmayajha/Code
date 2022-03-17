#include "bits/stdc++.h"
using namespace std;
#define int long long

int n, e, qq, target;
vector<vector<pair<int, int>>> adj;
map<int, int> indd;
vector<int> a, b, seg; // a stores values, b stores nodes
// a[i] = distance between b[i] and b[i + 1];

void dfs1(pair<int, int> root, int parent) { // constructing a and b array
    for(auto& i : adj[root.first]) if(i.first != parent) dfs1(i, root.first);
    a.push_back(root.second);
    b.push_back(root.first);
}

int build(int ind, int low, int high) {
    if(high == low) return seg[ind] = a[low];
    int mid = (low + high) / 2;
    return seg[ind] = max(
        build(2 * ind + 1, low, mid),
        build(2 * ind + 2, mid + 1, high) 
    );
}

int query(int ind, int low, int high, int l, int r) {
    if(high < low || l > r || l > high || r < low) return 0;
    if(high >= r && l <= low) return seg[ind];
    int mid = (low + high) / 2;
    return max(
        query(2 * ind + 1, low, mid, l, r),
        query(2 * ind + 2, mid + 1, high, l, r)
    );
}

void subtask1() {
    seg.resize(4 * n + 4);
    int root = -1;
    for(int i = 0; i < n; ++i) if((int) adj[i].size() == 1) root = i;
    dfs1({root, 0}, -1);
    // for(auto& i : a) {cout << i << " ";} cout << "\n";
    // for(auto& i : b) {cout << i << " ";} cout << "\n";
    for(int i = 0; i < n; ++i) indd[b[i]] = i;
    
    build(0, 0, n - 1);
    for(int i = 0, x, y; i < qq; ++i) {
        cin >> x >> y;
        x = indd[x], y = indd[y];
        if(x > y) swap(x, y);
        cout << query(0, 0, n - 1, x, y) << "\n";
    }
}

int dfs(int node, vector<int>& vis) {
    
    int ans = 0;


}

void subtask2() {
    for(int i = 0, x; i < qq; ++i) {
        cin >> x >> target;
        dfs(x, -1);
    }
}

void preprocess() {
    if(e != n - 1) return;
    bool check1 = all_of(adj.begin(), adj.end(), [&](vector<pair<int, int>>& ww){return (int) ww.size() <= 2;});
    if(check1) subtask1();
    else subtask2();
}

signed main() {
    cin >> n >> e >> qq;
    adj.resize(n);
    for(int i = 0, x, y, z; i < e; ++i) {
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }
    preprocess();
}