#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n, k, ans = 0; cin >> n >> k;
        string s; cin >> s;

        map<char, int> a;
        for(auto& i : s) a[i] += 1;
        for(auto& i : a) {
            char c = i.first; 
            if(c >= 65 && c <= 90) {
                int temp = min(a[c + 32], i.second);
                i.second -= temp;
                a[c + 32] -= temp;
                ans += temp;
            }
        }
        for(auto& i : a) {
            int temp = min(k, i.second / 2);
            ans += temp;
            k -= temp;
            if(k == 0) break;
        }
        cout << ans << "\n";
    }
}
