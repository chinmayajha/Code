#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        string s; cin >> s;
        int ans = 1;
        for(int i = 0; i < s.size(); ++i) {
            if(i == 0 && s[i] == '?') ans *= 9;
            else if(s[i] == '?') ans *= 10;
        }
        cout << ((s == "0" || s[0] == '0') ? 0 : ans) << "\n";
    }
}
