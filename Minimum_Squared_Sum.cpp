#include "bits/stdc++.h"
using namespace std;
#define int long long
// #include "debug.hpp"

int sum(vector<int>& a, int x) {
    int res = 0;
    for (auto ai : a) {
        res += min((x - ai) * (x - ai), (x + 1 - ai) * (x + 1 - ai));
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());

        int X = a[0], Y = a[1];
        for (int i = 2; i < n; i++) {
            int s1 = (X - a[i]) * (X - a[i]);
            int s2 = (Y - a[i]) * (Y - a[i]);
            if (s1 < s2) {
                X = a[i];
            } else {
                Y = a[i];
            }
        }

        int sum = 0;
        for (auto ai : a) {
            sum += min((X - ai) * (X - ai), (Y - ai) * (Y - ai));
        }

        cout << sum << endl;
    }
}
