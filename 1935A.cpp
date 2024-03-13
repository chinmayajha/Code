#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n; cin >> n;
        string s, t; cin >> s;
        t = s;
        reverse(t.begin(), t.end());

        if(s < t) {
            if(n % 2 == 0) cout << s;
            else {
                cout << s;
                n--;
                if(n) cout << t;
            }
        } else if(s > t) {
            if(n % 2 == 1) cout << t;
            else {
                cout << t;
                n--;
                if(n) cout << s;
            }
        } else if(s == t) cout << s;

        cout << "\n";
    }
}

