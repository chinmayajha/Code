// https://cses.fi/problemset/task/1643
#include "bits/stdc++.h"
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);

    int n, res = 2; cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) { cin >> a[i]; }
    sort(a.begin(), a.end());

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {

            int cur = a[j], diff = a[j] - a[i], cnt = 2;

            for (int k = 0; k < n; ++k) {
                if (abs(a[k] - a[j]) == diff) { cur += diff, cnt++; }
            }

            res = max(res, cnt);
        }
    }

    cout << res;
}