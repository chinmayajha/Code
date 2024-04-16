#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int tents = 0, a, b, c; cin >> a >> b >> c;

        tents += a;
        tents += (b / 3);
        b = b % 3;
        if(b == 0) {
            tents += (c + 2) / 3;
        } else if(b == 1) {
            if(c >= 2) {
                c -= 2;
                tents++;
                tents += (c + 2) / 3;
            } else tents = -1;
        } else { // b = 2
            if(c >= 1) {
                c--;
                tents++;
                tents += (c + 2) / 3;
            } else tents = -1;
        }

        cout << tents << "\n";
    }
}

