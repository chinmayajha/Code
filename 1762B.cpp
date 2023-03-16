#include "bits/stdc++.h"
using namespace std;
#define int long long
 
int next_power_of_two(int b) {
    int x = 1;
    while(1ll << x <= b) x += 1;
    return (1ll << x);
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        cout << n << "\n";
        for (int i = 0, x; i < n; ++i) {
            cin >> x;
            cout << i + 1 << " " << next_power_of_two(x) - x << "\n";
        }
    }
}