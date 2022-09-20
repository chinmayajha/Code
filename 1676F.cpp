#include "bits/stdc++.h"
using namespace std;

signed main() {
    int t = 1; cin >> t; while (t--) {
        int n, k; cin >> n >> k;
        map<int, int> a;
        for (int i = 0, temp; i < n; ++i) {
            cin >> temp;
            a[temp] += 1;
        }
        
        vector<int> ans;
        for(auto& i : a) if(i.second >= k) ans.push_back(i.first);
        if((int) ans.size() == 0) {
            cout << "-1\n";
            continue;
        }
        sort(ans.begin(), ans.end());

        int l = ans[0], r = ans[0], curl = ans[0], curr = ans[0];
        for(int i = 1; i < (int) ans.size(); ++i) {
            if(ans[i] != ans[i - 1] + 1) curl = ans[i];
            curr = ans[i];
            if(curr - curl > r - l) l = curl, r = curr;
        }

        cout << l << " " << r << endl;
    }
}
