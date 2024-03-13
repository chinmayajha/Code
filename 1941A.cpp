#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef
tree<
  int,
  null_type,
  less_equal<int>,
  rb_tree_tag,
  tree_order_statistics_node_update>
ordered_set;


signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n, m, k; cin >> n >> m >> k;
        ordered_set a; ordered_set b;
        for(int i = 0, x; i < n; ++i) {
            cin >> x; a.insert(x);
        }
        for(int i = 0, x; i < m; ++i) {
            cin >> x; b.insert(x);
        }

        int ans = 0;
        for(auto& i : a) {
            ans += b.order_of_key(k - i + 1);
        }

        cout << ans << "\n";
    }
}

