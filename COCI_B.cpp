#include <bits/stdc++.h>
using namespace std;

int n, e, x, y, z, k, q;
vector<vector<pair<int, int>>> a;

bool check(int xx, int yy) { 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dis(n + 1, 100000007), vis(n + 1, 0), parent(n + 1, -1);
    dis[xx] = 0;
    pq.push({dis[xx], 1});
    parent[xx] = -1;
    while((int) pq.size() > 0) {
        int cur = (int) pq.top().second; pq.pop();
        if(vis[cur]) continue;
        vis[cur] = 1;
        for(auto& [node, weight] : a[cur]) {
            if(dis[node] > dis[cur] + 1) {
                dis[node] = dis[cur] + 1;
            }
            pq.push({dis[node], node});
        }
    }
    return (dis[yy] <= k);
}

int solve() {
    cin >> x >> y;
    if(!check(x, y)) return -1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dis(n + 1, 100000007), vis(n + 1, 0), parent(n + 1, -1);
    
    dis[x] = 0;
    pq.push({dis[x], x});
    while((int) pq.size() > 0) {
        int cur = (pq.top()).second; pq.pop();
        if(vis[cur]) continue;
        vis[cur] = 1;
        for(auto& [node, weight]: a[cur]) {
            if(dis[cur] + weight <  dis[node]) {
                dis[node] = dis[cur] + weight;
                parent[node] = cur;
            }
            pq.push({dis[node], node});
        }
    }
    
    return dis[y];
}

int main() {
    cin >> n >> e;
    a.resize(n + 1);
    for(int i = 0; i < e; ++i) {
        cin >> x >> y >> z; 
        a[x].push_back({y, z});
    }

    cin >> k >> q;
    while(q--) cout << solve() << "\n";
}
//