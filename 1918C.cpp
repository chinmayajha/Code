#include "bits/stdc++.h"
using namespace std;

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); int T = 1;
    cin >> T;
    while (T--) {
        unsigned long long a, b, r; cin >> a >> b >> r;
        if(a > b) swap(a, b);

        unsigned long long x = 0;
        bool check = 1;
        for(int i = 63; i >= 0; --i) {
            bool ll = (a & (1LL << i)), rr = (b & (1LL << i));
            if(ll != rr) 
                if(check) check = 0;
                else 
                    if(!ll)
                        if(x + (1LL << i) <= r) 
                            x += (1LL << i), a ^= (1LL << i), b ^= (1LL << i);
        }

        cout << (b - a) <<"\n";
    
    }
}
