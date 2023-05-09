#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int t = 1;
    cin >> t;
    while (t--) {
        int n, e; cin >> n >> e;
        int x, y;
        vector<int> freq(n + 1, 0);
        vector<vector<int>> a(n + 1);
        while(e--) {
            cin >> x >> y;
            freq[x] += 1;
            freq[y] += 1;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        
        int centroid = -1, not_leaf = -1;
        for(int i = 1; i <= n; ++i) {
            if(freq[i] == 1) continue;
            bool found = 1;
            for(int j = 1; j < a[i].size(); ++j) {
                if(freq[a[i][j]] != freq[a[i][j - 1]]) {
                    found = 0;
                    break;
                }
            }
            if(!found) continue; 
            centroid = i;
            not_leaf = a[i].back();
            break;
        }
        
        cout << freq[centroid] << " " << freq[not_leaf] - 1 << "\n";
    }
}
