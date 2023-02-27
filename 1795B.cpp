#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> l(n), r(n);
        for (int i = 0; i < n; ++i) cin >> l[i] >> r[i];
        sort(l.begin(), l.end());

        set<int> possibles;
        for(auto& i : r) {
            if(binary_search(l.begin(), l.end(), i)) possibles.insert(i);
        }
        cout << (possibles.count(k) ? "YES" : "NO") << "\n";
    }
}
