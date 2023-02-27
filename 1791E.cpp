#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n, freq = 0, sum = 0; cin >> n;
        vector<int> a(n), b;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            freq += (a[i] <= 0);
            a[i] = abs(a[i]);
            sum += a[i];
        }
        if(freq % 2 == 0) cout << sum << "\n";
        else cout << sum - 2 * abs(*min_element(a.begin(), a.end())) << "\n";
    }
}
