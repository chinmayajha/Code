#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    int n; cin >> n;
    vector<int> a(n + 1, 0);
    a[0] = 1;

    for(int i = 0; i <= n; ++i) {
        for(int j = 1; j <= 6; ++j) {
            if(i - j < 0) continue;
            a[i] = (a[i] + a[i - j]) % 1000000007;
        }
    }

    cout << a[n] % 1000000007;
}
