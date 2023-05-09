#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int ans = 0;
        string s, t = "codeforces"; cin >> s;
        for(int i = 0; i < 10; ++i) ans += (s[i] != t[i]);
        cout << ans << "\n";
    }
}
