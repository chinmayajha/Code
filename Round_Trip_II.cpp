#include "bits/stdc++.h"
using namespace std;

vector<vector<int>> a;
int n, e;
vector<int> vis, rec, path, ans;

// starting DFS from somewhere
// if we walk back into source chain, there is a cycle, add all elements in that cycle, and restart dfs

void dfs(int node) {
    // mark node visited for ENTRIE problem, and mark node visited for CURRENT recursion
    // and add it to the traversal path
    vis[node] = 1; rec[node] = 1; path.push_back(node);
    for(auto& i : a[node]) {
        // if node is new for ENTIRE problem, search there
        if(!vis[i] && !rec[i]) dfs(i);
        else if(vis[i] && rec[i]) { // if it is a part of CURRENT recursion => cycle found
            path.push_back(i);
            // start contructing the REVERSE path
            for(int j = (int) path.size() - 1; j >= 0; --j) {
                ans.push_back(path[j]);
                // when same node is met before (which should happen, as it is a cycle)
                // we contruct our output and break (as cycle is completed)
                if(path[j] == i && j != (int) path.size() - 1) {
                    cout << (int) ans.size() << "\n";
                    for(auto& kk : ans) {cout << kk << " ";} cout << "\n";
                    exit(0);
                }
            }
            return;
        }
    }
    rec[node] = 0;
    path.pop_back();
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); 
    cin >> n >> e;
    a.resize(n + 1); vis.assign(n + 1, 0); rec.assign(n + 1, 0);
    for(int i = 0, x, y; i < e; ++i) {
        cin >> x >> y;
        a[y].push_back(x);
    }
    // for disconnected graph
    for(int i = n; i <= n; ++i) if(!vis[i]) dfs(i);
    cout << "IMPOSSIBLE";
}