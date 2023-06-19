#include "bits/stdc++.h"
using namespace std;

signed main() {
    int t = 1; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            a[i] = abs((i + 1) - a[i]);
        }
        for(int i = 1; i < n; ++i) a[i] = __gcd(a[i], a[i - 1]);
        cout << a[n - 1] << "\n";
    }
}
