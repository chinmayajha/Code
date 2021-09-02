
#include "bits/stdc++.h"
#pragma GCC optimize "trapv"
using i64 = long long int;
using namespace std;
int nxt(){int x; cin >> x; return x;}
#define sz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()
#define inarr(a,n) for(int i = 0; i < n; ++i) cin >> a[i];
//
vector<i64> a[202020];
vector<bool> vis(202020);
vector<i64> cost(202020);
i64 n, q, x, y, cnt;
i64 dfs(i64 node) {
    vis[node] = 1;
    i64 curcost = cost[node];
    for(auto i : a[node]) {
        if(!vis[i]) curcost = min(curcost, dfs(i)); 
    }
    return curcost;
}
void find_connected_components() {
    for(i64 i = 0; i < n; ++i) {
        if(!vis[i]) {
            vis[i] = 1;
            cnt += dfs(i);
        }
    }
}
void solve(){
	cin >> n >> q;
    inarr(cost, n);
    while(q--) {
        cin >> x >> y;
        x--; y--;
        a[x].emplace_back(y);
        a[y].emplace_back(x);
    }
    find_connected_components();
    cout << cnt;
}

int main(){
    cin.tie(nullptr);cout.tie(nullptr);ios::sync_with_stdio(false);
    int testt = 1;
    // cin >> testt;
    for (int i = 1; i <= testt; ++i){
        // cout << "Case #" << i << ": ";
        solve();
    }
}

