#include "bits/stdc++.h"
using namespace std;
#define int long long

int dfs(int node, vector<vector<int>>& a, vector<int>& ans) {
    int temp = 0;
    for(auto& i : a[node]) {
        temp += dfs(i, a, ans);
    }
    return ans[node] = temp + 1;
}

signed main() {
    int n; cin >> n;
    vector<vector<int>> a(n + 1);
    vector<int> ans(n + 1, 0);
    for(int i = 2, x; i <= n; ++i) {
        cin >> x;
        a[x].push_back(i);
    }

    dfs(1, a, ans);
    for(int i = 1; i <= n; ++i) cout << ans[i] - 1 << " ";
}
