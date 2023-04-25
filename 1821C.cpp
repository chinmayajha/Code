#include "bits/stdc++.h"
using namespace std;
#define int long long

int max_power_of_2(int x) {
    int cnt = 0;
    while(x > 0) x /= 2, cnt += 1;
    return cnt;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.size();
        int final_ans = INT_MAX;
        for(char ch = 'a'; ch <= 'z'; ch++) {
            int last = -1, mx = 0;
            for(int i = 0; i < n; ++i) {
                if(s[i] == ch) {
                    mx = max(mx, i - last - 1);
                    last = i;
                }
            }
            mx = max(mx, (n - last - 1));
            final_ans = min(final_ans, max_power_of_2(mx));
        }
        cout << final_ans << "\n";
    }
}
