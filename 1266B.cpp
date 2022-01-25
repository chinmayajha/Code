#include "bits/stdc++.h"
using namespace std;
#define int long long
// #include "debug.hpp"

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        if(n % 14 <= 6 && n % 14 >= 1 && n / 14 != 0) cout << "YES\n";
        else cout << "NO\n";
    }
}
