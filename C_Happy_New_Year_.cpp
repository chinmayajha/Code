#include "bits/stdc++.h"
using namespace std;
#define int long long

string solve(int len, int k, int n) {
    if(len == 0) return "";
    if(k > n / 2) return ("2" + solve(len - 1, (k - 1) % (n / 2) + 1, n / 2));
    else return ("0" + solve(len - 1, k, n / 2));
}

signed main() {
    int n, len = 0; cin >> n;
    int temp = n;
    while(temp > 0) {
        temp /= 2;
        len++;
    }
    int k = (n + 1) % (1ll << (len - 1));
    if(k == 0) while(len--) cout << 2;
    else {
        cout << "2" << solve(len - 1, k, (1ll << (len - 1)));
    }   
}
