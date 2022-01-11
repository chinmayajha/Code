#include "bits/stdc++.h"
using namespace std;
#define int long long

struct x {
    int p,q,r;
};
bool cmp(x a, x b) {
    return ((a.q + a.r) > (b.q + b.r));
}
signed main() {
    int n, sum = 0; cin >> n;
    vector<x> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].p >> a[i].q >> a[i].r;
    }
    sort(a.begin(), a.end(), cmp);
    int ans = 0;
    for(auto& i : a) {
        ans = max(ans, sum + i.p + i.q + i.r);
        sum += i.p;
    }
    cout << ans;
}