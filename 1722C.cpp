#include "bits/stdc++.h"
signed main() {
    int t; std::cin >> t;
    while (t--) {
        int n; std::cin >> n; 
        std::set<std::string> a, b, c, d;
        std::string s;
        for(int i = 0; i < n; ++i) { std::cin >> s; a.insert(s); d.insert(s); }
        for(int i = 0; i < n; ++i) { std::cin >> s; b.insert(s); d.insert(s); }
        for(int i = 0; i < n; ++i) { std::cin >> s; c.insert(s); d.insert(s); }
        
        int c1 = 0, c2 = 0, c3 = 0;
        for(auto& i : d) {
            int x = (a.find(i) != a.end());
            int y = (b.find(i) != b.end());
            int z = (c.find(i) != c.end());
            if(x + y + z == 3) continue;
            if(x == 1 && y == 1) {
                c1 += 1; c2 += 1;
                continue;
            }
            if(x == 1 && z == 1) {
                c1 += 1; c3 += 1;
                continue;
            }
            if(y == 1 && z == 1) {
                c2 += 1; c3 += 1;
                continue;
            }
            if(x == 1) c1 += 3;
            if(y == 1) c2 += 3;
            if(z == 1) c3 += 3;
        }

        std::cout << c1 << " " << c2 << " " << c3 << "\n";
    }
}
