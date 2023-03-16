#include "bits/stdc++.h"
using namespace std;

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tt = 1;
    cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        string s, t; cin >> s >> t;

        bool check = 1;
        // if a character cannot move anywhere, then 
        for(int i = 0; i < n; ++i) {
            if(i - k < 0 && i + k > n - 1) {
                if(s[i] != t[i]) {
                    check = 0;
                    break;
                }
            }
        }

        if(!check) {
            cout << "NO\n";
            continue;
        }
        // for all remaining characters, (assumed) each char can take any other char's position
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        cout << (t != s ? "NO\n" : "YES\n");;
    }
}
