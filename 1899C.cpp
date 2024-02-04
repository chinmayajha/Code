#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        
        int j = 0, par = -1;
        int cursum = 0, mx = a[0];
        while(j < n) {
            if(cursum < 0 || abs(a[j]) % 2 == par) {
                par = -1;
                cursum = 0;
            } else {
                par = abs(a[j]) % 2;
                cursum += a[j];
                mx = max(cursum, mx);
                j++;
            }
        }
        cout << mx << "\n";
    }
}
