#include "bits/stdc++.h"
using namespace std;

map<int, int> primefactors(int n, int d = 2) {
    map<int, int> factors;
    while (n > 1) {
        while (n % d == 0) factors[d] += 1, n /= d;
        d += 1;
    }
    return factors;
}

int nearest_power_of_two(int n) {
    int result = 1;
    while (result < n) result <<= 1;
    return result;
}

int log_2(int n) {
    int result = 0;
    while (n >>= 1) ++result;
    return result;
}

signed main() {
    int n, mx = 0, ans = 1, steps = 0; cin >> n;

    map<int, int> factors = primefactors(n);
    for(auto& i : factors) mx = max(mx, i.second);
    for(auto& i : factors) ans *= i.first;
    mx = nearest_power_of_two(mx);
    for(auto& i : factors) {
        if(i.second != mx) {
            steps += 1;
            break;
        }
    }
    steps += log_2(mx);
    cout << ans << " " << steps;
}
