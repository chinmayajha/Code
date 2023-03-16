#include "bits/stdc++.h"
using namespace std;
#define int long long 

int power(int x, int y, int p)
{
    int res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1) res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int modInverse(int n, int p) {
    return power(n, p - 2, p);
}

int mul(int x, int y, int p) {
    return x * 1ull * y % p;
}

int divide(int x, int y, int p) {
    return mul(x, modInverse(y, p), p);
}

int C(int n, int r, int p) {
    if (n < r) return 0;
    if (r == 0) return 1;
    if (n - r < r) return C(n, n - r, p);
    int res = 1;
    for (int i = r; i >= 1; i--) res = divide(mul(res, n - i + 1, p), i, p);
    return res;
}

signed main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int ans = C(n / 3, n / 6, 998244353);
    for (int i = 0; i <= n - 3; i += 3) {
        // sum += (a[i] + a[i + 1] + a[i + 2] - min({a[i], a[i + 1], a[i + 2]}));
        multiset<int> temp(a.begin() + i, a.begin() + i + 3);
        ans = (ans * temp.count(*temp.begin())) % 998244353;
    }
    // sum is not needed, but can be calculated easily -> choosing 2 max weights from each triple
    // ans = (n/3)C(n/6), i.e. choosing and rearranging n/6 nodes out of n/3 triples
    // then ans *= pi(freq of min of all triples) because that min is not counted, 
    // and if it repeats the answer increases
    cout << ans;
}
