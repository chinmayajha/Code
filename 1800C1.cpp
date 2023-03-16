#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    int t = 1; cin >> t;
    while (t--) {
        int n, ans = 0; cin >> n;
        priority_queue<int> pq;
        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            if(x != 0) pq.push(x);
            else {
                if(pq.size() == 0) continue;
                ans += pq.top();
                pq.pop();
            }
        }
        cout << ans << "\n";
    }
}
