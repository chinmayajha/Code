#include "bits/stdc++.h"
#define int long long

std::vector<std::vector<std::pair<int, int>>> adj;
int n, e, h, t;
std::vector<int> dis, p, vis;

signed main() {
    std::cin >> n >> e;
    adj.resize(n + 1);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> s;
    dis.assign(n + 1, 1000000000000);
    p.assign(n + 1, -1);
    vis.assign(n + 1, 0);
    //
    for(int i = 0, x, y, z; i < e; ++i) {
        std::cin >> x >> y >> z;
        adj[x].push_back(std::make_pair(y, z));
        adj[y].push_back(std::make_pair(x, z));
    }
    dis[1] = 0;
    s.push(std::make_pair(0, 1));
    //
    while((int) s.size() > 0) {
        int cur = s.top().second; s.pop();
        if(vis[cur]) continue;
        vis[cur] = 1;
        for(auto& i : adj[cur]) {
            int node = i.first, weight = i.second;
            if(dis[cur] + weight < dis[node]) {
                dis[node] = dis[cur] + weight;
                p[node] = cur;
            }
            s.push(std::make_pair(dis[node], node));
        }
    }
    //
    if(dis[n] == 1000000000000) std::cout << "-1";
    else {
        std::vector<int> path;
        while(p[n] != -1) {
            path.push_back(n);
            n = p[n];
        }
        path.push_back(1);
        std::reverse(path.begin(), path.end());
        for(auto& i : path) std::cout << i << " ";
    }
    return 0;
}