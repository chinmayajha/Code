#include "bits/stdc++.h"

bool valid(int k) {
    return (k > 0 && k < 3);
}
bool check(char a, char b, char c) {
    if(a == '.') a = 'x';
    else if(b == '.') b = 'x';
    else if(c == '.') c = 'x';
    
    return (a == b && b == c && a == 'x');
}
std::string solve() {
    std::vector<std::string> a(4);
    for(int i = 0; i < 4; ++i) std::cin >> a[i];
    for(int i = 0; i < 4; ++i) for(int j = 0; j < 4; ++j) { if(a[i][j] != '.') continue; 
        
        if(valid(j) && check(a[i][j - 1], a[i][j], a[i][j + 1])) return "YES";
        if(valid(i) && check(a[i - 1][j], a[i][j], a[i + 1][j])) return "YES";
        
        if(valid(i) && valid(j) && check(a[i - 1][j - 1], a[i][j], a[i + 1][j + 1])) return "YES";
        if(valid(i) && valid(j) && check(a[i - 1][j + 1], a[i][j], a[i + 1][j - 1])) return "YES";
    }
    return "NO";
}

signed main() {
    std::cout << solve();
}
