#include "bits/stdc++.h"
using namespace std;
#define int long long

int n, ans = LONG_LONG_MAX;
vector<pair<int, int>> a;

int dist(int x1, int y1, int x2, int y2) {
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}
signed main() {                                                                      
    cin >> n; a.resize(n);
    for(int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end(), [&](pair<int, int>& p1, pair<int, int>& p2){return p1.first + p1.second < p2.first + p2.second;});
    for(int i = 1; i < n; ++i) ans = min(ans, dist(a[i - 1].first, a[i - 1].second, a[i].first, a[i].second));
    cout << ans;
//     for(int i = 0; i < n; ++i) for(int j = i + 1; j < n; ++j) ans = min(ans, dist(a[j].first, a[j].second, a[i].first, a[i].second));
//     cerr << ans;   
}
