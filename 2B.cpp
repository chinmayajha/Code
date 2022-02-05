#include "bits/stdc++.h"
#define int long long

std::vector<std::vector<int>> a, dp2, dp5;
int n;

int getfact(int x, int y) {
    int cnt = 0;
    while(x > 0 && x % y == 0) cnt++, x /= y;
    return cnt;
}

signed main() {
    std::cin >> n;
    a.assign(n + 1, std::vector<int>(n + 1, 0));
    dp2.assign(n + 1, std::vector<int>(n + 1, 0));
    dp5.assign(n + 1, std::vector<int>(n + 1, 0));

    bool check = 1;
    int zeroi = -1, zeroj = -1;
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) {
        std::cin >> a[i][j];
        if(a[i][j] == 0) {
            a[i][j] = 10;
            if(check) zeroi = i, zeroj = j;
            check = 0;
        }
        dp2[i][j] = getfact(a[i][j], 2);
        dp5[i][j] = getfact(a[i][j], 5);
    }

    for(int i = 1; i <= n; ++i) {
        dp2[1][i] += dp2[1][i - 1];
        dp2[i][1] += dp2[i - 1][1];
        
        dp5[1][i] += dp5[1][i - 1];
        dp5[i][1] += dp5[i - 1][1];
    }
    for(int i = 2; i <= n; ++i) for(int j = 2; j <= n; ++j) {
        dp2[i][j] += std::min(dp2[i - 1][j], dp2[i][j - 1]);
        dp5[i][j] += std::min(dp5[i - 1][j], dp5[i][j - 1]);
    }
    
    if(dp2[n][n] > dp5[n][n]) std::swap(dp2, dp5);

    int i = n, j = n;
    std::string s = "";
    while(i >= 1 || j >= 1) {
        if(i == 1 && j == 1) break;
        if(i == 1) {
            s.push_back('R');
            j--;
        } else if(j == 1) {
            s.push_back('D'); 
            i--;
        } else if(dp2[i - 1][j] > dp2[i][j - 1]) {
            s.push_back('R');
            j--;;
        } else {
            s.push_back('D');
            i--;
        }
    }

    std::reverse(s.begin(), s.end());
    if(dp2[n][n] < 1 || check) {
        std::cout << dp2[n][n] << "\n";
        std::cout << s;
    } else {
        std::cout << "1\n";
        for(i = 1; i < zeroi; ++i) std::cout << "D";
        for(i = 1; i < zeroj; ++i) std::cout << "R";
        for(i = zeroi; i < n; ++i) std::cout << "D";
        for(i = zeroj; i < n; ++i) std::cout << "R";
    }

    return 0;
}
