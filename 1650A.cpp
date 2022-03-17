#include "bits/stdc++.h"
using namespace std;

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        string s; char c; cin >> s; cin >> c;
        bool check = 0; int n = (int) s.size();
        for(int i = 0; i < n; ++i) {
            if(s[i] - '0' != c - '0') continue;
            if((i % 2 == 0) && ((n - i - 1) % 2 == 0)) {
                check = 1;
                break;
            }
        }
        cout << (check ? "YES\n" : "NO\n");
    }
}
