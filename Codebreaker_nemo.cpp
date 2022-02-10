#include "bits/stdc++.h"
using namespace std;
#define int long long

int n, e, qq;
vector<vector<vector<int>>> adj;

signed main() {
    cin >> n >> e;
    adj.resize(n);
    for(int i = 0, w, x, y, z; i < e; ++i) {
        cin >> w >> x >> y >> z;
        adj[w].push_back({w, x, y, z});
    }
}