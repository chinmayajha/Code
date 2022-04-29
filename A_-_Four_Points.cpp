#include "bits/stdc++.h"
using namespace std;

signed main() {
    pair<int, int> a[3];
    for(int i = 0; i < 3; ++i) cin >> a[i].first >> a[i].second;
    sort(a, a + 3);
    if(a[0].first == a[1].first) {
        if(a[0].second == a[2].second) cout << a[2].first << ' ' <<  a[1].second;
        else cout << a[2].first << ' ' << a[0].second;
    } else if(a[1].first == a[2].first) {
        if(a[1].second == a[0].second) cout << a[0].first << ' ' << a[2].second;
        else cout << a[0].first << ' ' << a[1].second;
    }
}
