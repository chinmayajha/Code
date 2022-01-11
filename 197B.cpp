
#include "bits/stdc++.h"
using namespace std;
#define int long long

int gcdd(int a, int b) {
    // Source : https://en.algorithmica.org/hpc/analyzing-performance/gcd/
    if (a == 0) return b;
    if (b == 0) return a;
    int az = __builtin_ctz(a);
    int bz = __builtin_ctz(b);
    int shift = std::min(az, bz);
    b >>= bz;
    while (a != 0) {
        a >>= az;
        int diff = b - a;
        az = __builtin_ctz(diff);
        b = std::min(a, b), a = std::abs(diff);
    }
    return b << shift;
}

signed main() {
    int n, m; cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    for(int i = 0; i <= n; ++i) cin >> a[i];
    for(int i = 0; i <= m; ++i) cin >> b[i];
    //
    if(n > m) {
        int x = 1;
        if(a[0] < 0) x *= -1;
        if(b[0] < 0) x *= -1;

        if(x == -1) cout << '-';
        cout << "Infinity";
    } else if(n < m) cout << "0/1";
    else {
        int x = gcdd(abs(a[0]), abs(b[0]));
        int sign = 1;
        if(a[0] < 0) sign *= -1;
        if(b[0] < 0) sign *= -1;
        if(sign < 0) cout << '-';
        cout << abs(a[0]) / x << "/" << abs(b[0]) / x;
    }
}
