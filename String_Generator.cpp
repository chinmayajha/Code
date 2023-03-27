#include "bits/stdc++.h"
using namespace std;
#define int long long
// #include "debug.hpp"

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tt = 1;
    cin >> tt;
    for(int jj = 1; jj <= tt; ++jj) {
        int n; cin >> n;
        string s, t; cin >> s >> t;

        int left = 0, right = n - 1;
        string ans = "NO\n";
        while(left < right) {
            int mid = (left + right) / 2;
            if(works(mid, s, t)) {
                ans = "YES\n";
                break;
            } else if() right = mid + 1;
        }
    }
}
