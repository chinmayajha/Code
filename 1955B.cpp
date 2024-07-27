// #include "debug.h"
#include "bits/stdc++.h"
using namespace std;
#define int long long

string solve() {
    int n, c, d; cin >> n >> c >> d;
    multiset<int> m;
    for(int i = 0, x; i < n * n; ++i) cin >> x, m.insert(x);

    int a11 = *(m.begin());
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            auto it = m.find(a11 + j * c);
            if(it == m.end()) return "NO";
            else m.erase(it);
        }
        a11 += d;
    }

    return "YES";
}

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) cout << solve() << "\n";
}

