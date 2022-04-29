#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    int n, ans = LONG_LONG_MAX; cin >> n;
    auto f = [](int a, int b) {return (a * a + b * b) * (a + b);};

    for(int k = 0; k <= 1000002; ++k) {
        int i = -1, j = 1000002, mid;
        while(i < j - 1) {
            mid = (i + j) / 2;
            if(f(k, mid) >= n) j = mid;
            else i = mid;
        }
        ans = min(ans, f(k, j));
    }
    cout << ans;
}
