#include "bits/stdc++.h"
#define int long long

int getsum(int n) {
    int sum = 0;
    while(n > 0) sum += (n % 10), n /= 10;
    return sum;
}

signed main() {
    int n, m, s;
    std::cin >> n >> m >> s;
    int sum = getsum(n);
    while(sum != s) {
        n++;
        sum = getsum(n);
    }

    std::cout << "0\n" << n;
}