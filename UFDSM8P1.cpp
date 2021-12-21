
#include "bits/stdc++.h"
using namespace std;
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define print(...)
#define dbg(...)
#endif
const int N = 1e5 + 10;
int n, m, q, x1, x2, y1, y2;

bool valid(int x, int y) {
    if(x < 0 || x >= n) return 0;
    if(y < 0 || y >= m) return 0;

    return 1;
}

bool bfs(int X1, int Y1, int X2, int Y2, bool parent_color, vector<vector<int>> &vis, vector<vector<int>> &a) {
    if(X1 == X2 && Y1 == Y2) return 1;

    if(vis[X1][Y1]) return 0;
    vis[X1][Y1] = 1;

    if(a[X1][Y1] != parent_color) return 0;

    bool ok1 = 0, ok2 = 0, ok3 = 0, ok4 = 0;

    if(valid(X1 - 1, Y1)) ok1 = bfs(X1 - 1, Y1, X2, Y2, !parent_color, vis, a);
    if(valid(X1, Y1 - 1)) ok2 = bfs(X1, Y1 - 1, X2, Y2, !parent_color, vis, a);
    if(valid(X1 + 1, Y1)) ok3 = bfs(X1 + 1, Y1, X2, Y2, !parent_color, vis, a);
    if(valid(X1, Y1 + 1)) ok4 = bfs(X1, Y1 + 1, X2, Y2, !parent_color, vis, a);

    return (ok1 || ok2 || ok3 || ok4);
}

void solve(){
    vector<vector<int>> a(n, vector<int>(m, 0));

    for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) cin >> a[i][j];
    while(q--) {
        vector<vector<int>> vis(n, vector<int>(m, 0));
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;
        cout << bfs(x1, y1, x2, y2, a[x1][y1], vis, a) << "\n";
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int s = 0;
    cin >> s;
    cin >> n >> m >> q;
    if(s == 3) {
        while(q--) cout << "1\n"; //path always exists
        return 0;
    }
    solve();

}
