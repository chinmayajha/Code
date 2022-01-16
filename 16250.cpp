#include "bits/stdc++.h"
using namespace std;

signed main() {
    int t = 1; std::cin >> t;
    while (t--) {
        int n, l; std::cin >> n >> l;
        std::vector<int> freq(l + 1, 0);
        for(int i = 0, x; i < n; ++i) {
            std::cin >> x;
            for(int k = 0; k < l; ++k) freq[k] += ((x >> k) & 1);
        }
        
        int ans = 0;
        for(int i = 0; i < l; ++i) {
            if(freq[i] * 2 > n) ans = (ans | (1ll << i));
        }
        std::cout << ans << "\n";
    }
}
