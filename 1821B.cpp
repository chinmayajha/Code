#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n, l = 0, r = 0; cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        // finding first L and last R
        for(int i = 0; i < n; ++i) if(a[i] != b[i]) {l = i; break;}
        for(int i = n - 1; i >= 0; --i) if(a[i] != b[i]) {r = i; break;}

        // expanding left
        for(int i = l; i >= 1; i--) {
            if(b[i - 1] <= b[i]) l = i - 1;
            else break;
        }
        /// expanding right
        for(int i = r; i < n - 1; i++) {
            if(b[i + 1] >= b[i]) r = i + 1;
            else break;
        }

        cout << ++l << " " << ++r << "\n";
    }
}
