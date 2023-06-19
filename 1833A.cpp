#include "bits/stdc++.h"
using namespace std;

signed main() {
    int tt = 1; cin >> tt;
    while (tt--) {
        int n; string s; set<string> t;
        cin >> n >> s;
        for(int i = 0; i < n - 1; ++i) t.insert(s.substr(i, 2));
        cout << t.size() << "\n";
    }
}
