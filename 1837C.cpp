#include "bits/stdc++.h"
using namespace std;

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.size();

        char cur = '1';
        for(int i = n - 1; i >= 0; --i) {
            if(s[i] != '?') {
                cur = s[i];
                continue;
            }
            s[i] = cur;
        }
        cout << s << "\n";
    }
}
