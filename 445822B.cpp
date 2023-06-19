#include "bits/stdc++.h"
using namespace std;
#define int long long

vector<int> primes;

bool isPrime(int n) {
   if (n == 2) return 1;
   for (int i = 2; i * i <= n; i++) if (n % i == 0) return 0;
   return 1;
}
int process(int n) {
    for (int i = n - 1; i >= 1; i--) {
        if (isPrime(i)) primes.push_back(i);
    }
    return 0;
}

signed main() {
    int n; cin >> n;
    process(n);
    reverse(primes.begin(), primes.end());
    for(int pos = primes.size() - 1; pos >= 0; --pos) {
        for(int i = 1; i < pos; ++i) {
            if(primes[i] + primes[i - 1] + 1 == primes[pos]) {
                cout << primes[pos];
                return 0;
            }
        }
    }
    cout << 0;
}

