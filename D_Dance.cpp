#include "bits/stdc++.h"

std::vector<std::pair<int, int>> x;
std::vector<bool> vis(100, 0);

int calc(int n, std::vector<std::vector<int>>& a) {
    if((int) x.size() == n / 2) {
        int ans = 0;
        for(auto& i : x) ans ^= a[i.first][i.second];
        return ans;  
    }
    int temp = -1;
    for(int i = 1; i <= n; ++i) {
        if(!vis[i]) {
            temp = i;
            vis[temp] = 1;
            break;
        }
    }

    int cnt = 0;
    for(int i = 1; i <= n; ++i) {
        if(!vis[i]) {
            x.push_back(std::make_pair(temp, i));
            vis[i] = 1;
            cnt = std::max(cnt, calc(n, a));
            x.pop_back();
            vis[i] = 0;
        }
    }
    vis[temp] = 0;
    return cnt;
}

signed main() {
    int n; std::cin >> n;
    n *= 2;
    std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1, 0));
    for(int i = 1; i <= n - 1; ++i) for(int j = i + 1; j <= n; ++j) std::cin >> a[i][j];
    std::cout << calc(n, a);
}