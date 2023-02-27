#include "bits/stdc++.h"
int main() {
    int t = 1; std::cin >> t;
    while (t--) {
        int n, qcnt = 0; std::cin >> n;
        std::string s; std::cin >> s;
        
        if(s[0] != 'A') for(auto& i : s) {
            if(i == 'Q') qcnt += 1;
            else qcnt = std::max(0, qcnt - 1);
        }
        std::cout << ((s[0] != 'A') && qcnt <= 0 ? "Yes\n" : "No\n");
    }
}
