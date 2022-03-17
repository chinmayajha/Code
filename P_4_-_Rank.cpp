#include "bits/stdc++.h"
using namespace std;
#define int long long

vector<vector<int>> a;
int n, e;
vector<int> vis, rec, path;
set<int> finset;

// starting DFS from somewhere
// if we walk back into source chain, there is a cycle, add all elements in that cycle, and restart dfs

void dfs(int node) {
    vis[node] = 1; rec[node] = 1; path.push_back(node);
    for(auto& i : a[node]) {
        if(!vis[i] && !rec[i]) dfs(i);
        else if(rec[i]) { // cycle found
            path.push_back(i);
            for(int j = (int) path.size() - 1; j >= 0; --j) {
                finset.insert(path[j]);
                if(path[j] == i && j != (int) path.size() - 1) break;
            }
            return;
        } 
    }
    rec[node] = 0;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); 
    cin >> n >> e;
    a.resize(n + 1); vis.assign(n + 1, 0); rec.assign(n + 1, 0);
    for(int i = 0, x, y, p, q; i < e; ++i) {
        cin >> x >> y >> p >> q;
        if(p < q) swap(x, y);
        a[x].push_back(y);
    }
    for(int i = 1; i <= n; ++i) for(auto& j : a[i]) cout << i << " " << j << endl;
    return 0;
    for(int i = 1; i <= n; ++i) if(!vis[i]) dfs(i);
    
     
    cout << (int) finset.size();
}