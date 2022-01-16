#include "bits/stdc++.h"

signed main() {
    int n; std::cin >> n;
    std::string s, t; std::cin >> s >> t;
    int i = 0, ans = 0;
    while(i < n) {
        if(s[i] != t[i]) {
            // 0 1 or 1 0
            // 1 0    0 1
            // ^ checking this
            if(i + 1 < n && s[i + 1] != s[i] && s[i + 1] !=- t[i + 1]) i += 2;
            else ++i;
            ++ans;
        } else ++i;
    }
    std::cout << ans;
}
