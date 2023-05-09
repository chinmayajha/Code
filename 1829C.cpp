#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        int left, right, both;
        left = right = both = INT_MAX;

        int cost; string s;
        while(n--) {
            cin >> cost >> s;
            if(s == "11") both = min(both, cost);
            else if(s[0] == '1') left = min(left, cost);
            else if(s[1] == '1') right = min(right, cost);
        }

        if(both == INT_MAX && (left == INT_MAX || right == INT_MAX)) cout << -1;
        else cout << min(both, left + right);
        cout << "\n";
    }
}
