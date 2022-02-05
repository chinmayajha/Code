#include "bits/stdc++.h"
signed main() {
    int t = 1; std::cin >> t;
    while (t--) {
        int n; std::cin >> n;
        std::vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) std::cin >> a[i];
        for (int i = 0; i < n; ++i) std::cin >> b[i];
        
        for (int i = 0; i < n; ++i) {
            if(a[i] > b[i]) std::swap(a[i], b[i]);
        }
        std::cout << (*std::max_element(a.begin(), a.end())) * (*std::max_element(b.begin(), b.end())) << "\n";
    }
}
