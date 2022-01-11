#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    int t = 1; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        
        map<char, int> a;
        for(auto& i : s) a[i]++;
        int pairs = 0, left = 0;
        for(auto& i : a) {
            pairs += (i.second / 2);
            left += (i.second % 2);
        }
        int groups = pairs / k; // for each color, maximize the number of chars
        int remaining = pairs % k;

        int ans1 = groups * 2, ans2 = groups * 2;
        if(left >= k - remaining) ans1 += 1;
        if(remaining * 2 + left >= k) ans2 += 1;

        cout << max(ans1, ans2) << "\n";
    }
}
