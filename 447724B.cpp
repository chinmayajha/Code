#include "bits/stdc++.h"
using namespace std;
#define int long long
// #include "debug.hpp"

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    // cin >> t;
    while (t--) {
        int n; cin >> n;
        int ans = 1;
        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            ans *= x;
        }

        int i = 0;
        while(i * i <= ans) i++;
        cout << i - 1;
    }
}
