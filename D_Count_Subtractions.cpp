#include "bits/stdc++.h"
using namespace std;
#define int long long

signed main() {
    int n, m, cnt = 0; cin >> n >> m;
    if(n < m) swap(n, m);
    while(m != 0) {
        cnt += n / m;
        n = n % m;
        swap(n, m);
    }
    cout << --cnt;
}