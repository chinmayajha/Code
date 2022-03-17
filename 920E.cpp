#include "bits/stdc++.h"
using namespace std;

int n, e, ans;
vector<set<int>> a;
multiset<int> vis, fin; // vis is actually not_vis

void dfs(int node) {
    vis.erase(node);
    ans += 1;
    auto node2 = vis.begin();
    while(node2 != vis.end()) {
        int cur = *node2;
        if(a[node].find(cur) == a[node].end()) dfs(cur);
        node2 = vis.upper_bound(cur);
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> e;
    a.resize(n + 1); 
    for(int i = 1; i <= n; ++i) vis.insert(i);

    for(int i = 0, x, y; i < e; ++i) {
        cin >> x >> y;
        a[x].insert(y);
        a[y].insert(x);
    }

    while((int) vis.size() > 0) {
        dfs(*vis.begin());
        fin.insert(ans);
        ans = 0;
    }
    
    cout << (int) fin.size() << "\n";
    for(auto& i : fin) cout << i << " ";
}
