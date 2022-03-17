#include "bits/stdc++.h"
using namespace std;

signed main() {
    vector<bool> a(361, 0); a[0] = 1;
    vector<int> b;
    int n, x, ind = 0, ans = 0; cin >> n;
    for(int k = 0; k < n; ++k) {
        cin >> x;
        ind += x; ind %= 360;
        a[ind] = 1;
    }
    
    b.push_back(0);
    for(int i = 1; i <= 360; ++i) if(a[i]) b.push_back(i);
    b.push_back(360);
    for(int i = 1; i < (int) b.size(); ++i) ans = max(ans, b[i] - b[i - 1]);

    cout << ans;
}
