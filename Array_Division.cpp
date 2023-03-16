#include "bits/stdc++.h"
using namespace std;
#define int long long

bool candivide(vector<int>& a, int mid, int k) {
    int tsum = 0, cnt = 1;
    for(auto& i : a) {
        if(i > mid) return 0;
        if(tsum + i > mid) tsum = i, cnt += 1;
        else tsum += i;
        if(cnt > k) return 0;
    }
    return (cnt <= k);
}

signed main() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    int left = *max_element(a.begin(), a.end()), right = accumulate(a.begin(), a.end(), 0ll), count = 60;
    while(count) {
        count--;
        int mid = (left + right) / 2;

        // FFFFTTTTT
        if(candivide(a, mid, k)) right = mid;
        else left = mid + 1;
    }

    cout << left;
}
