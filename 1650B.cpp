#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    int t = 1; cin >> t;
    auto f = [](int x, int div) { return ((x / div) + (x % div)); };

    while (t--) {
        int l, r, a; cin >> l >> r >> a;
        int r2 = (r / a) * a - 1;
        if(r2 < l) r2 = r;
        
        cout << max(f(r2, a), f(r, a)) << "\n";
    }
}
