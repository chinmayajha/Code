#include "bits/stdc++.h"
using namespace std;
#define int long long

int n, q, parent[100001], rankk[100001];

int findpar(int x) {
    if(parent[x] == x) return x;
    return parent[x] = findpar(parent[x]);
}

void unite(int x, int y) {
    x = findpar(x);
    y = findpar(y);

    if(rankk[x] < rankk[y]) swap(x, y);
    parent[y] = x;
    cout << x << "\n";
}

signed main() {
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) {
        cin >> rankk[i];
        parent[i] = i;
    }
    for(int i = 0, x, y; i < q; ++i) {
        cin >> x >> y;
        if(findpar(x) == findpar(y)) {
            cout << "-1\n";
            continue;
        }
        unite(x, y);
    }
}
