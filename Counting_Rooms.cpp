#include "bits/stdc++.h"
using namespace std;

vector<string> a;
int n, m, cnt = 0, dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

void search(int i, int j) {
    if(i < 0 || j < 0 || i >= n || j >= m || a[i][j] != '.') return;
    a[i][j] = '#';
    for(int k = 0; k < 4; ++k) search(i + dx[k], j + dy[k]);
}

signed main() {
    cin >> n >> m;
    a.resize(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) if(a[i][j] == '.') {
        cnt += 1;
        search(i, j);
    }
    cout << cnt;
}
