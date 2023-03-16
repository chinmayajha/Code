#include "bits/stdc++.h"
using namespace std;
#define int long long
// #include "debug.hpp"

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n, j; cin >> n >> j;
        string s; cin >> s;
        vector<int> a(n, 1);
        for (int i = 0; i < n; ++i) a[i] += (s[i] == '#');

        int sum = 0;
        for(int i = j - 1; i < n; ++i) sum += a[i];
        if(sum <= n) cout << "JAY\n";
        else cout << "JEFF\n";
    }
}
