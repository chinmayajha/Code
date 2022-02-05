#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, sum;

signed main() {
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    for(int i = 1; i < n; ++i) sum += (a[i] + a[0]);
    cout << sum;
}