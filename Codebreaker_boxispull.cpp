#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    int t = 1; cin >> t;
    while (t--) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        if(x1 - x2 == 0 || y1 - y2 == 0) cout << abs(x1 - x2) + abs(y1 - y2);
        else cout << abs(x1 - x2) + abs(y1 - y2) + 2;
        cout << "\n";
    }
}
