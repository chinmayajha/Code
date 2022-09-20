#include "bits/stdc++.h"
using namespace std;
#define int long long

void dfs(int node, int parent, vector<vector<int>>& a, vector<pair<int, int>>& bw, string& s) {
    if(s[node - 1] == 'W') bw[node].first += 1;
    else bw[node].second += 1;

    for(auto& i : a[node]) {
        if(i == parent) continue;
        dfs(i, node, a, bw, s);
    }
    if(parent != -1) {
        bw[parent].first += bw[node].first;
        bw[parent].second += bw[node].second;
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n, cnt = 0; cin >> n;
        vector<vector<int>> a(n + 1); string s;
        vector<pair<int, int>> bw(n + 1, {0, 0});
        for(int i = 1, temp; i <= n - 1; ++i) {
            cin >> temp;
            a[temp].push_back(i + 1);
            a[i + 1].push_back(temp);
        }
        cin >> s;

        dfs(1, -1, a, bw, s);
        for(int i = 1; i <= n; ++i) if(bw[i].first == bw[i].second) cnt++;
        cout << cnt << "\n";
    }
}
