#include "bits/stdc++.h"
using namespace std;
#define int long long

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<int> dis, vis, parent, path;
int n, e;

vector<vector<pair<int, int>>> adj;
signed main() {
    cin >> n >> e;
    adj.resize(n + 1);
    dis.assign(n + 1, 100000007);
    vis.assign(n + 1, 0);
    parent.assign(n + 1, -1);
    for(int i = 0, x, y; i < e; ++i) {
        cin >> x >> y;
        adj[x].push_back({y, 1});
        adj[y].push_back({x, 1});
    }
    //
    dis[1] = 0;
    pq.push({dis[1], 1ll});

    while((int) pq.size() > 0) {
        auto cur = pq.top().second; pq.pop();
        if(vis[cur]) continue;
        vis[cur] = 1;
        for(auto& [node, weight] : adj[cur]) {
            if(dis[node] > dis[cur] + weight) {
                dis[node] = dis[cur] + weight;
                parent[node] = cur; 
            }
            pq.push({dis[node], node});
        }
    }
    
    if(dis[n] == 100000007) cout << "IMPOSSIBLE\n";
    else {
        while(n != -1) {
            path.push_back(n);
            n = parent[n];
        }
        reverse(path.begin(), path.end());
        cout << (int) path.size() << "\n";
        for(auto& i : path) {cout << i << " ";} cout << "\n";
    } 
}
