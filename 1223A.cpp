#include <bits/stdc++.h>
signed main() {
    int t; std::cin >> t;
    while(t--) {
        int n; std::cin >> n;
        std::cout << (n & 1) + (n == 2) * 2 << "\n";
    }
}
