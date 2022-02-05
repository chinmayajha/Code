#include "bits/stdc++.h"
using namespace std;
#define int long long

int n, q, x, y; 
vector<int> a, seg;

int build(int ind, int l, int r) {
    if(l == r) return seg[ind] = a[l];
    else return seg[ind] = build(2 * ind + 1, l, (l + r) / 2) + build(2 * ind + 2, (l + r) / 2 + 1, r);
}

int query(int ind, int low, int high, int l, int r) {
    if(low >= l && high <= r) return seg[ind];
    if(low > r || high < l) return 0;

    return  query(2 * ind + 1, low, (low + high) / 2, l, r) + query(2 * ind + 2, (low + high) / 2 + 1, high, l, r);
}

signed main() {
    cin >> n >> q;
    a.resize(n + 1);
    seg.resize(4 * n + 4);
    for(int i = 0; i < n; ++i) cin >> a[i];

    build(0, 0, n - 1);
    while(q--) {
        cin >> x >> y; x--; y--;
        cout << query(0, 0, n - 1, x, y) << "\n";
    }
}