#include "bits/stdc++.h"
using namespace std;

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first; // temperature
            a[i].second = i; // day number
        }
        vector<int> b(n), c(n);
        for(int i = 0; i < n; ++i) cin >> b[i];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        for(int i = 0; i < n; ++i) c[a[i].second] = b[i];
        for(auto& i : c) cout << i << " "; 
        cout << "\n";
    }
}
