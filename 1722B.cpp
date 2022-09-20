#include "bits/stdc++.h"
signed main() {
    int t; std::cin >> t;
    while (t--) {
        int n; std::cin >> n;
        std::string a, b; std::cin >> a >> b;
        for(auto& i : b) if(i == 'B') i = 'G';
        for(auto& i : a) if(i == 'B') i = 'G';
        std::cout << ((a == b) ? "YES\n" : "NO\n");
    }
}
