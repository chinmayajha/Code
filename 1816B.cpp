#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(2 * n);
        int x = 2 * n;
        a[2 * n - 1] = x--;
        a[0] = x--;

        // filling all blue boxes
        for(int i = 2; i < n; i += 2) a[i] = x--;
        for(int i = n + 1; i < 2 * n - 1; i += 2) a[i] = x--;
        // filling all red boxes
        for(int i = 1; i < n; i += 2) a[i] = (i % n) + 1;
        for(int i = n; i < 2 * n - 1; i += 2) a[i] = (i % n) + 1;

        for(int i = 0; i < n; ++i) cout << a[i] << " ";
        cout << "\n";
        for(int i = n; i < 2 * n; ++i) cout << a[i] << " ";
        cout << "\n";
    }
}
