
#include "bits/stdc++.h"
using namespace std;
#define int long long

const int maxn = 100010;
vector<vector<pair<int, int>>> a(maxn);
vector<int> dist(maxn);
int n, q;

int dfs2(int node, int cur_dist = 0, int parent = -1) {
    dist[node] = cur_dist;
    int ans = 0;
    for(auto& i : a[node]) {
        if(i.first == parent) continue;
        ans += dfs2(i.first, cur_dist + i.second, node);
    }
    return ans;
}

signed main() {
    cin >> n;
    for(int i = 0; i < n - 1; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        a[x].push_back(make_pair(y, w));
        a[y].push_back(make_pair(x, -1ll * w));
    }
    
    dfs2(1); // calculate sum of weights from root
    
    cin >> q;
    for(int i = 0; i < q; ++i) {
        int x, y; cin >> x >> y;
        cout << dist[y] - dist[x] << "\n";
    }
}
