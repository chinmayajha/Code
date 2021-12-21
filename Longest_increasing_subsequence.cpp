// https://codebreaker.xyz/problem/lis_easy
#include "bits/stdc++.h"
using namespace std;

int main() {
    int n, res = 1; cin >> n;
    vector<int> a(n), ans(n, 1);
    for (int i = 0; i < n; ++i) { cin >> a[i]; }

    for (int i = 0; i < n; ++i) {
        int cnt = 1, cur = a[i];
        for (int j = 0; j < i; ++j) {
            if (a[j] < a[i]) {
                ans[i] = max(ans[i], ans[j] + 1);
            }
        }
    }

    cout << *max_element(ans.begin(), ans.end());
}