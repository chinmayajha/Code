#include "bits/stdc++.h"
using namespace std;
#define int long long
int n, m, x, y, z;
set<int> s;
vector<int> ans;

signed main() {
    cin >> n >> m;
    ans.assign(n + 1, 0);
    s.insert(-1);
    for(int i = 1; i <= n; ++i) s.insert(i);
	s.insert((int) 3e5 + 10);
    while(m--) {
        cin >> x >> y >> z;
        x = *(s.lower_bound(x));
        while(x <= y) {
            if(x != z) ans[x] = z;
            s.erase(x);
            x = *(s.lower_bound(x));
        } 
        s.insert(z);
    }
    for(int i = 1; i <= n; ++i) cout << ans[i] << " ";
}
