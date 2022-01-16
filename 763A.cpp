#include "bits/stdc++.h"

bool dfs(int& node, std::vector<std::vector<int>>& a, std::vector<int>& vis, std::vector<int>& colors, int& parent_color) {
    vis[node] = 1;
    if(colors[node] != parent_color) return 0;
    for(auto& i : a[node]) {
        if(!vis[i]) if(dfs(i, a, vis, colors, parent_color) == 0) return 0;
    }
    return 1;
}
signed main() {
    int n; std::cin >> n;
    std::vector<std::vector<int>> a(n + 1);
    int c1 = -1, c2 = -1;
    for(int i = 1, x, y; i <= n - 1; ++i) {
        std::cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    std::vector<int> colors(n + 1), vis1(n + 1, 0), vis2(n + 1, 0);
    for(int i = 1; i <= n; ++i) std::cin >> colors[i];
    // choose any edge similar to c1 --- c2 

    for(int i = 1; i <= n; ++i) for(auto& j : a[i]) {
        if(colors[i] != colors[j]) {
            c1 = i, c2 = j;
            break;
        }
    }
    if(c1 == -1) {std::cout << "YES\n1"; return 0;}
    vis1[c1] = 1; 
    bool chk1 = 1, chk2 = 1;
    for(auto& i : a[c1]) {
        if(dfs(i, a, vis1, colors, colors[i]) == 0) chk1 = 0;
    }
    vis2[c2] = 1;
    for(auto& i : a[c2]) {
        if(dfs(i, a, vis2, colors, colors[i]) == 0) chk2 = 0;
    }

    if(chk1) std::cout << "YES\n" << c1;
    else if(chk2) std::cout << "YES\n" << c2;
    else std::cout << "NO\n";
}
