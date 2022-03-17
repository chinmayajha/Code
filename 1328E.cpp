#include "bits/stdc++.h"
using namespace std;

vector<vector<int>> a;
vector<int> tin, tout, parent;
int n, qq, timer;
string ans[2] = {"NO\n", "YES\n"};

void dfs(int node, int par) {
    parent[node] = par;
    tin[node] = ++timer;
    for(auto& i : a[node]) if(i != par) dfs(i, node);
    tout[node] = ++timer;
}

bool not_ancestor(int x, int y) {
    return (tin[x] > tin[y] || tout[x] < tout[y]);
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> qq; parent.assign(n + 1, 0);
    tin.assign(n + 1, 0); tout.assign(n + 1, 0);
    a.resize(n + 1);
    for(int i = 0, x, y; i < n - 1; i++) {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1, 1); 
    while(qq--) {
        int x; cin >> x;
        vector<int> b;
        for(int i = 1, y; i <= x; ++i) {
            cin >> y; b.push_back(parent[y]);
        }
        
        sort(b.begin(), b.end(), [&](int p, int q){
            if(tin[p] == tin[q]) return tout[p] < tout[q];
            return tin[p] < tin[q];
        });

        int check = 1;
        for(int i = 0; i < -1 + (int) b.size(); ++i) {
            if(not_ancestor(b[i], b[i + 1])) {check = 0; break;}
        }
        cout << ans[check];
    }
}