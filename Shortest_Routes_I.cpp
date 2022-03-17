#include "bits/stdc++.h"
using namespace std;
#define int long long

int n, e;
vector<vector<pair<int, int>>> a;
vector<int> dis, vis;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> e;
    a.resize(n + 1); vis.assign(n + 1, 0);
    dis.assign(n + 1, 999999999999999ll);
    for(int i = 0, x, y, z; i < e; ++i) {
        cin >> x >> y >> z;
        a[x].push_back({y, z});
    }
    
    dis[1] = 0;
    pq.push({0, 1});

    while((int) pq.size() > 0) {
        int cur = pq.top().second; pq.pop();
        if(vis[cur]) continue;
        vis[cur] = 1;
        for(auto& [node, weight] : a[cur]) {
            if(dis[cur] + weight < dis[node]) {
                dis[node] = dis[cur] + weight;
            }
            pq.push({dis[node], node});
        }
    }
    for(int i = 1; i <= n; ++i) cout << dis[i] << " ";
}
