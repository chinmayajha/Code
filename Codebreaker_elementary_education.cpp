#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m), c;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    sort(b.begin(), b.end());
    for(auto& i : a) if(binary_search(b.begin(), b.end(), i)) c.push_back(i);
    for(int i = (int)(c.size()) - 1; i >= 0; --i) cout << c[i] << " ";
}
