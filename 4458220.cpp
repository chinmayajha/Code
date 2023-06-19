#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n, a, b; cin >> n >> a >> b;
        if(a >= b) cout << n * a;
        else if(b > a) cout << (n - 1) * a + b;
        cout << "\n";
    }
}
