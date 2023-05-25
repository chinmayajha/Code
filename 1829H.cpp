#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n), freq(6, 0);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            for(int j = 0; j < 6; ++j) {
                if((1 << j) & a[i]) freq[j] += 1;
            }

        }
        
    }
}
