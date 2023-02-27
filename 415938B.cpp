#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;
        vector<int> a(n + 1, 0), diff(n + 2, 0); 
        
        int p, l, r;
        while(q--) {
            cin >> p >> l >> r;
            if(p == 0) {
                diff[l] += 1;
                diff[r + 1] -= 1;
            } else {
                diff[l] -= 1;
                diff[r + 1] += 1;
            }
        }
        
        for (int i = 1; i <= n; i++) {
            diff[i] += diff[i - 1];
            a[i] += diff[i];
        }
        for (int i = 1; i <= n; i++) cout << a[i] << " ";
        cout << "\n";
    }
}

