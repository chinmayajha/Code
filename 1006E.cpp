#include "bits/stdc++.h"
using namespace std;
#define int long long

int n, q;
vector<vector<int>> a;
vector<bool> vis;
vector<int> ans;

void dfs(int v) {
    vis[v] = true;
    for (int u : a[v]) if (!vis[u]) dfs(u);
    ans.push_back(v);
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> q;
    a.resize(n + 1);
    vis.assign(n + 1, 0);
    vector<int> state(n + 100), topological_sort;
    for(int i = 1, x; i <= n - 1; ++i) {
        cin >> x;
        a[x].push_back(i);

        cout << x << " " << i << endl;
    }
    for(auto& i : a) sort(i.begin(), i.end());
    
    dfs(1);
    reverse(ans.begin(), ans.end());

    for(auto& i : ans) {cout << i << " ";} cout << "\n";
}
