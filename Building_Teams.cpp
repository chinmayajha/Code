#include "bits/stdc++.h"
using namespace std;

int n, e;
vector<vector<int>> adj;
vector<int> vis;
int color = 1;

signed main() {
    cin >> n >> e;
    adj.resize(n + 1);
    vis.assign(n + 1, 0);
    for(int i =  0, x, y; i < e; ++i) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    for(int k = 1; k <= n; ++k) {
        if(vis[k]) continue;
        queue<int> q;
        q.push(k);
        vis[k] = 1;
        while((int) q.size() > 0) {
            int cur = q.front(); q.pop();
            for(auto& i : adj[cur]) {
                if(vis[i] == 0){
                    vis[i] = vis[cur] ^ 2;
                    q.push(i);
                } else {
                    if(vis[cur] == vis[i]) {
                        cout << "IMPOSSIBLE";
                        exit(0);
                    }
                }
            }
        }
    }

    for(int i = 1; i <= n; ++i) cout << min(vis[i], 2) << " ";
}
