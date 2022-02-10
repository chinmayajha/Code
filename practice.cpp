#include "bits/stdc++.h"
using namespace std;


signed main() {
    cin >> n >> e;
    parent.resize(n + 1); for(int i = 0; i < n; ++i) parent[i] = i + 1;
    siz.assign(n + 1, 1);
    for(int i = 0, x, y, z; i < e; ++i) {
        cin >> x >> y >> z;
        edges.push_back({z, x, y});
    }
    sort(edges.begin(), edges.end());
    for(auto& i : edges) {
        i[1] = findpar(i[1]);
        i[2] = findpar(i[2]);
        if(i[1] == i[2]) continue;
        cost += i[0];
        if(siz[i[2]] > siz[i[1]]) swap(i[2], i[1]);
        siz[i[1]] += siz[i[2]];
        parent[i[2]] = i[1];
    }
    cout << cost;
}