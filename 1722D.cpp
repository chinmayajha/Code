#include "bits/stdc++.h"
#define int long long
signed main() {
    int tt; std::cin >> tt;
    while (tt--) {
        int n, tempans = 0; std::cin >> n;
        std::string s; std::cin >> s;
        std::vector<int> answer;
        std::multiset<int, std::greater<int>> change;

        for(int i = 0; i < n; ++i) {
            if(s[i] == 'L') {
                change.insert((n - i - 1) - i);
                tempans += i;
            }
            if(s[i] == 'R') {
                tempans += (n - i - 1);
                change.insert(i - (n - i - 1));
            }
        }
        
        for(auto& i : change) {
            tempans += std::max(0ll, i);
            answer.push_back(tempans);
        }
        
        for(auto& e : answer) std::cout << e << " ";
        std::cout << "\n";
    }
}
