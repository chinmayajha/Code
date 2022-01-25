#include "bits/stdc++.h"

signed main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); int t = 1;
    std::cin >> t;
    while (t--) {
        int n; std::cin >> n; 
        std::vector<int> a(n), b;
        std::vector<std::vector<int>> freq(200010);
        for(int i = 0; i < n; ++i) {
            std::cin >> a[i];
            freq[a[i]].push_back(i);
        }
        int cur = -1;
        while(cur < n - 1) {
            int mex = 0, i = cur + 1;
            while(i < n) {
                auto index = std::lower_bound(freq[mex].begin(), freq[mex].end(), cur + 1);
                if(index == freq[mex].end()) break;
                i = std::max(*index, i), mex += 1;
            }
            b.push_back(mex);
            cur = i;
        }
        std::cout << (int) b.size() << "\n";
        for(auto& i : b) std::cout << i << " "; 
        std::cout << "\n";
    }
}
