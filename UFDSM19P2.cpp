#include "bits/stdc++.h"
using namespace std;
#define int long long

int n, e;
vector<vector<pair<int, int>>> a;
vector<vector<int>> edges;
vector<int> dis, vis;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int dijsktra(int start, int end) {
    dis.assign(n + 1, 1000000007); vis.assign(n + 1, 0);
    while(!pq.empty()) pq.pop();
    
    dis[start] = 0;
    pq.push({dis[start], start});

    while((int) pq.size() > 0) {
        int cur = pq.top().second; pq.pop();
        if(vis[cur]) continue;
        vis[cur] = 1;
        for(auto& [node, weight] : a[cur]) {
            if(vis[node]) continue;
            if(node == start && cur == end) continue;
            if(node == end && cur == start) continue;
            if(dis[cur] + weight < dis[node]) {
                dis[node] = dis[cur] + weight;
            }
            pq.push({dis[node], node});
        }
    }
    return dis[end];
}

void preprocess() {
    if(n != e) return;
    // SUBTASK 2 DONE
    int ans = 0;
    for(auto& i : edges) ans += i[2];
    cout << ans;
    exit(0);
}

signed main() {
    // SUBTASKS DONE : 1 2 3 4 
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> e;
    a.resize(n + 1); for(int i = 0, x, y, z; i < e; ++i) {
        cin >> x >> y >> z;
        a[x].push_back({y, z});
        a[y].push_back({x, z});
        edges.push_back({x, y, z});
    }
    preprocess();
    int ans = INT_MAX;
    for(auto& i : edges) {
        ans = min(ans, i[2] + dijsktra(i[0], i[1]));
    }
    cout << ans;
}