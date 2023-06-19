#include "bits/stdc++.h"
using namespace std;

signed main() {
    int t = 1; cin >> t;
    while (t--) {
        string s; set<char> check;
        cin >> s;
        int n = s.size() / 2 - 1;
        for(int i = 0; i <= n; ++i) check.insert(s[i]);
        cout << (check.size() > 1 ? "YES\n" : "NO\n");
    }
}
