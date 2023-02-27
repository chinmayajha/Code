#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n, l; cin >> n >> l;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        int sum = 0, cursum = 0;
        for(int i = 0; i < n; ++i) {
            if(i + 1 > l) cursum -= a[i - l];
            cursum += a[i];

            sum = max(sum, cursum);
        }
        cout << sum << "\n";
    }
}
