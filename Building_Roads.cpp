
#include "bits/stdc++.h"
using namespace std;
#define sz(x) ((int)(x).size())

int n, m;
bool vis[200005];
vector<int> adj[200005];
set<int> s;
vector<pair<int, int>> ans;

void dfs(int node) {
    vis[node] = 1;
    s.erase(s.find(node));
    for(auto& i : adj[node]) {
        if(!vis[i]) {
            dfs(i);
            vis[i] = 1;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i = 1; i <= n; ++i) s.insert(i);
    while(sz(s) > 0) {
        int node = *s.begin();
        dfs(node);
        if(sz(s) > 0) {
            ans.push_back(make_pair(node, *s.begin()));
            adj[node].push_back(*s.begin());
            adj[*s.begin()].push_back(node);
        }
    }
    
    cout << sz(ans) << "\n";
    for(auto& i : ans) cout << i.first << " " << i.second << "\n";
}
