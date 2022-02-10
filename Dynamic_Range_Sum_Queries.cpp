#include "bits/stdc++.h"
using namespace std;
#define int long long

int n, q, typ, x, y;
vector<int> a, seg;

int build(int ind, int low, int high) {
    if(high < low) return seg[ind] = 0;
    if(high == low) return seg[ind] = a[low];
    int mid = (low + high) / 2;
    return seg[ind] = (
        build(2 * ind + 1, low, mid) + 
        build(2 * ind + 2, mid + 1, high)
    );
}

int query(int ind, int low, int high, int l, int r) {
    if(l > r || high < low || low > r || high < l) return 0;
    if(high == r && low == l) return seg[ind];

    int mid = (high + low) / 2;
    return (query(2 * ind + 1, low, mid, l, min(r, mid)) +
            query(2 * ind + 2, mid + 1, high, max(l, mid + 1), r));
}

void update(int ind, int low, int high, int target, int value) {
    if(low == high) {
        seg[ind] = value;
        return;
    }
    int mid = (high + low) / 2;
    if(target <= mid) update(2 * ind + 1, low, mid, target, value);
    else update(2 * ind + 2, 1 + mid, high, target, value);
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];  
}

signed main() {
    cin >> n >> q;
    a.resize(n);
    seg.resize(4 * n + 5);
    
    for(int i = 0; i < n; ++i) cin >> a[i];
    build(0, 0, n - 1);

    while(q--) {
        cin >> typ >> x >> y;
        if(typ == 1) update(0, 0, n - 1, x - 1, y);
        else cout << query(0, 0, n - 1, x - 1, y - 1) << "\n";
    }
}
