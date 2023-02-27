#include "bits/stdc++.h"
signed main() {
    int t = 1; std::cin >> t;
    while (t--) {
        int n, cnt = 1; std::cin >> n;
        std::vector<int> a(n);
        for(int i = 1; i < n; i += 2) a[i] = cnt++;
        for(int i = 0; i < n; i += 2) a[i] = cnt++;
        for(auto& i : a) {std::cout << i << " ";} std::cout << "\n";
    }
}
