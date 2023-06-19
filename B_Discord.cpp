#include "bits/stdc++.h"
using namespace std;

signed main() {
    int n, m; cin >> m >> n;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) cin >> a[i][j];

    set<pair<int, int>> s;
    for(int i = 1; i <= m; ++i) for(int j = 1; j <= m; ++j) {
        if(i != j) s.insert({min(i, j), max(i, j)});
    }

    for (int i = 0; i < n; ++i) for(int j = 0; j < m - 1; ++j) {
        auto it = s.find({min(a[i][j], a[i][j + 1]), max(a[i][j], a[i][j + 1])});
        if(it != s.end()) s.erase(it);
    }

    cout << s.size();
}
