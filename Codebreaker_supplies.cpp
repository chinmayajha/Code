#include "bits/stdc++.h"
#define int long long

std::vector<std::vector<std::pair<int, int>>> adj;
int n, e, h, t;

int dijsktra(int x, int y) {
    std::vector<int> dis;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> s;
    dis.assign(n + 1, 1000000000);

    dis[x] = 0;
    s.push(std::make_pair(0, x));

    while((int) s.size() > 0) {
        int cur = s.top().second; s.pop();
        for(auto& i : adj[cur]) {
            int node = i.first, weight = i.second;
            if(dis[cur] + weight < dis[node]) {
                dis[node] = dis[cur] + weight;
                s.push(std::make_pair(dis[node], node));
            }
        }
    }

    return dis[y];
}

signed main() {
    std::cin >> n >> e >> h >> t;
    adj.resize(n + 1);
    for(int i = 0, x, y, z; i < e; ++i) {
        std::cin >> x >> y >> z;
        adj[x].push_back(std::make_pair(y, z));
    }
    int cnt1 = dijsktra(h, t), cnt2 = dijsktra(t, h);
    if(cnt1 == 1000000000 || cnt2 == 1000000000) std::cout << "-1";
    else std::cout << cnt1 + cnt2;
}
