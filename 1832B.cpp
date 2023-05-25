#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n + 1, 0);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        for(int i = 1; i <= n; ++i) a[i] += a[i - 1]; 

        // There wil be 2x deletions of minimum, and k - 2x deletions of maximum 
        // Trying for all i from 1 to k

        int sum = 0, tsum;
        for(int i = 0; i <= k; ++i) {
            // deleting 2i minimums and k - 2i maximums
            tsum = a[n - (k - i)] - a[2 * i];
            sum = max(sum, tsum);
        }

        cout << sum << "\n";
    }
}
