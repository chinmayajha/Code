#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        vector<int> a(n + 1, -1);
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a.rbegin(), a.rend());
        a.back() = INT_MAX;
        
        for(int i = 1; i < n; ++i) a[i] += a[i - 1]; // prefix summing
        for(int i = 0, temp = 0; i < q; ++i) {
            cin >> temp;
            int x = (lower_bound(a.begin(), a.end(), temp) - a.begin()) + 1;
            cout << (x > n ? -1 : x) << "\n";
        }
    }
}
