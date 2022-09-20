#include "bits/stdc++.h"
signed main() {
    int64_t t; std::cin >> t;
    while (t--) {
        int64_t n, q, hl, wl, hr, wr; std::cin >> n >> q;
        std::vector<std::vector<int64_t>> a(1005, std::vector<int64_t>(1005, 0));
        for(int64_t i = 0, x, y; i < n; ++i) {
            std::cin >> x >> y;
            a[x][y] += (x * y);
        }
        for(int64_t i = 0; i < 1005; ++i) for(int64_t j = 0; j < 1005; ++j) {
            if(i) a[i][j] += a[i - 1][j];
            if(j) a[i][j] += a[i][j - 1];
            if(i) if(j) a[i][j] -= a[i - 1][j - 1];
        }
        while(q--) {
            std::cin >> hl >> wl >> hr >> wr;
            std::cout << a[hr - 1][wr - 1] - a[hr - 1][wl] - a[hl][wr - 1] + a[hl][wl] << "\n";
        }
    }
}
