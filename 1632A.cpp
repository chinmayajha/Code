#include "bits/stdc++.h"

signed main() {
    int t = 1; std::cin >> t;
    while (t--) {
        int n; std::cin >> n;
        std::string s; std::cin >> s;
        std::vector<int> a(2, 0);
        for(auto& i : s) a[i - '0']++;
        if(a[0] > 1 || a[1] > 1) std::cout << "NO\n";
        else std::cout << "YES\n";
    }
}
