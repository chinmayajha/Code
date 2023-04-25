#include "bits/stdc++.h"
using namespace std;

signed main() {
    int n, m; cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    for(int i = 0; i < n; ++i) for(int j = 0; j < m - 1; ++j) {
        if(a[i][j] == 'T' && a[i][j + 1] == 'T') a[i][j] = 'P', a[i][j + 1] = 'C';
    }

    for (int i = 0; i < n; ++i) cout << a[i] << "\n";
}
