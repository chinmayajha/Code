#include "bits/stdc++.h"
using namespace std;

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        
        set<string> freq;
        for(int i = 0; i < n - 1; ++i) {
            // removing i and i + 1
            freq.insert(s.substr(0, i) + s.substr(i + 2, n - i - 2));
        }
        cout << freq.size() << '\n';
    }
}
