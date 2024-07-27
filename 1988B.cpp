// #include "debug.h"
#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;

        vector<int> a;
        a.push_back(s[0] - '0');
        for(int i = 1; i < n; ++i) {
            if(s[i] != s[i - 1] || s[i] == '1') a.push_back(s[i] - '0');
        }

        int c0 = 0, c1 = 0;
        for(auto &i : a) {
            c0 += (1 - i);
            c1 += i;
        }

        if(c1 > c0) cout << "Yes\n";
        else cout << "No\n";
    }
}