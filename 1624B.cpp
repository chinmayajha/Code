#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    int t = 1; cin >> t;
    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int d1 = 2 * b - c;
        int d2 = 2 * b - a;
        int d3 = a + c;
        if (
            (d1 % a == 0 && d1 > 0) ||
            (d2 % c == 0 && d2 > 0) ||
            (d3 % 2 == 0 && (d3 / 2) % b == 0 && d3 > 0)
        ) cout << "YES\n";
        else cout << "NO\n";
    }
}
