#include "bits/stdc++.h"
using namespace std;
#define int long long

int n, m, q;
vector<int> rankk(1000010), parent(1000010);

vector<vector<int>> a, b;
int findpar(int x) {
    if(parent[x] == x) return x;
    return parent[x] = findpar(parent[x]);
}

void unite(int x, int y) {
    x = findpar(x);
    y = findpar(y);
    if(x == y) return;
    if(rankk[x] < rankk[y]) swap(x, y);
    if(rankk[x] == rankk[y]) rankk[x]++;
    parent[y] = x;
}

signed main() {
    cin >> n >> m >> q;
    for(int i = 1; i <= n; ++i) parent[i] = i;
    for(int i = 1; i <= n; ++i) rankk[i] = 0;
    
    for(int i = 1, x, y, z; i <= m; ++i) {
        cin >> x >> y >> z;
        a.push_back({z, x, y});
    }
    for(int i = 1, x, y, z; i <= q; ++i) {
        cin >> x >> y >> z;
        b.push_back({z, x, y, i - 1});
    }
    a.push_back({(int) 1e9, n, n});
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<bool> ans(q + 1, 0);
    int i = 0;

    for(auto& k : a) {
        int w = k[0], x = k[1], y = k[2];
        while(i < q && b[i][0] < w) {
            if(findpar(b[i][1]) != findpar(b[i][2])) ans[b[i][3]] = 1;
            i++;
        } 
        if(findpar(x) != findpar(y)) unite(x, y);
    }

    for(int j = 0; j < q; ++j) cout << (ans[j] ? "Yes\n" : "No\n");
    return 0;
}