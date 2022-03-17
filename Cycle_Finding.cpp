#include "bits/stdc++.h"
using namespace std;

vector<vector<pair<int, int>>> a;
vector<int> vis, rec, ans;
vector<pair<int, int>> path;
int n, e;

void print(int k) {
    ans.push_back(k);
    for(int j = (int) path.size() - 1; j >= 0; --j) {
        ans.push_back(path[j].first);
        if(path[j].first == k) break;
    }
    reverse(ans.begin(), ans.end());
    cout << "YES\n";
    for(auto& i : ans) {cout << i << " ";} cout << "\n";
    exit(0);
}

bool check(int k, int tsum) {
    for(int j = (int) path.size() - 1; j >= 0; --j) {
        tsum += path[j].second;
        if(path[j].first == k) break;
    }
    return (tsum >= 0);
}

void dfs(int node, int weight, int par) {
    vis[node] = 1; rec[node] = 1;
    path.push_back({node, weight});

    for(auto& i : a[node]) {
        if(rec[i.first] && i.first != par) {
            // cycle found
            if(check(i.first, i.second)) continue;
            // answer found!
            print(i.first);
        } else if(!vis[i.first]) dfs(i.first, i.second, node);
    }
    rec[node] = 0;
    path.pop_back();
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> e;
    a.resize(n + 1); vis.assign(n + 1, 0); rec.assign(n + 1, 0);
    for(int i = 0, x, y, z; i < e; ++i) {
        cin >> x >> y >> z;
        a[x].push_back({y, z});
    }
    for(int i = 1; i <= n; ++i) {
        path.clear();
        if(!vis[i]) dfs(i, 0, -1);
    }

    cout << "NO";
}
