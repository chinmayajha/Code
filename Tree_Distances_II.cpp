
#include "bits/stdc++.h"
using namespace std;

const int64_t N = 2e5 + 10;
int64_t n, p, q;
vector<int64_t> adj[N];
int64_t subnodes[N], dist[N], ans[N];

void dfs(int64_t node, int64_t parent) {
    subnodes[node] = 1;
    for(auto& i : adj[node]) {
        if(i == parent) continue;
        dfs(i, node);
        subnodes[node] += subnodes[i];
        dist[node] += subnodes[i] + dist[i];
    }
}

void dfs2(int64_t node, int64_t parent) {
    ans[node] = ans[parent] - (subnodes[node]) + (n - subnodes[node]);

    for(auto& i : adj[node]) {
        if(i == parent) continue;
        dfs2(i, node);
    }
}

void solve(){
    cin >> n;
    if(n == 1) {
        cout << 0;
        return;
    }
    for(int64_t i = 0; i < n - 1; ++i) {
        cin >> p >> q;
        adj[p].push_back(q);
        adj[q].push_back(p);
    }

    dfs(1, -1); //calculates subtree size for each node
    ans[1] = dist[1];

    for(auto& i : adj[1]) dfs2(i, 1); 
    
    /* ^^^^^^^^^^^ calculating answer by the formula : 
     = ans[parent] - no. of nodes moving farther + no. of nodes coming closer
     = ans[parent] - subnodes[node] + (total - subnodes[node]) */

    for(int64_t i = 1; i <= n; ++i) cout << ans[i] << " ";

}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int testt = 1;
    // cin >> testt;
    for (int i = 1; i <= testt; ++i){
        // cout << "Case #" << i << ": ";
        solve();
    }
}



