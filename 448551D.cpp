#include "bits/stdc++.h"
using namespace std;
#define int long long
// #include "debug.hpp"

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        multiset<int> b;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            a[i] -= k;
        }
        for (int i = 0, x; i < n; ++i) {
            cin >> x; x -= k;
            b.insert(x);
        }
        sort(a.begin(), a.end());

        for(int i = 0; i < n; ++i) {
            // find just largest of a[i]
            int large = 
        }
        
    }
}
