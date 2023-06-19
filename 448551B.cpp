#include "bits/stdc++.h"
using namespace std;

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    deque<int> d;

    bool last = 1;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        if(x == 0) last = 1 - last;
        if(last) d.push_back(x);
        else d.push_front(x);
    }

    if(last) {
        for(int i = 0; i < n; ++i) cout << d[i] << " ";
    } else for(int i = n - 1; i >= 0; --i) cout << d[i] << " ";
}
