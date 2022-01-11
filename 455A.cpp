#include "bits/stdc++.h"
using namespace std;
#define int long long

vector<int> a(1000005, 0);
signed main() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        a[x] += x;
    }
    for(int i = 2; i < 1000001; ++i) {
        a[i] = max(a[i - 1], a[i - 2] + a[i]);
    }
    cout << a[1000000];
}
