#include "bits/stdc++.h"
using namespace std;

signed main() {
    int T = 1; cin >> T;
    while (T--) {
        int n; cin >> n;
        cout << (n % 3 ? "First" : "Second") << "\n";
    }
}
