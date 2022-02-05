#include "bits/stdc++.h"
using namespace std;
#define int long long

const int w = 1000050;
int n, m;
char c;
vector<int> parent((int) 1e7), siz((int) 1e7, 1);

int findpar(int x) {
    if(x == parent[x]) return x;
    return parent[x] = findpar(parent[x]);
}

void unite(int x, int y) {
    x = findpar(x);
    y = findpar(y);

    if(x == y) return;
    if(siz[y] > siz[x]) swap(x, y);

    parent[y] = x;
    siz[x] += siz[y];
}

signed main() {
    cin >> n >> m;
    for(int i = 0; i < (int) 1e7; ++i) parent[i] = i;

    int x, y;
    while(m--) {
        cin >> c; cin >> x >> y;
        if(c == 'A') {
            unite(x, y + w);
            unite(x + w, y);
        } else if(c == 'R') {
            unite(x, y);
            unite(x + w, y + w);
        } else {
            int p, q, s;
            p = findpar(x);
            q = findpar(y);
            // r = findpar(x + w);
            s = findpar(y + w);

            if(p == q && p == s) cout << "?";
            else if (p == q) cout << "R";
            else if (p == s) cout << "A";
            else cout << "?";
            cout << "\n";
        }
    }
}