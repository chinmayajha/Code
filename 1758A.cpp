#include "bits/stdc++.h"
using namespace std;

signed main() {
    int t = 1; cin >> t;
    while (t--) {
        string s; cin >> s;
        cout << s; 
        reverse(s.begin(), s.end());
        cout << s << "\n";
    }
}
