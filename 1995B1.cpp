// #include "debug.h"
#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // random seed for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        shuffle(a.begin(), a.end(), rng);
        sort(a.begin(), a.end());

        int i = 0, j = 0, cur = 0, mx = 0;
        while(i < n && j < n) {
            if(a[j] - a[i] <= 1 && cur + a[j] <= k) {
                cur += a[j];
                mx = max(mx, cur);
                j++;
            } else {
                cur -= a[i];
                i++;
            }
        }

        cout << mx << "\n";
    }
}