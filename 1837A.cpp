#include "bits/stdc++.h"
using namespace std;

signed main() {
    int t = 1; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        if(n % k == 0) {
            cout << "2\n";
            cout << (n - 1) << " 1\n";
        } else cout << "1\n" << n << "\n";
    }
}
