#include "bits/stdc++.h"
using namespace std;

signed main() {
    int n, step = 0, k; cin >> n >> k;
    vector<int> a(n);
    map<int, vector<int>> mp;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mp[a[i]].push_back(step);
    }

    int ans = INT_MAX, check = 1;
    while(check) {
        step += 1;
        check = 0;
        for(int i = 0; i < n; ++i) {
            if(a[i] == 0) continue;
            check = 1;
            a[i] /= 2;
            mp[a[i]].push_back(step);
            if((int) mp[a[i]].size() == k) {
                ans = min(ans, accumulate(mp[a[i]].begin(), mp[a[i]].end(), 0));
            }
        }
    }
    cout << ans;
}
