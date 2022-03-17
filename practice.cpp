#include "bits/stdc++.h"
using namespace std;
#define int long long

int n;
vector<int> parent, siz;

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

void preprocess() {
    siz.assign(n + 1, 1); parent.resize(n + 1);
    for(int i = 0; i <= n; ++i) parent[i] = i;
}

signed main() {
    cin >> n;
    preprocess();
    // ieput + function_call
    cout << findpar(1) << " " << findpar(2) << "\n";
    unite(1, 2);
    cout << findpar(1) << " " << findpar(2) << "\n";
}