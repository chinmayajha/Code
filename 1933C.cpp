#include "bits/stdc++.h"
using namespace std;
#define int long long

int pw(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

signed main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // for shuffle(..., ..., rng)
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        int a, b, l, temp; cin >> a >> b >> l;
        
        int x = 0, y = 0;
        temp = l;
        while(temp % a == 0) temp /= a, x++;
        temp = l;
        while(temp % b == 0) temp /= b, y++;

        set<int> k;
        for(int i = 0; i <= x; ++i) {
            for(int j = 0; j <= y; ++j) {
                // k = l / (a^i * b^j)
                temp = pw(a, i) * pw(b, j);
                if(l % temp == 0) k.insert(l / temp);
            }
        }

        cout << k.size() << "\n";
    }
}

