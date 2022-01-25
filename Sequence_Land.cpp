#include "bits/stdc++.h"

std::vector<std::vector<int>> a(1000000);
std::vector<int> parent(1000000), siz(1000000);
int n, k;

int findpar(int x) {
    if(parent[x] == x) return x;
    return parent[x] = findpar(parent[x]);
}

void unite(int x, int y) {
    x = findpar(x);
    y = findpar(y);
    if(x == y) return;

    if(siz[x] < siz[y]) std::swap(x, y);
    parent[y] = x;
    siz[x] += siz[y];
}

bool connections_check(int i, int j) {
    int x = (int) a[i].size(), y = (int) a[j].size();
    int ind1 = 0, ind2 = 0, cnt = 0;

    while(ind1 < x && ind2 < y) {
        if(a[i][ind1] == a[j][ind2]) {
            cnt++; ind1++; ind2++;
            if(cnt >= k) return 1;
        } 
        else if(a[i][ind1] > a[j][ind2]) ind2++;
        else if(a[i][ind1] < a[j][ind2]) ind1++;
    }
    return 0;
}

signed main() {
    std::cin >> n >> k;
    for(int i = 0, x, y; i < n; ++i) {
        parent[i] = i, siz[i] = 1;
        std::cin >> x;
        while(x--) std::cin >> y, a[i].push_back(y);
        std::sort(a[i].begin(), a[i].end());
    }

    for(int i = 0; i < n; ++i) for(int j = i + 1; j < n; ++j) {
        if((findpar(i) != findpar(j)) && connections_check(i, j)) unite(i, j);
    }
    std::cout << siz[findpar(0)];
}
