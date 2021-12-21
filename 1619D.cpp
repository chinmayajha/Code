
#include "bits/stdc++.h"
using namespace std;
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define int long long

#ifdef chinmayajha
#include "debug.hpp"
#else
#define print(...)
#define dbg(...)
#endif

int n, m;
void solve() {
    cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) cin >> a[i][j];
    }

}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int testt = 1;
    // cin >> testt;
    for (int i = 1; i <= testt; ++i) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}
