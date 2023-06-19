#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int m, n; cin >> m >> n;
        if(m == 1) cout << "2\n";
        else cout << (1 << m) - 1 << "\n";
    }
}
