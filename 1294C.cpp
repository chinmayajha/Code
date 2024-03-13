#include "bits/stdc++.h"
using namespace std;
#define int long long

int first_prime_factor(int n, int diff) {
    for(int i = diff + 1; i * i <= n; i++) {
        if(n % i == 0) return i;
    }
    return -1;
}

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int n; cin >> n;
        
        int first = first_prime_factor(n, 1);
        int second = first_prime_factor(n / first, first);

        if(second == -1) cout << "NO\n";
        else {
            int third = (n / (first * second));
            if(third == first || third == second || third == 1) cout << "NO\n";
            else {
                cout << "YES\n";
                cout << first << " " << second << " " << third << "\n"; 
            }
        }
    }
}

