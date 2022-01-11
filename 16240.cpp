#include "bits/stdc++.h"
using namespace std;
#define int long long
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
// #include "debug.hpp"

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        int sum = -1;
        int x = *max_element(all(a));
        for(auto& i : a) sum = max(sum, x - i);
        cout << sum << "\n";
    }
}
