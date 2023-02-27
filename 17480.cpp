#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        int sum = ((n / 2) * (n / 2 + 1)) + ((n % 2) * (n / 2 + 1));
        int i = sqrt(sum) + 1;
        cout << i - 1 + (sum == i * i) << "\n";
    }
}
