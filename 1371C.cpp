#include "bits/stdc++.h"
using namespace std;
#define int long long
// #include "debug.hpp"

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int a, b, n, m; cin >> a >> b >> n >> m;
        if(m + n > a + b) cout << "No\n";
        else {
            if(m <= min(a, b)) cout << "Yes\n";
            else cout << "No\n";
        }
    }
}
