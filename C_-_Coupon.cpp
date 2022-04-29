#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(auto& i : a) {
        if(k == 0) break;
        int can = i / x;
        can = min(can, k);
        k -= can;
        i -= (can * x);
    }
    sort(a.rbegin(), a.rend());
    for(auto& i : a) {
        if(k == 0) break;
        k -= 1;
        i = 0;
    }
    cout << accumulate(a.begin(), a.end(), 0ll);
}
