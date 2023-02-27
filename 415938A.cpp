#include "bits/stdc++.h"
using namespace std;
#define int long long

// efficient gcd 
int gcd(int a, int b) {
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
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, ans = 0; cin >> n;
    vector<int> a(n), pref(n), suff(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    pref[0] = a[0];
    suff[n - 1] = a[n - 1];
    for(int i = 1; i < n; ++i) {
        pref[i] = gcd(a[i], pref[i - 1]);
    }
    for(int i = n - 2; i >= 0 ; --i) {
        suff[i] = gcd(suff[i + 1], a[i]);
    }
    
    for(int i = 1; i < n - 1; ++i) {
        ans = max(gcd(suff[i + 1], pref[i - 1]), ans);
    }

    ans = max({ans, pref[n - 2], suff[1]});
    if(n == 1) cout << a[0];
    else if(n == 2) cout << max(a[0], a[1]);
    else cout << ans;
}
