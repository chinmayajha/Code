#include "bits/stdc++.h"
signed main() {
    int n, k; std::cin >> n >> k; --k;
    std::vector<int> a(n), A(n, 0), B(n, 0);
    for(int i = 0; i < n; ++i) std::cin >> a[i];
    // A is forward, B is backward
    
    if(k + 1 < n) A[k + 1] = a[k + 1];
    for(int i = k + 2; i < n; ++i) {
        A[i] = std::max(A[i - 1], A[i - 2]) + a[i];
    }

    B[0] = a[0];
    if(n > 1) B[1] = a[0] + a[1];
    for(int i = 2; i < n; ++i) {
        B[i] = std::max(B[i - 1], B[i - 2]) + a[i];
    }

    int ans = INT_MIN;
    for(int i = k; i < n; ++i) {
        ans = std::max(ans, A[i] + B[i] - a[i]);
    }
    std::cout << ans;
}
