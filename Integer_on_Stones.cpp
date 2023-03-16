#include "bits/stdc++.h"
using namespace std;
#define int long long

int power(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int a, n; cin >> a >> n;
        cout << (a < 0 ? 1 : power(a, n / 2, 1e9 + 7)) << "\n";
    }
}
