#include "bits/stdc++.h"
using namespace std;

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        int mx = 1, curmax = 1;
        for(int i = 1; i < n; ++i) {
            if(s[i] == s[i - 1]) curmax++;
            else {
                mx = max(curmax, mx);
                curmax = 1;
            }
            mx = max(curmax, mx);
        }
        cout << ++mx << "\n";
    }
}
