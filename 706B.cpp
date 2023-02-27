#include "bits/stdc++.h"
using namespace std;

signed main() {
    int n, q, r; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    cin >> q;
    while(q--) {
        cin >> r;
        cout << (upper_bound(a.begin(), a.end(), r) - a.begin()) << "\n";
    }
}
