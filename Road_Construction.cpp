#include "bits/stdc++.h"
using namespace std;
#define int long long

int n, e, components, largest;
vector<vector<int>> a;
vector<int> parent, siz;

int findpar(int x) {
    if(parent[x] == x) return x;
    return parent[x] = findpar(parent[x]);
}

void unite(int x, int y) {
    x = findpar(x);
    y = findpar(y);
    if(x == y) return;
    components--;
    if(siz[y] > siz[x]) swap(x, y);
    siz[x] += siz[y];
    parent[y] = x;
    largest = max(largest, siz[x]);
}

signed main() {
	cin >> n >> e; components = n; largest = 1;
    a.resize(n + 1);
    parent.resize(n + 1); siz.assign(n + 1, 1);
    for(int i = 0; i <= n; ++i) parent[i] = i;
	for(int i = 0, x, y; i < e; ++i) {
		cin >> x >> y;
        unite(x, y);
        cout << components << " " << largest << "\n";
	}
}