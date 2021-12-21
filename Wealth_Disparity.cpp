
#include "bits/stdc++.h"
using namespace std;
#define int long long

int n, root, fin = INT_MIN;
vector<int> adj[100005];
vector<int> a(100001);

int dfs(int node) {
    int ans = INT_MAX;
    for(auto& i : adj[node]) ans = min(ans, dfs(i));

    fin = max(fin, a[node] - ans);
    return min(a[node], ans);
}

signed main() {
    cin >> n;
    if(n == 1) {
        cout << 0;
        return 0;
    }
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        if(x != -1) adj[x].push_back(i);
        else root = i;
    }

    dfs(root);
    cout << fin;
}
