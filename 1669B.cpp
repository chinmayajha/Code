#include "bits/stdc++.h"
using namespace std;

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n, ans = -1; cin >> n;
        map<int, int> a;
        for (int i = 0, temp; i < n; ++i) {
            cin >> temp;
            a[temp] += 1;
        }
        for(auto& i : a) if(i.second >= 3) ans = i.first;
        cout << ans << "\n";        
    }
}
