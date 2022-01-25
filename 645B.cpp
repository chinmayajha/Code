#include "bits/stdc++.h"
signed main() {
    int64_t n, k; std::cin >> n >> k;
    k = std::max(n - 2 * k, 0ll);
    k = n * (n - 1) / 2 - k * (k - 1) / 2;
    std::cout << k;
}
