#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);

        int l = 1, r = n;
        for(int starti = 0; starti < k; ++starti) {
            if(starti % 2 == 0) {
                for(int i = starti; i < n; i += k) a[i] = l++;
            } else {
                for(int i = starti; i < n; i += k) a[i] = r--;
            }
        }

        for(auto& i : a) cout << i << " ";
        cout << "\n";
    }
}
