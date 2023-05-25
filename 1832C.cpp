#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), b;
        for (int i = 0; i < n; ++i) cin >> a[i];

        b.push_back(a[0]);
        for(int i = 1; i < n; ++i) if(a[i] != a[i - 1]) b.push_back(a[i]);
        int sz = n = b.size();
        
        for(int i = 1; i < n - 1; ++i) {
            sz -= (b[i] > b[i - 1] && b[i] < b[i + 1]);
            sz -= (b[i] < b[i - 1] && b[i] > b[i + 1]);
        }

        cout << sz << "\n";
    }
}
