#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    map<int, vector<int>> a;
    int n, q; cin >> n >> q;
    for(int i = 1, x; i <= n; ++i) {
        cin >> x;
        a[x].push_back(i);
    }
    for(int j = 1, x, k; j <= q; ++j) {
        cin >> x >> k;
        if((int) a[x].size() < k) cout << "-1";
        else cout << a[x][k - 1];
        cout << "\n";
    }

}
