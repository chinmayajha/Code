#include "bits/stdc++.h"
using namespace std;

signed main() {
    int t = 1;
    cin >> t;
    while(t--) {
        int n, m, x1, y1, x2, y2;
        cin >> n >> m >> x1 >> y1 >> x2 >> y2;

        int horizontal = abs(x2 - x1);
        if(x2 < x1) horizontal += 2 * (n - x1);

        int vertical = abs(y2 - y1);
        if(y2 < y1) vertical += 2 * (m - y1);
        
        cout << min(horizontal, vertical) << "\n";
    }
}
