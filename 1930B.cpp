#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n, cur = 1; cin >> n; 
        vector<int> a(n);
        for(int i = 0; i < n; i += 2) a[i] = cur++;
        for(int i = 1; i < n; i += 2) a[i] = cur++;
        for(auto& i : a) cout << i << " ";
        cout << "\n";
    }
}