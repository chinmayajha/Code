#include "bits/stdc++.h"
using namespace std;

vector<vector<int>> a, up;
int n, q, x, k, LOG;

void dfs(int node, int parent) {
    up[node][0] = parent;
    for(int i = 1; i < LOG; ++i) {
        if(up[node][i - 1] >= 0) {
            up[node][i] = up[up[node][i - 1]][i - 1];
        }
    }
    for(auto& i : a[node]) if(i != parent) dfs(i, node);
}

void query() {
    for(int i = 0; i <= LOG; ++i) {
        if((1 << i) & k) x = up[x][i];
        if(x == -1) break;
    }
    cout << x << "\n";
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> q;
    LOG = 1 + ceil(log2(n + 1));
    a.resize(n + 1); up.assign(n + 1, vector<int>(LOG + 1, -1));
    for(int i = 2; i <= n; ++i) {
        cin >> x;
        a[x].push_back(i);
        a[i].push_back(x);
    }
    dfs(1, -1);
    while(q--) {
        cin >> x >> k;
        query();
    }
}
