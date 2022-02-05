#include "bits/stdc++.h"
using namespace std;
#define int long long
// O(N * Q) solution, should not pass many cases

signed main() {
    int n, m; cin >> n >> m;
    vector<int> a(n), ans(m);
    vector<pair<<int, int>> b(m);
    sort(b.begin(), b.end());
    set<int> s;
    for(int i = 0; i < n; ++i) s.insert(i);

    for(auto& [k, i] : b) {
        set<int> t = s;
        for(auto& element : s) if(a[element] <= k) t.erase(a[element]);
        s = t;
    }

}
