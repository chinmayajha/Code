#include "bits/stdc++.h"
using namespace std;
#define int long long
 
signed main() {
    string ans[3] = {"RIGHT", "TOUCH", "LEFT"};
    int t = 1; cin >> t; while (t--) {
        int x1, y1, x2, y2, x, y;
        cin >> x1 >> y1 >> x2 >> y2 >> x >> y;
        int check = (x2 - x1) * (y - y1) - (y2 - y1) * (x - x1);
        cout << ans[1 + (check > 0) - (check < 0)] <<  "\n";
    }
}