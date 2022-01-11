#include "bits/stdc++.h"
using namespace std;
#define sz(x) ((int)(x).size())
#define int long long

signed main() {    
    int n, m, q, cnt = 0;
    cin >> n >> m;
    vector<set<int>> a(n + 1);
    vector<int> weak(n + 1, 0);
    for(int i = 1; i <= m; ++i) {
        int x, y; cin >> x >> y;
        a[x].insert(y);
        a[y].insert(x);
    }
    for(int i = 1; i <= n; ++i) {
        a[i].insert(-1);
        weak[i] = (*a[i].rbegin() < i);
    }
    for(int i = 1; i <= n; ++i) cnt += weak[i];

    cin >> q;
    for(int ii = 1; ii <= q; ii++) {
        int temp; cin >> temp;
        if(temp == 3) cout << cnt << "\n";
        else if(temp == 1) {
            int x, y; cin >> x >> y;
            a[x].insert(y);
            a[y].insert(x);

            cnt -= weak[x]; cnt -= weak[y];
            weak[x] = (*a[x].rbegin()) < x;
            weak[y] = (*a[y].rbegin()) < y;
            cnt += weak[x]; cnt += weak[y];
        }
        else if(temp == 2) {
            int x, y; cin >> x >> y;
            a[x].erase(y);
            a[y].erase(x);

            cnt -= weak[x]; cnt -= weak[y];
            weak[x] = (*a[x].rbegin()) < x;
            weak[y] = (*a[y].rbegin()) < y;
            cnt += weak[x]; cnt += weak[y];
        }
    }
}