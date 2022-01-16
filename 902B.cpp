#include "bits/stdc++.h"

signed main() {
    int n; std::cin >> n;
    std::vector<int> a(n + 1), c(n + 1);
    a[1] = -1;
    for(int i = 2; i <= n; ++i) std::cin >> a[i];
    for(int i = 1; i <= n; ++i) std::cin >> c[i];
    
    int cnt = 1;
    for(int i = 2; i <= n; ++i) cnt += (c[i] != c[a[i]]);
    std::cout << cnt;
}
