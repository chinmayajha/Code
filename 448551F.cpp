#include "bits/stdc++.h"
using namespace std;

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int q, n = 0; cin >> q;
    
    vector<vector<int>> mp(500050);
    while(q--) {
        int typ, x, y;
        cin >> typ;
        if(typ == 2) {
            cin >> x >> y;
            if(x == y) continue;
            vector<int> store = mp[x];
            mp[x].clear();
            for(auto& i : store) mp[y].push_back(i);
        } else {
            cin >> x;
            mp[x].push_back(n);
            n++;
        }
    }
    vector<int> a(n, 0);
    for(int i = 0; i < (int) mp.size(); ++i) {
        for(auto& j : mp[i]) {
            a[j] = i;
        }
    }
    
    for(auto& i : a) {cout << i << " ";} cout << "\n";
}
