#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int a, b, c, d, mn; cin >> a >> b >> c >> d;
        mn = min({a, b, c, d});
        cout << (a + b + c + d - 4 * mn) << "\n";
    }
}
