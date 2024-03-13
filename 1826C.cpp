#include "bits/stdc++.h"
using namespace std;
#define int long long

int firstDivisorOfN(int n) {
    for(int i = 2; i * i <= n; ++i) {
        if(n % i == 0) return i;
    }
    return n;
}

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        int k = firstDivisorOfN(n); 

        cout << (n == 1 || k > m ? "YES\n" : "NO\n");
    }
}