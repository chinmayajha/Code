#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        vector<pair<int, int>> profit(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        for (int i = 0; i < n; ++i) profit[i] = {a[i] + b[i] - 1, i};

        random_shuffle(profit.begin(), profit.end());
        sort(profit.rbegin(), profit.rend());

        int turn = 0; // A goes first
        for(auto [p, i] : profit) {
            if(turn == 0) {
                a[i]--; b[i] = 0;
            } else {
                b[i]--; a[i] = 0;
            }
            turn = 1 - turn;
        }

        int ans = 0;
        for(auto& i : a) ans += i;
        for(auto& i : b) ans -= i;
        cout << ans << "\n";
    }
}
