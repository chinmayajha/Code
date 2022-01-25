#include "bits/stdc++.h"
signed main() {
    int n, m; std::cin >> n >> m;
    std::vector<std::string> a(n + 1), b(m + 1), c(n + 1);
    for(int i = 1; i <= n; ++i) std::cin >> a[i];
    for(int i = 1; i <= m; ++i) std::cin >> b[i];
    int i = 1, j = 1;
    while(i <= n && j <= m) {
        if(a[i] == b[j]) c[i] = "Yes\n", j += 1;
        else c[i] = "No\n";
        i += 1;
    }
    for(int k = 1; k <= n; ++k) std::cout << c[k];
}
