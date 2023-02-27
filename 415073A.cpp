#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
     int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    int cnt2 = 0;
    int cnt5 = 0;

    for (int i = 0; i < n; i++) {
        while (a[i] % 2 == 0) {
            cnt2++;
            a[i] /= 2;
        }
        while (a[i] % 5 == 0) {
            cnt5++;
            a[i] /= 5;
        }
    }

    int ans = min(cnt2, cnt5);
    cout << ans << endl;
}
