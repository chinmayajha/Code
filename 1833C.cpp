#include "bits/stdc++.h"
using namespace std;
#define int long long
// #include "debug.hpp"

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        set<int> even, odd;
        for (int i = 0, j; i < n; ++i) {
            cin >> j;
            if(j % 2) odd.insert(j);
            else even.insert(j);
        }
        string ans = "YES\n";
        if(even.size() != 0 && odd.size() != 0) {
            if(*odd.begin() > *even.begin()) ans = "NO\n";
        }
        cout << ans;
    }
}
