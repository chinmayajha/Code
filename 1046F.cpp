
#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    int n, f, x, cnt = 0; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cin >> x >> f;
    for(auto& i : a) {
        int bal = i / (f + x);
        i = (i % (f + x));
        if(i > x) bal += 1; 
        cnt += bal;
    }
    cout << cnt * f;
}
