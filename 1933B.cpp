#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n, sum = 0, check = 0; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
            if(a[i] % 3 == 1) check = 1;
        }
        if(sum % 3 == 0) cout << 0;
        else if(sum % 3 == 2) cout << 1;
        else if(check) cout << 1;
        else cout << 2;
        cout << "\n"; 
        // if % 3 == 0 - 0
        // if % 3 == 1
            // find any 3k + 1, remove - 1 or - 2
        // if % 3 == 2 - 1
    }
}

