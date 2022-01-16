#include "bits/stdc++.h"

signed main() {
    int n; std::cin >> n; std::map<int, int> degree; 
    for(int i = 1, x; i <= 2 * (n - 1); ++i) std::cin >> x, degree[x]++;
    for(auto& i : degree) if(i.second == 2) { std::cout << "NO"; return 0; }
    std::cout << "YES";
}
