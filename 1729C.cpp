#include "bits/stdc++.h"
using namespace std;

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.size();

        // Reversing in this case so that first <= last always
        bool reversed = s[0] > s[n - 1];
        if(reversed) reverse(s.begin(), s.end());

        vector<set<int>> a(52);
        for(int i = 0; i < n; ++i) a[s[i] - 'a'].insert(i + 1);
        
        // It is best to take all indices of each char to maximize jumps, and 0 cost
        vector<int> ans;
        int first = s[0] - 'a', last = s[n - 1] - 'a', cost = 0;

        for(int i = first; i <= last; ++i) {
            if(!a[i].size()) continue;
            for(auto& j : a[i]) ans.push_back(j);
        }
        
        for(int i = 1; i < (int) ans.size(); ++i) {
            cost += abs(s[ans[i] - 1] - s[ans[i - 1] - 1]);
        }

        cout << cost << " " << ans.size() << "\n";
        if(reversed) {
            reverse(ans.begin(), ans.end());
            for(auto& i : ans) cout << n - i + 1 << " ";
        }
        else for(auto& i : ans) cout << i << " ";

        cout << "\n";
    }
}
