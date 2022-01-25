#include "bits/stdc++.h"
using namespace std;
#define int long long

int countodd(int L, int R) {
    int N = (R - L) / 2;
    if (R % 2 != 0 || L % 2 != 0) N += 1;
    return N;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int l, r, k; cin >> l >> r >> k;
        int odds = countodd(l, r);
        if((l == r && l != 1) || odds <= k) cout << "YES";
        else cout << "NO";

        cout << "\n";
    }
}
