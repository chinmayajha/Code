#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
#include "bits/stdc++.h"
#define int long long

using namespace std;
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n, cnt = 0; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        ordered_set<pair<int, int>> b;
        for(int i = n - 1; i >= 0; --i) {
            cnt += (b.order_of_key({a[i], 1000000000000000005ll}));
            b.insert({a[i], i});
        }
        cout << cnt << "\n";
    }
}
