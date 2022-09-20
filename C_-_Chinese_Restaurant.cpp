#include "bits/stdc++.h"
int main() {
    int n, mx = 0; std::cin >> n;
    std::map<int, int> mp;
    for (int i = 0, temp; i < n; ++i) {
        std::cin >> temp;
        mp[((temp - i) + n) % n] += 1;
        mp[((temp - i - 1) + n) % n] += 1;
        mp[((temp - i + 1) + n) % n] += 1;
    }
    for(auto& i : mp) mx = std::max(mx, i.second);
    std::cout << mx;
}
