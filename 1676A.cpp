#include "bits/stdc++.h"
using namespace std;

int func(string s) {
    return s[0] - '0' + s[1] - '0' + s[2]  - '0' == s[3] - '0' + s[4] - '0' + s[5] - '0';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        string s; cin >> s;
        cout << (func(s) ? "YES\n" : "NO\n");
    }
}
