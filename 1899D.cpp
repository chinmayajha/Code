#include "bits/stdc++.h"
using namespace std;
#define int long long

int nc2(int n) {
    return (n * (n - 1)) / 2;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n; cin >> n;
        map<int, int> a;
        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            a[x]++;
        }

        int ans = 0;
        if(a[1] > 0 && a[2] > 0) ans += (a[1] * a[2]);
        for(auto& i : a) ans += nc2(i.second);
        
        cout << ans << "\n";
    }
}
