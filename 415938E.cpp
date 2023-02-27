#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    if(accumulate(a.begin(), a.end(), 0ll) <= k) {
        cout << n;
        exit(0);
    }

    int i = 0, j = 0, l = 0, sum = 0;
    while(i < n && j < n) {
        while(j < n && sum <= k) {
            sum += a[j];
            j++;
        }
        l = max(j - i - 1, l);
        cerr << j << " " << i << endl;
        while(i < n && sum > k) {
            sum -= a[i];
            i++;
        }
    }
    cout << l;
}
