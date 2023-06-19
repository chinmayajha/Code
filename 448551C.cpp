#include "bits/stdc++.h"
using namespace std;

signed main() {
    int bullets, grenades, both; cin >> bullets >> grenades >> both;
    int n; cin >> n;

    vector<int> b, g; 
    for (int i = 0, x; i < n; ++i) {
        char c; cin >> x >> c;
        if(c == 'G') g.push_back(x);
        else b.push_back(x);
    }
    sort(b.begin(), b.end());
    sort(g.begin(), g.end());

    int cost = 0, ans = 0;

    // For BULLETS ONLY
    int bullets_taken = 0;
    bullets = min(bullets, (int) b.size());
    for(bullets_taken = 0; bullets_taken < bullets; ++bullets_taken) {
        cost += b[bullets_taken];
        ans++;
    }
    bullets_taken--;
    
    // for GRENADES ONLY
    int grenades_taken = 0;
    grenades = min(grenades, (int) g.size());
    for(grenades_taken = 0; grenades_taken < grenades; ++grenades_taken) {
        cost += g[grenades_taken];
        ans++;
    }
    grenades_taken--;
    
    // for BOTH
    multiset<int> left; // grenades and bullets left, using this for simplicity
    for(int i = bullets_taken + 1; i < (int) b.size(); ++i) left.insert(b[i]);
    for(int i = grenades_taken + 1; i < (int) g.size(); ++i) left.insert(g[i]);

    for(auto& i : left) {
        if(both == 0) break;
        both--;
        cost += i;
        ans++;
    }
    cout << ans << " " << cost;    
}


