#include "bits/stdc++.h"
using namespace std;
#define int long long

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n, ones = 0, zeros = 0; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            ones += (a[i] == 1);
            zeros += (a[i] == 0);
        }
        cout << binpow(2, zeros) * ones << "\n";
    }
}

