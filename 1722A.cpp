#include "bits/stdc++.h"
signed main() {
    int t; std::cin >> t;
    while (t--) {
        int n; std::cin >> n;
        std::string s; std::cin >> s;
        std::sort(s.begin(), s.end());
        std::cout << ((s == "Timru") ? "YES\n" : "NO\n");
    }
}
