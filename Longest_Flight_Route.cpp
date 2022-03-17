#include "bits/stdc++.h"
using namespace std;
#define int long long

int n, e;
vector<vector<int>> a;
vector<int> vis, parent, dis, path;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> e;
    a.resize(n + 1); vis.assign(n + 1, 0); parent.assign(n + 1, -1); dis.assign(n + 1, 999999999999ll);
    for(int i = 0, x, y; i < e; ++i) {
        cin >> x >> y;
        a[x].push_back(y);
    }
    //
    pq.push({0, 1});
    while((int) pq.size() > 0) {
        int cur = pq.top().second; pq.pop();
        if(vis[cur] == 50) continue; 
        vis[cur]++;
        for(auto& node : a[cur]) {
            if(dis[cur] - 1 < dis[node]) {
                dis[node] = dis[cur]  - 1; 
                parent[node] = cur;
            }
            pq.push({dis[node], node});
        }
    }
    int N = n;
    while(N != -1) {
        path.push_back(N);
        N = parent[N];
    }
    if(dis[n] == 999999999999ll || (int) path.size() == 1) {
        cout << "IMPOSSIBLE";
        exit(0);
    }
    reverse(path.begin(), path.end());
    cout << (int) path.size() << "\n";
    for(auto& i : path) cout << i <<  " ";
}
