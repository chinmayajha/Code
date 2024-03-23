#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    string s = "";
    for(int i = 0; i <= 55; ++i) {
        s.push_back('A');
        s.push_back('A');
        s.push_back('B');
        s.push_back('B');
    }
    cin >> T;
    while (T--) {
        int n, chance = 0; cin >> n;
        if(n % 2 == 1) cout << "NO\n";
        else cout << "YES\n" << s.substr(0, n) << "\n";
    }
}
