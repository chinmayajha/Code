#include "bits/stdc++.h"
using namespace std;
#define int long long

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}

signed main() {
    int n; cin >> n;
    if(n < binpow(2, 31) && n >= binpow(-2, 31)) cout << "Yes";
    else cout << "No";
}