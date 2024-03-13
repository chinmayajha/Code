#include "bits/stdc++.h"
using namespace std;
#define int long long

bool search(vector<int>& a, int e) {
    int l = 0, r = a.size() - 1;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(a[mid] == e) return 1;
        if(a[mid] > e) r = mid - 1;
        else l = mid + 1;
    }
    return 0;
}

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<vector<int>> a;
        set<int> total;
        // minimum number of elements with minimum frequency in which array? answer is union of all other arrays
        for(int i = 0, k; i < n; ++i) {
            cin >> k;
            vector<int> temp(k);
            for(auto& i : temp) cin >> i, total.insert(i);
            sort(temp.begin(), temp.end());
            a.push_back(temp);
        }

        int ans = 0;
        for(auto& exclude : total) {
            set<int> result;
            for(auto& i : a) {
                if(!search(i, exclude)) {
                    for(auto& j : i) result.insert(j);
                    ans = max(ans, (int) result.size());
                }
            }
        }

        cout << ans << "\n";
    }
}