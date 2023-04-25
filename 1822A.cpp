#include "bits/stdc++.h"
using namespace std;
#define int long long
// #include "debug.hpp"

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n, time; cin >> n >> time;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        int ind = -1, curmax = -1;
        for(int i = 0; i < n; ++i) {
            if(a[i] + i <= time) {
                if(b[i] > curmax) {
                    curmax = b[i];
                    ind = i + 1;
                }
            }
        }
        cout << ind << "\n";
    }
}
