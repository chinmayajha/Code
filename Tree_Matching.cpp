#include "bits/stdc++.h"
using namespace std;

int n, temp, cnt, check;
vector<vector<int>> a;
vector<int> taken;

void dfs(int node, int parent) {
    for(auto& i : a[node]) if(i != parent) dfs(i, node);
    if(parent != -1 && !taken[parent] &&  !taken[node]) {
        cnt++;
        taken[node] = 1; taken[parent] = 1;
    }
}

signed main() {
    cin >> n; a.resize(n + 1); taken.assign(n + 1, 0);
    for(int i = 0, x, y; i < n - 1; ++i) {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1, -1);
    cout << cnt;
}
