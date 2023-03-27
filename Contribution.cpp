#include "bits/stdc++.h"
using namespace std;
#define int long long
// #include "debug.hpp"

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int tt = 1;
    cin >> tt;
    while (tt--) {
        int ans = 0;
        string s, t; cin >> s >> t;
        int n = s.size();
        for(int i = 0; i < n; ++i) {
            if(s[i] == '1') ans += 1;
            if(s[i] == '3') ans += 4;
            if(s[i] == '5') ans += 6;
            if(s[i] == '7') ans += 9;
        }
        for(int i = 0; i < n; ++i) {
            if(t[i] == '1') ans -= 1;
            if(t[i] == '3') ans -= 4;
            if(t[i] == '5') ans -= 6;
            if(t[i] == '7') ans -= 9;
        }
        cout << ans <<"\n";
    }   
}
