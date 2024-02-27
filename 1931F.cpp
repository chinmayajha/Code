#include "bits/stdc++.h"
using namespace std;
#define int long long

bool checkCycle(int node, vector < int > adj[], int vis[], int dfsVis[]) {
    vis[node] = 1;
    dfsVis[node] = 1;
    for (auto it: adj[node]) {
        if (!vis[it]) {
            if (checkCycle(it, adj, vis, dfsVis)) return 1;
        } else if (dfsVis[it]) return 1;
    }
    dfsVis[node] = 0;
    return 0;
}

bool isCyclic(int N, vector <int> adj[]) {
    int vis[N], dfsVis[N];

    for(int i = 0; i < N; i++){
        vis[i] = 0;
        dfsVis[i] = 0;
    }

    for (int i = 0; i < N; i++) {
        if (!vis[i]) {
            if (checkCycle(i, adj, vis, dfsVis)) return 1;
        }
    }
    return 0;
}

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;

        vector<int> g[n + 10];
        for(int j = 0; j < m; ++j) {
            vector<int> a(n);
            for (int i = 0, x; i < n; ++i) cin >> a[i];
            for (int i = 2; i < n; ++i) g[a[i - 1]].push_back(a[i]); // edge from i - 1 to i
        }
        
        if(isCyclic(n + 10, g)) cout << "NO\n";
        else cout << "YES\n";
    }
}