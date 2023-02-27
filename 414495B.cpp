#include "bits/stdc++.h"
using namespace std;
#define int long long
// #include "debug.hpp"

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < m; ++i) cin >> b[i];

        if(n != m) {
            cout << "NO\n";
            continue;
        }
        bool check = true;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        for(int i = 0; i < n; ++i) {
            if(a[i] != b[i]) {
                check = false;
                break;
            }
        }

        cout << (check ? "YES\n" : "NO\n");
    }
}
