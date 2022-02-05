#include "bits/stdc++.h"
using namespace std;
#define int long long

vector<int> a, seg;
int n, q, x, y;

int build(int ind, int low, int high) {
    if(high < low) return 0;
    if(high == low) return seg[ind] = a[low];
    int mid = (low + high) / 2;
    return seg[ind] = build(2 * ind + 1, low, mid) ^ build(2 * ind + 2, mid + 1, high);
}

int query(int ind, int low, int high, int l, int r) {
    if(high < low || r < l || low > r || high < l) return 0;
    if(l == low && r == high) return seg[ind];
    int mid = (low + high) / 2;
    return query(2 * ind + 1, low, mid, l, min(mid, r)) ^ query(2 * ind + 2, mid + 1, high, max(mid + 1, l), r);
}

signed main() {
    cin >> n >> q;
    a.resize(n + 1); seg.resize(4 * n + 4);
    for(int i = 0; i < n; ++i) cin >> a[i];

    build(0, 0, n - 1);
    while(q--) {
        cin >> x >> y;
        cout << query(0, 0, n - 1, x - 1, y - 1) << "\n";
    }
}