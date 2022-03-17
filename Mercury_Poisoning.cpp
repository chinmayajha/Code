#include "bits/stdc++.h"
using namespace std;
#define int long long

int n, m, qq;
vector<vector<int>> a;

void solve() {
    cin >> n >> m >> qq;
    a.assign(n, vector<int>(m, 0));
    bool check1 = 1;
    for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) {
        cin >> a[i][j];
        if(a[i][j] != a[0][0]) check1 = 0;
    }
    if(check1) for(int i = 0, c; i < qq; i++){
        cin >> c >> c >> c;
        if(c <= a[0][0]) cout << 0 << endl;
        else cout << (long long) n * m << endl;
    } else if(n == 1) {
        for(int i = 0, x, y, z; i < qq; ++i) {
            cin >> x >> y >> z; y--;
            int left = y, right = y;
            if(a[0][y] >= z) {
                cout << "0\n";
                continue;
            }
            while(left > 0 && a[0][left - 1] < z) left--;
            while(right < m - 1 && a[0][right + 1] < z) right++;
            cout << right - left + 1 << "\n";
        }
    } else {
        vector<int> ans(qq, 0);
        vector<pair<pair<int, int>, int>> queries(qq);
        int x, y;
        for(int i = 0; i < qq; ++i) {
            cin >> x >> y >> queries[i].first.first;
            queries[i].first.second = i;
            queries[i].second = 0;
        } x--; y--;
        sort(queries.begin(), queries.end());
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        pq.push({a[x][y], x, y});
        for(int i = 0; i < qq; ++i) {
            auto [margin, ind] = queries[i].first;
            while(!pq.empty() && pq.top()[0] < margin) {
                int xi = pq.top()[1], yi = pq.top()[2]; pq.pop();
                if(vis[xi][yi]) continue;
                vis[xi][yi] = 1;
                queries[i].second++;
                if(xi - 1 >= 0 && !vis[xi - 1][yi]) pq.push({a[xi - 1][yi], xi - 1, yi});
                if(yi - 1 >= 0 && !vis[xi][yi - 1]) pq.push({a[xi][yi - 1], xi, yi - 1});
                if(xi + 1 < n && !vis[xi + 1][yi]) pq.push({a[xi + 1][yi], xi + 1, yi});
                if(yi + 1 < m && !vis[xi][yi + 1]) pq.push({a[xi][yi + 1], xi, yi + 1});
            }
        }
        for(int i = 1; i < qq; ++i) queries[i].second += queries[i - 1].second;
        sort(queries.begin(), queries.end(), [&](pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2){return p1.first.second < p2.first.second;});
        for(int i = 0; i < qq; ++i) cout << queries[i].second << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
